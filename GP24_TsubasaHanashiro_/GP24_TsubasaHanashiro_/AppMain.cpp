#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);
	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//�I�u�W�F�N�g�̐���
	Player* player = new Player();
	//����ʂɕ`��
	SetDrawScreen(DX_SCREEN_BACK);
	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{//���͋@�\�̍X�V
		InputControl::Update();
		//�v���C���[�̍X�V
		player->Update();
		//�ϐ�tmp�Ƀv���C���[�̍��W����
		Vector2D tmp = player->GetLocation();
		//�v���C���[���O�ɍs���Ȃ��悤�ɂ���/////////////
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
		player->SetLocation(tmp);   //�v���C���[�̍��W�X�V
		ClearDrawScreen();          //��ʂ̏�����
		player->Draw();             //�v���C���[�̕`�揈��
		ScreenFlip();               //����ʂ̓��e��\��ʂɔ��f
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))//ESCAPE�L�[�������ꂽ�烋�[�v���甲����
		{
			break;
		}
	}
	delete player;  //�I�u�W�F�N�g�̍폜
	DxLib_End();    //DX���C�u�����̏I������
	return 0;       //�v���O�������I��
}