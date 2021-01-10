#include "PracticeEngine.h"
#include "VertexShader.h"


VertexShader::~VertexShader()
{
	Clear();
}

void VertexShader::Create(const std::wstring path, const std::string entryName)
{
	this->path = path;
	this->entryName = entryName;

	CompileShader(path, entryName, "vs_5_0", &blob);
	HRESULT hr = DEVICE->CreateVertexShader
	(
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		nullptr,
		&shader
	);
	assert(SUCCEEDED(hr));
}

void VertexShader::Clear()
{
	SAFE_RELEASE(shader);
	SAFE_RELEASE(blob);
}

void VertexShader::SetShader()
{
	DEVICECONTEXT->VSSetShader(shader, nullptr, 0);
}