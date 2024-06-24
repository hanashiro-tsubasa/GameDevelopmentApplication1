#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);
	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//オブジェクトの生成
	Player* player = new Player();
	//裏画面に描画
	SetDrawScreen(DX_SCREEN_BACK);
	//ゲームループ
	while (ProcessMessage() != -1)
	{//入力機能の更新
		InputControl::Update();
		//プレイヤーの更新
		player->Update();
		//変数tmpにプレイヤーの座標を代入
		Vector2D tmp = player->GetLocation();
		//プレイヤーが外に行かないようにする/////////////
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;
			}
			else
			{
				tmp.x = 0.0f;
			}
			player->SetLocation(tmp);
		}
		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;
			}
			else
			{
				tmp.y = 0.0f;
			}
		}
		////////////////////////////////////////////////////
		//2
		player->SetLocation(tmp);   //プレイヤーの座標更新
		ClearDrawScreen();          //画面の初期化
		player->Draw();             //プレイヤーの描画処理
		ScreenFlip();               //裏画面の内容を表画面に反映
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))//ESCAPEキーが押されたらループから抜ける
		{
			break;
		}
	}
	delete player;  //オブジェクトの削除
	DxLib_End();    //DXライブラリの終了処理
	return 0;       //プログラムを終了
}