#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//���C���֐��i�v���O�����͂�������n�܂�܂��B�j
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�i���F640px,�c�F480px)��ݒ�
	SetGraphMode(640, 480, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}

	//�`���𗠉�ʂ���n�߂�悤�Ɏw�肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//���[�J���ϐ���`
	Scene* scene = new Scene();   //�V�[�����
	int result = 0;               //�I�������

	

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v�i�E�C���h�E�ُ̈픭���@or ESC�L�[�������ꂽ��A���[�v�I���j
		while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE)==false)

		{
			//���͋@�\�̍X�V
			InputControl::Update();

			//�V�[���̍X�V����
			scene->Update();

			//��ʂ̏�����
			ClearDrawScreen();

			//�V�[���̕`�揈��
			scene->Draw();
			//2
			//����ʂ̓��e��\��ʂɔ��f����
			ScreenFlip();
		}
	}
	catch (const char* error_log)
	{
		//�G���[����Log.txt�ɏo�͂���
		OutputDebugString(error_log);
		//�ُ��ԂɕύX����
		result = -1;
	}

	//�V�[����񂪑��݂��Ă���΁A�폜����
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DX���C�u�����̎g�p���I������
	DxLib_End();

	//�I����ԏ��̒l��ʒm����
	return result;
}