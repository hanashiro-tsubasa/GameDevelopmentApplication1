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
	//��������������Ȃ��ˁH
}

eSceneType TitleScene::Update(const float& delta_second)
{
	// ���͏����擾
	InputManager* input = InputManager::GetInstance();

	// �C���Q�[���V�[���ɑJ�ڂ���
 	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		return eSceneType::in_game;

	}
	if (input->GetButtonDown(XINPUT_BUTTON_START))
	{
		return eSceneType::in_game;
	}

	// �e�N���X�̍X�V�������Ăяo��
	return __super::Update(delta_second);
}

void TitleScene::Draw() 
{
	// �e�N���X�̕`�揈�����Ăяo��


	DrawRotaGraph(320, 240, 1.0, 0.0, title_img, TRUE);

	//__super::Draw();

	// UI�̕`��
	//���̕ӂɃ^�C�g���摜�`�悳�����炢������?
	/*SetFontSize(60);
	DrawFormatString(120, 140, GetColor(255, 255, 0), "M A R I O . EXE");
	SetFontSize(40);
	DrawFormatString(10, 640, GetColor(255, 0, 0), "Space key pressed game start");
	SetFontSize(16);*/
}

void TitleScene::Finalize()
{
	// �e�N���X�̏I�����������Ăяo��
	__super::Finalize();
}

const eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::title;
}

