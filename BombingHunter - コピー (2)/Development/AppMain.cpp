#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"
#include"Objects/Score.h"

//メイン関数（プログラムはここから始まります。）
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Windowモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドウサイズ（横：640px,縦：480px)を設定
	SetGraphMode(640, 480, 32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//異常を通知
		return -1;
	}

	//描画先を裏画面から始めるように指定する
	SetDrawScreen(DX_SCREEN_BACK);

	//ローカル変数定義
	Scene* scene = new Scene();   //シーン情報
	int result = 0;               //終了時情報

	Score* score = new Score();



	try
	{
		//シーンの初期化
		scene->Initialize();
		score->Initialize();

		//メインループ（ウインドウの異常発生　or ESCキーが押されたら、ループ終了）
		while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)

		{
			//入力機能の更新
			InputControl::Update();

			//シーンの更新処理
			scene->Update();
			
			score -> Update();

			//画面の初期化
			ClearDrawScreen();

			//シーンの描画処理
			scene->Draw();

			score->Draw();
			//2
			//裏画面の内容を表画面に反映する
			ScreenFlip();
		}
	}
	catch (const char* error_log)
	{
		//エラー情報をLog.txtに出力する
		OutputDebugString(error_log);
		//異常状態に変更する
		result = -1;
	}

	//シーン情報が存在していれば、削除する
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DXライブラリの使用を終了する
	DxLib_End();

	//終了状態情報の値を通知する
	return result;
}