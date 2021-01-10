#include "PracticeEngine.h"
#include "Camera.h"

void Camera::Update()
{
	Move();
	ShakeUpdate();
}

void Camera::Render()
{
	vpBuffer->SetVSBuffer(1);
}

void Camera::Move()
{
	if (Keyboard::Get()->Press(VK_LSHIFT))
	{
		if (Keyboard::Get()->Press('W'))
			position.y += cameraSpeed * Time::Delta();
		else if (Keyboard::Get()->Press('S'))
			position.y -= cameraSpeed * Time::Delta();

		if (Keyboard::Get()->Press('A'))
			position.x -= cameraSpeed * Time::Delta();
		else if (Keyboard::Get()->Press('D'))
			position.x += cameraSpeed * Time::Delta();
	}
}

void Camera::UpdateView()
{
	D3DXMatrixLookAtLH(&view, &position, &(position + Values::FwdVec), &Values::UpVec);
	vpBuffer->SetView(view);
}

void Camera::UnProjection(D3DXVECTOR3 * out, D3DXVECTOR3 source, D3DXMATRIX world)
{
	D3DXVECTOR3 position = source;

	out->x = (position.x * 2.0f / WinMaxWidth) - 1.0f;
	out->y = (position.y * 2.0f / WinMaxHeight) - 1.0f;
	out->z = position.z;

	D3DXMATRIX wvp = world * view * proj;
	D3DXMatrixInverse(&wvp, nullptr, &wvp);

	D3DXVec3TransformCoord(out, out, &wvp);
}

Camera::Camera()
{
	vpBuffer = new VPBuffer();

	D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
	D3DXMatrixOrthoOffCenterLH(&proj, 0.0f, (float)WinMaxWidth, 0.0f, (float)WinMaxHeight, 0, 1);
	vpBuffer->SetView(view);
	vpBuffer->SetProj(proj);
}

Camera::~Camera()
{
	SAFE_DELETE(vpBuffer);
}

void Camera::Shake(float shakeDuration, float shakeAmount, float decreaseFactor)
{
	this->shakeDuration = shakeDuration;
	this->shakeAmount = shakeAmount;
	this->decreaseFactor = decreaseFactor;
	originPos = position;
}

void Camera::ShakeUpdate()
{
	if (shakeDuration > 0)
	{
		position = position + D3DXVECTOR3
		(
			DxMath::ReliableRandom(-1, 1),
			DxMath::ReliableRandom(-1, 1),
			0
		) * shakeAmount;

		shakeDuration -= Time::Delta() * decreaseFactor;
	}
	else
	{
		shakeDuration = 0;
	}
}