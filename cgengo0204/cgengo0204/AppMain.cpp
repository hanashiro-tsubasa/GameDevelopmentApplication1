#include "DxLib.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

//プログラムはここから始まります。
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//Windowモードで起動する
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	GameObject* object = new Player();
	ResourceManager* resource_manager = GetResourceManager();

	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		object->Initialize();  //初期化処理

		while (ProcessMessage() != -1)
		{
			InputControl::Update(); //更新処理

			object->Update();

			ClearDrawScreen();      //画面の初期化処理

			object->Draw();

			ScreenFlip();           //裏画面の内容を表画面に反映する

			if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}
	catch (std::string error_log)
	{
		OutputDebugString(error_log.c_str());
		//2
	}

	object->Finalize();//終了処理
	delete object;

	resource_manager->DeleteImages();  //画像を削除

	DxLib_End();

	return 0;
}