#pragma once

class Camera : public SingletonBase<Camera>
{
public :
	friend class SingletonBase<Camera>;

	void Update();
	void Render();

	void Move();
	void UpdateView();

	void UnProjection(D3DXVECTOR3 * out, D3DXVECTOR3 source, D3DXMATRIX world);


	D3DXVECTOR3 GetPos()
	{
		return position;
	}

private :
	Camera();
	~Camera();

	VPBuffer * vpBuffer = nullptr;
	D3DXMATRIX view, proj;

	D3DXVECTOR3 position = Values::ZeroVec3;

	float cameraSpeed = 100.0f;
public :
	void Shake(float shakeDuration, float shakeAmount = 0.7f, float decreaseFactor = 1.0f);

private :
	void ShakeUpdate();

private :
	float shakeDuration = 0;
	float shakeAmount = 0;
	float decreaseFactor = 0;
	D3DXVECTOR3 originPos;
};
