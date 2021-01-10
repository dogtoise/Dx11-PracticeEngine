#include "PracticeEngine.h"
#include "DxHelpers.h"


const float Values::PI = 3.14159f;
const float Values::PI_TIMES_TWO = 6.28318530718f;

const D3DXVECTOR3 Values::ZeroVec3 = D3DXVECTOR3(0, 0, 0);
const D3DXVECTOR3 Values::OneVec3 = D3DXVECTOR3(1, 1, 1);
const D3DXVECTOR3 Values::RightVec = D3DXVECTOR3(1, 0, 0);
const D3DXVECTOR3 Values::LeftVec = D3DXVECTOR3(-1, 0, 0);
const D3DXVECTOR3 Values::UpVec = D3DXVECTOR3(0, 1, 0);
const D3DXVECTOR3 Values::DownVec = D3DXVECTOR3(0, -1, 0);
const D3DXVECTOR3 Values::FwdVec = D3DXVECTOR3(0, 0, 1);
const D3DXVECTOR3 Values::ScreenSize = D3DXVECTOR3((float)WinMaxWidth, (float)WinMaxHeight, 1);

const D3DXVECTOR2 Values::ZeroVec2 = D3DXVECTOR2(0, 0);
const D3DXVECTOR2 Values::OneVec2 = D3DXVECTOR2(1, 1);
const D3DXVECTOR2 Values::UVLT = D3DXVECTOR2(0, 0);
const D3DXVECTOR2 Values::UVLB = D3DXVECTOR2(0, 1);
const D3DXVECTOR2 Values::UVRT = D3DXVECTOR2(1, 0);
const D3DXVECTOR2 Values::UVRB = D3DXVECTOR2(1, 1);

const D3DXCOLOR Values::Red = D3DXCOLOR(1, 0, 0, 1);
const D3DXCOLOR Values::Green = D3DXCOLOR(0, 1, 0, 1);
const D3DXCOLOR Values::Blue = D3DXCOLOR(0, 0, 1, 1);
const D3DXCOLOR Values::Magenta = D3DXCOLOR(1, 0, 1, 1);
const D3DXCOLOR Values::Black = D3DXCOLOR(0, 0, 0, 1);
const D3DXCOLOR Values::White = D3DXCOLOR(1, 1, 1, 1);
const D3DXCOLOR Values::ClearColor = 0xFF555566;

const D3DXMATRIX Values::Identity = { 1, 0, 0, 0,
								  0, 1, 0, 0,
								  0, 0, 1, 0,
								  0, 0, 0, 1 };

