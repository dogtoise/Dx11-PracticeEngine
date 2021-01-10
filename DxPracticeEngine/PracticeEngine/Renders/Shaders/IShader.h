#pragma once

class IShader
{
public:
	virtual void Create(const std::wstring path, const std::string entryName) = 0;
	virtual void Clear() = 0;
	virtual void SetShader() = 0;

protected:
	void CompileShader(std::wstring path, std::string entryName, std::string profile, ID3DBlob** blob);

	std::wstring path = L"";
	std::string entryName = "";
private:
	void CheckShaderError(HRESULT hr, ID3DBlob* error);
};