#pragma once

class Entry : public IScene
{
public:
	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void GUI() override;

private :
	void Push(IScene * scene);
	void Pop(IScene * scene);

	VPBuffer * vpBuffer = nullptr;
	D3DXMATRIX view, proj;
	std::vector<IScene*> scenes;



};