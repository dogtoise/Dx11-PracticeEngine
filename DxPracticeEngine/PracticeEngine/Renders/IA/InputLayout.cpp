#include "PracticeEngine.h"
#include "InputLayout.h"

InputLayout::~InputLayout()
{
	SAFE_RELEASE(inputLayout);
}

void InputLayout::Create(D3D11_INPUT_ELEMENT_DESC * desc, UINT count, ID3DBlob * blob)
{
	if (!desc || !count || !blob)
		assert(false);

	HRESULT hr = DEVICE->CreateInputLayout
	(
		desc,
		count,
		blob->GetBufferPointer(),
		blob->GetBufferSize(),
		&inputLayout
	);
	assert(SUCCEEDED(hr));
}

void InputLayout::SetIA()
{
	DEVICECONTEXT->IASetInputLayout(inputLayout);
}
