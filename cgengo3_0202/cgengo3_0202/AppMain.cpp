#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == 1)
	{
		return -1;
	}
	//裏画面で描画
	SetDrawScreen(DX_SCREEN_BACK);
	//オブジェクトの生成
	GameObject* object1 = new GameObject();
	Player*		object2 = new Player();
	//オブジェクトの初期化
	object1->Initialize();
	object2->Initialize();
	//メインループ
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();

		object1->Update();
		object2->Update();

		ClearDrawScreen();

		object1->Draw();
		object2->Draw();

		ScreenFlip();

	}
	//オブジェクト削除
	delete object1;
	delete object2;
	//DXライブラリの終了処理
	DxLib_End();

	return 0;
		
}