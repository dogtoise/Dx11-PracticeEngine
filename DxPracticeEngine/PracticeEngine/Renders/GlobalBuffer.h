#pragma once
#include "PracticeEngine.h"
class WorldBuffer : public ShaderBuffer
{
public:
	WorldBuffer() : ShaderBuffer(&data, sizeof(Data))
	{
		D3DXMatrixIdentity(&data.world);
	}

	void SetWorld(D3DXMATRIX world)
	{
		D3DXMatrixTranspose(&data.world, &world);

	}

	struct Data
	{
		D3DXMATRIX world;
	};
private:
	Data data;

};

class VPBuffer : public ShaderBuffer
{
public:
	VPBuffer() : ShaderBuffer(&data, sizeof(Data))
	{
		D3DXMatrixIdentity(&data.view);
		D3DXMatrixIdentity(&data.projection);
	}
	void SetView(D3DXMATRIX view)
	{
		D3DXMatrixTranspose(&data.view, &view);
	}
	void SetProj(D3DXMATRIX projection)
	{
		D3DXMatrixTranspose(&data.projection, &projection);
	}
	struct Data
	{
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};
private :
	Data data;
};

