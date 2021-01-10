#include "PracticeEngine.h"
#include "Rect.h"

Rect::Rect(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotation)
	: position(position), size(size), rotation(rotation)
{
	// vertices
	{
		vertices.assign(4, VertexColor());

		vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f); // left bottom
		vertices[0].color = D3DXCOLOR(1, 0, 0, 1);

		vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f); // left top
		vertices[1].color = D3DXCOLOR(1, 0, 0, 1);

		vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f); // right bottom
		vertices[2].color = D3DXCOLOR(1, 0, 0, 1);

		vertices[3].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f); // right top
		vertices[3].color = D3DXCOLOR(1, 0, 0, 1);
	}
	// vertexBuffer
	{
		vb = new VertexBuffer();
		vb->Create(vertices, D3D11_USAGE_DYNAMIC);
	}
	// indexBuffer
	{
		indices = { 0, 1, 2, 2, 1, 3 };
		ib = new IndexBuffer();
		ib->Create(indices, D3D11_USAGE_IMMUTABLE);
	}
	// vertexShader
	{
		vs = new VertexShader();
		vs->Create(ShaderPath + L"VertexColor.hlsl", "VS");
	}
	// inputLayout
	{
		il = new InputLayout();
		il->Create(VertexColor::descs, VertexColor::count, vs->GetBlob());
	}
	// PixelShader
	{
		ps = new PixelShader();
		ps->Create(ShaderPath + L"VertexColor.hlsl", "PS");
	}

	wb = new WorldBuffer();

	UpdateWorld();
}

Rect::~Rect()
{
	SAFE_DELETE(wb);
	SAFE_DELETE(ps);
	SAFE_DELETE(il);
	SAFE_DELETE(vs);
	SAFE_DELETE(ib);
	SAFE_DELETE(vb);
}

void Rect::Update()
{
	UpdateWorld();
}

void Rect::Render()
{
	vb->SetIA();
	ib->SetIA();
	il->SetIA();
	DEVICECONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	vs->SetShader();
	wb->SetVSBuffer(0); 
	ps->SetShader();

	DEVICECONTEXT->DrawIndexed(ib->GetCount(), 0, 0);
}

void Rect::GUI()
{
}

void Rect::UpdateWorld()
{
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);
	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));

	world = S * R * T;
	wb->SetWorld(world);
}