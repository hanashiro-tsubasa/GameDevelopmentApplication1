#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == 1)
	{
		return -1;
	}
	//����ʂŕ`��
	SetDrawScreen(DX_SCREEN_BACK);
	//�I�u�W�F�N�g�̐���
	GameObject* object1 = new GameObject();
	Player*		object2 = new Player();
	//�I�u�W�F�N�g�̏�����
	object1->Initialize();
	object2->Initialize();
	//���C�����[�v
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
	//�I�u�W�F�N�g�폜
	delete object1;
	delete object2;
	//DX���C�u�����̏I������
	DxLib_End();

	return 0;
		
}