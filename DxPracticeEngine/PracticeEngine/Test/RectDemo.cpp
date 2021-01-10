#include "PracticeEngine.h"
#include "RectDemo.h"
#include "Geometries/Rect.h"

void RectDemo::Init()
{
	Camera::Create();
	rect = new Rect(D3DXVECTOR3(620, 360, 0), D3DXVECTOR3(100, 100, 1), 0.0f);
}

void RectDemo::Destroy()
{
	Camera::Delete();
	SAFE_DELETE(rect);
}

void RectDemo::Update()
{
	Camera::Get()->Update();
	rect->Update();
}

void RectDemo::Render()
{
	Camera::Get()->Render();
	rect->Render();
}

void RectDemo::GUI()
{
}
