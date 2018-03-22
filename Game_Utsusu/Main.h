
//--- ウィンドウサイズ----------------
#define WINDOW_SIZE_X (1280)
#define WINDOW_SIZE_Y (720)

//--- ライブラリ----------------------
#include "DxLib.h"
#include <windows.h>
#include <process.h>
#include <mmdeviceapi.h>
#include <audioclient.h>

#include <stdlib.h>
#include <algorithm>
#include <atomic>
#include <iostream>
#include <fstream>
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

typedef struct {
	int type;
	int time;
	int interval;
}get_event;

typedef struct {
	int s_time;
	int inter;
}save_note;

#define ASSERT_THROW(c,e)   if(!(c)) { throw std::runtime_error(e); }
#define CLOSE_HANDLE(x)     if((x)) { CloseHandle(x); x = nullptr; }
#define RELEASE(x)          if((x)) { (x)->Release(); x = nullptr; }

extern get_event note;

//--- ヘッダインクルード --------
#include "Global.h"
