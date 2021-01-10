#pragma once

class Rect
{
public :
	Rect(D3DXVECTOR3 position, D3DXVECTOR3 size, float rotaiton);
	~Rect();

	void Update();
	void Render();

	void GUI();

	void UpdateWorld();

	D3DXVECTOR3 GetPosition() { return position; }


private :
	std::vector<VertexColor> vertices;
	VertexBuffer* vb = nullptr;

	std::vector<UINT> indices;
	IndexBuffer* ib = nullptr;

	VertexShader * vs = nullptr;
	ID3DBlob * vsBlob = nullptr;

	PixelShader * ps = nullptr;
	ID3DBlob * psBlob = nullptr;

	InputLayout * il = nullptr;

	D3DXMATRIX world;
	D3DXMATRIX S, R, T;

	D3DXVECTOR3 position;
	D3DXVECTOR3 size;
	float rotation;

	D3DXCOLOR color = D3DXCOLOR(1, 0, 0, 1);

	WorldBuffer * wb = nullptr;

};