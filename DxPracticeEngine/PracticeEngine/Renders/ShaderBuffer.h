#pragma once
#include "PracticeEngine.h"

class ShaderBuffer
{
public :
	void SetVSBuffer(UINT slot)
	{
		MapData();
		DEVICECONTEXT->VSSetConstantBuffers(slot, 1, &buffer);
	}
	void SetPSBuffer(UINT slot)
	{
		MapData();
		DEVICECONTEXT->PSSetConstantBuffers(slot, 1, &buffer);
	}

protected :
	ShaderBuffer(void* data, UINT dataSize)
		: data(data), dataSize(dataSize)
	{
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.ByteWidth = dataSize;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		HRESULT hr = DEVICE->CreateBuffer(&desc, nullptr, &buffer);
		assert(SUCCEEDED(hr));
	}

private :
	void MapData()
	{
		D3D11_MAPPED_SUBRESOURCE subResource;
		HRESULT hr = DEVICECONTEXT->Map
		(
			buffer,
			0, 
			D3D11_MAP_WRITE_DISCARD,
			0,
			&subResource
		);
		memcpy(subResource.pData, data, dataSize);
		DEVICECONTEXT->Unmap(buffer, 0);
	}


private :
	D3D11_BUFFER_DESC desc = { 0 };
	ID3D11Buffer* buffer = nullptr;

	void * data = nullptr;
	UINT dataSize = 0;
};