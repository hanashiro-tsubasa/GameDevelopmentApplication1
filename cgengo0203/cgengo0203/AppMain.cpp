#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR LpCmdLine,
	_In_ int nShowCmd
)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//オブジェクトの生成
	GameObject* objects[2] = { nullptr, nullptr };
	objects[0] = new GameObject();
	objects[1] = new Player();
	//オブジェクトの初期化
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize();
	}
	//裏画面で描画
	SetDrawScreen(DX_SCREEN_BACK);
	//メインループ
	while (ProcessMessage() != -1)
	{
		InputControl::Update();

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}

		ClearDrawScreen();

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();
		}

		ScreenFlip();

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
			//2
		}
	}

	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		//オブジェクトの削除
		delete objects[i];
	}
	//DXライブラリの終了処理
	DxLib_End();

	return 0;
}
