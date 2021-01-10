#pragma once

struct DXDesc
{
	std::wstring AppName;
	HINSTANCE instance;
	HWND handle;
	UINT width;
	UINT height;
};

class Window
{
public :
	Window(DXDesc desc);
	~Window();

	WPARAM Run(IScene* mainObj); // ����

private :
	static LRESULT CALLBACK WndProc // �޽��� ó���Լ�
	(
		HWND handle,//�â���� �˾ƺ��� â�� �ĺ���
		UINT message,//� �޼����� ���Դ��� �˾ƺ��°�.
		WPARAM wParam,//Ű������ ���õ����� �Ű���尡 ���ȴ��� �˾ƺ��°�.
		LPARAM lParam //���콺�� ��ǥ Ŭ���� ���ȴ��� ���콺�� ��ǥ�� �˾ƺ��°�.
	);
	void MainRender();
	static DXDesc desc;
	IScene* mainScene = nullptr;
};