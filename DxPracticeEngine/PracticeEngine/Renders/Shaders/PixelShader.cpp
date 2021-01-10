#include "PracticeEngine.h"
#include "PixelShader.h"


void PixelShader::Create(const std::wstring path, const std::string entryName)
{
	this->path = path;
	this->entryName = entryName;

	CompileShader(path, entryName, "ps_5_0", &blob);
	HRESULT hr = DEVICE->CreatePixelShader
	(
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		nullptr,
		&shader
	);
	assert(SUCCEEDED(hr));
}

void PixelShader::Clear()
{
	SAFE_RELEASE(shader);
	SAFE_RELEASE(blob);
}

void PixelShader::SetShader()
{
	DEVICECONTEXT->PSSetShader(shader, nullptr, 0);
}
