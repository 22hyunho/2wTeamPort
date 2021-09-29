#pragma once

#include "targetver.h"
#include "resource.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

//d2d lib
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "WindowsCodecs.lib")

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include "Resource.h"
#include "macroFunc.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "utils.h"
#include "cameraManager.h"
#include "timeManager.h"
#include "sceneManager.h"
#include "printManager.h"
#include "collisionManager.h"
#include "uiManager.h"
#include "EffectManager.h"
#include "InventoryManager.h"
#include "tileManager.h"
#include "txtData.h"
#include "streamManager.h"
#include "dtdManager.h"
#include "pokeDex.h"
#include "skillDex.h"
#include "turnManager.h"
#include "dialogManager.h"
#include "battleManager.h"
#include "soundManager.h"


using namespace std;
using namespace MACRO_FUNC;
using namespace D2D1;

//==================================
// ## 매크로 처리 ##
//==================================

#define WINNAME (LPTSTR)(TEXT("Pokemon Mystery Dungeon : Explorers of Time"))
#define WINSTARTX 50	//윈도우 창 시작좌표 (left)
#define WINSTARTY 50	//윈도우 창 시작좌표 (top)
#define WINSIZEX 1100	//윈도우 가로크기
#define WINSIZEY 900	//윈도우 세로크기
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define PRINTMANAGER printManager::getSingleton()
#define COLLISIONMANAGER collisionManager::getSingleton()
#define UIMANAGER uiManager::getSingleton()
#define EFFECTMANAGER EffectManager::getSingleton()
#define INVENTORYMANAGER InventoryManager::getSingleton()
#define TILEMANAGER tileManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define STREAMMANAGER streamManager::getSingleton()
#define DTDMANAGER dtdManager::getSingleton()
#define POKEDEX pokeDex::getSingleton()
#define SKILLDEX skillDex::getSingleton()
#define TURNMANAGER turnManager::getSingleton()
#define DIALOGMANAGER dialogManager::getSingleton()
#define BATTLEMANAGER battleManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()

#define SAFE_DELETE(p) { if(p) { delete(p); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p); (p) = nullptr; } }
#define SAFE_RELEASE(p) { if(p) { (p)->release(); (p) = NULL; } }
#define SAFE_RELEASE2(p) { if(p) { (p)->Release(); (p) = NULL; } }

#define TILEWIDTH	48
#define TILEHEIGHT	48

//==================================
// ## extern ##
//==================================
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;