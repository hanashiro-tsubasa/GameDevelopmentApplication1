#include "TitleScene.h"
#include "../../Utility/InputManager.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

TitleScene::TitleScene()
	: title_img(NULL)
{
}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	title_img = rm->GetImages("Resource/Images/title.png")[0];
	//ここも引数たりなくね？
}

eSceneType TitleScene::Update(const float& delta_second)
{
	// 入力情報を取得
	InputManager* input = InputManager::GetInstance();

	// インゲームシーンに遷移する
 	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		return eSceneType::in_game;

	}
	if (input->GetButtonDown(XINPUT_BUTTON_START))
	{
		return eSceneType::in_game;
	}

	// 親クラスの更新処理を呼び出す
	return __super::Update(delta_second);
}

void TitleScene::Draw() 
{
	// 親クラスの描画処理を呼び出す


	DrawRotaGraph(320, 240, 1.0, 0.0, title_img, TRUE);

	//__super::Draw();

	// UIの描画
	//この辺にタイトル画像描画させたらいいかも?
	/*SetFontSize(60);
	DrawFormatString(120, 140, GetColor(255, 255, 0), "M A R I O . EXE");
	SetFontSize(40);
	DrawFormatString(10, 640, GetColor(255, 0, 0), "Space key pressed game start");
	SetFontSize(16);*/
}

void TitleScene::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

const eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::title;
}

