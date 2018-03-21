
//--- ウィンドウサイズ----------------
#define WINDOW_SIZE_X (1280)
#define WINDOW_SIZE_Y (720)

//--- ライブラリ----------------------
#include "DxLib.h"
#include <windows.h>
#include <process.h>
#include <mmdeviceapi.h>
#include <audioclient.h>

#include <algorithm>
#include <atomic>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#pragma warning(push)
#pragma warning(disable : 4996)
#include "vst2.x/aeffectx.h"
#pragma warning(pop)


#define ASSERT_THROW(c,e)   if(!(c)) { throw std::runtime_error(e); }
#define CLOSE_HANDLE(x)     if((x)) { CloseHandle(x); x = nullptr; }
#define RELEASE(x)          if((x)) { (x)->Release(); x = nullptr; }

extern int get_event;

//--- ヘッダインクルード --------
#include "Global.h"
