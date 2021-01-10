#pragma once

#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// pch
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <functional>
#include <fstream>
#include <set>
#include <random>


// DirectX
#include <d3dcompiler.h>
#include <d3d11.h>
#include <D3DX10math.h>
#include <D3DX11async.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "d3dcompiler.lib")


// ImGui
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#pragma comment(lib, "ImGui/ImGui.lib")
 
// DirectXTex
#include "DirectTex/DirectXTex.h"
#pragma comment(lib, "DirectTex/DirectXTex.lib")


 
#define SAFE_DELETE(p) { if(p) { delete(p); (p) = nullptr; }}
#define SAFE_DELETE_ARRAY(p){ if(p) { delete[](p); (p) = nullptr; }}
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p) = nullptr;}}

#define DEVICE Graphics::Get()->GetDevice()
#define DEVICECONTEXT	   Graphics::Get()->GetDeviceContext()


#define WinMaxWidth 1280
#define WinMaxHeight 720

const std::wstring ShaderPath = L"../_Shaders/";
const std::wstring TexturePath = L"../_Resources/_Textures/";

extern HWND handle;





#include "Utilities/DxHelpers.h"
#include "Utilities/SingletonBase.h"
#include "Utilities/Keyboard.h"
#include "Utilities/Mouse.h"
#include "Utilities/Time.h"
#include "Utilities/Gui.h"


#include "Core/IScene.h"
#include "Core/Graphics.h"
#include "Core/Window.h"

#include "Renders/ShaderBuffer.h"
#include "Renders/GlobalBuffer.h"

#include "Renders/Shaders/VertexShader.h"
#include "Renders/Shaders/PixelShader.h"
#include "Renders/VertexTypes.h"

#include "Renders/IA/IndexBuffer.h"
#include "Renders/IA/VertexBuffer.h"
#include "Renders/IA/InputLayout.h"

#include "Core/Camera.h"