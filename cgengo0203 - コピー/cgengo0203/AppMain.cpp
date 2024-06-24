#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR LpCmdLine,
	_In_ int nShowCmd
)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//�I�u�W�F�N�g�̐���
	GameObject* objects[2] = { nullptr, nullptr };
	objects[0] = new GameObject();
	objects[1] = new Player();
	//�I�u�W�F�N�g�̏�����
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize();
	}
	//����ʂŕ`��
	SetDrawScreen(DX_SCREEN_BACK);
	//���C�����[�v
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
		//�I�u�W�F�N�g�̍폜
		delete objects[i];
	}
	//DX���C�u�����̏I������
	DxLib_End();

	return 0;
}
