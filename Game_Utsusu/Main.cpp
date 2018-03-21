
#include "Main.h"

auto	vsthost_Init(void) {

	Host::ComInit comInit{};

	const auto dllFilename = []() -> std::wstring {
		wchar_t fn[MAX_PATH + 1]{};
		OPENFILENAME ofn{ sizeof(ofn) };
		ofn.lpstrFilter = L"VSTi DLL(*.dll)\0*.dll\0All Files(*.*)\0*.*\0\0";
		ofn.lpstrFile = fn;
		ofn.nMaxFile = _countof(fn);
		ofn.lpstrTitle = L"Select VST DLL";
		ofn.Flags = OFN_FILEMUSTEXIST | OFN_ENABLESIZING;
		GetOpenFileName(&ofn);
		return fn;
	} ();

	return dllFilename;
	/*
	try {
	mainLoop(dllFilename);
	}
	catch (std::exception &e) {
	std::cout << "Exception : " << e.what() << std::endl;
	}
	*/
}
void main_loop(const std::wstring& dllFilename);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// 設定
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
	SetMainWindowText(_T("写譜屋"));

	SetDrawScreen(DX_SCREEN_BACK);

	// 初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ゲーム初期化
	game_init();

	// メインループ
	main_loop(vsthost_Init());

	// ゲーム終了
	game_end();
	DxLib_End();

	return 0;
}



int get_event;

// メインループ
void main_loop(const std::wstring& dllFilename) {

	Host::VstPlugin vstPlugin{ dllFilename.c_str(), GetConsoleWindow() };
	Host::Wasapi wasapi{ [&vstPlugin](float* const data, uint32_t availableFrameCount, const WAVEFORMATEX* const mixFormat) {
		return refillCallback(vstPlugin, data, availableFrameCount, mixFormat);
	} };

	struct Key {
		Key(int midiNote) : midiNote{ midiNote } {}
		int     midiNote{};
		bool    status{ false };
	};

	std::map<int, Key> keyMap{
		{ '2',{ 61 } },{ '3',{ 63 } },{ '5',{ 66 } },{ '6',{ 68 } },{ '7',{ 70 } },
	{ 'Q',{ 60 } },{ 'W',{ 62 } },{ 'E',{ 64 } },{ 'R',{ 65 } },{ 'T',{ 67 } },{ 'Y',{ 69 } },{ 'U',{ 71 } },{ 'I',{ 72 } },

	{ 'S',{ 49 } },{ 'D',{ 51 } },{ 'G',{ 54 } },{ 'H',{ 56 } },{ 'J',{ 58 } },
	{ 'Z',{ 48 } },{ 'X',{ 50 } },{ 'C',{ 52 } },{ 'V',{ 53 } },{ 'B',{ 55 } },{ 'N',{ 57 } },{ 'M',{ 59 } },{ VK_OEM_COMMA,{ 60 } },
	};

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
	{

		for (auto& e : keyMap) {
			auto& key = e.second;
			const auto on = (GetKeyState(e.first) & 0x8000) != 0;
			if (key.status != on) {
				key.status = on;
				vstPlugin.sendMidiNote(0, key.midiNote, on, 100);
			}
		}
		// ゲームメイン
		game_main();
	}
}

