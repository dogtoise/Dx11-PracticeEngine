#include "PracticeEngine.h"
#include "Entry.h"

#include "RectDemo.h"
void Entry::Init()
{
	Push(new RectDemo());
}

void Entry::Destroy()
{
	for (IScene * scene : scenes)
	{
		scene->Destroy();
		SAFE_DELETE(scene);
	}
}

void Entry::Update()
{
	for (IScene * scene : scenes)
		scene->Update();
}

void Entry::Render()
{
	for (IScene * scene : scenes)
		scene->Render();
}

void Entry::GUI()
{
	for (IScene * scene : scenes)
		scene->GUI();
}

void Entry::Push(IScene * scene)
{
	scenes.push_back(scene);
	scene->Init();
}
void Entry::Pop(IScene* scene)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i] == scene)
			scenes.erase(scenes.begin() + i);
	}
}


int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR param, int command)
{
	srand((UINT)time(NULL));

	DXDesc desc;
	desc.AppName = L"test_game";
	desc.instance = instance;
	desc.handle = NULL;
	desc.width = WinMaxWidth;
	desc.height = WinMaxHeight;

	Entry * entry = new Entry();
	Window * window = new Window(desc);

	WPARAM wParam = window->Run(entry);
	SAFE_DELETE(window);
	SAFE_DELETE(entry);

	return wParam;
}