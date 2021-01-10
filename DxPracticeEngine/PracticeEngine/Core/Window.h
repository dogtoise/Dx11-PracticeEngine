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

	WPARAM Run(IScene* mainObj); // 게임

private :
	static LRESULT CALLBACK WndProc // 메시지 처리함수
	(
		HWND handle,//어떤창인지 알아보는 창의 식별자
		UINT message,//어떤 메세지가 들어왔는지 알아보는것.
		WPARAM wParam,//키보드의 관련된정보 어떤키보드가 눌렸는지 알아보는것.
		LPARAM lParam //마우스의 좌표 클릭이 눌렸는지 마우스의 좌표를 알아보는것.
	);
	void MainRender();
	static DXDesc desc;
	IScene* mainScene = nullptr;
};