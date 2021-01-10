#include "PracticeEngine.h"
#include "IShader.h"


void IShader::CompileShader(std::wstring path, std::string entryName, std::string profile, ID3DBlob ** blob)
{
	ID3DBlob* error = nullptr;
	HRESULT hr = D3DX11CompileFromFile
	(
		path.c_str(),
		nullptr,
		nullptr,
		entryName.c_str(),
		profile.c_str(),
		D3DCOMPILE_ENABLE_STRICTNESS,
		0, 
		nullptr,
		blob,
		&error,
		nullptr
	);
	CheckShaderError(hr, error);
	SAFE_RELEASE(error);
}

void IShader::CheckShaderError(HRESULT hr, ID3DBlob * error)
{
	if (FAILED(hr))
	{
		if (error)
		{
			std::string str = (const char*)error->GetBufferPointer();
			MessageBoxA(handle, str.c_str(), "Shader Error", MB_OK);
		}
		assert(false);
	}
}
