#include "DxLib.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

//�v���O�����͂�������n�܂�܂��B
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//Window���[�h�ŋN������
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	GameObject* object = new Player();
	ResourceManager* resource_manager = GetResourceManager();

	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		object->Initialize();  //����������

		while (ProcessMessage() != -1)
		{
			InputControl::Update(); //�X�V����

			object->Update();

			ClearDrawScreen();      //��ʂ̏���������

			object->Draw();

			ScreenFlip();           //����ʂ̓��e��\��ʂɔ��f����

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

	object->Finalize();//�I������
	delete object;

	resource_manager->DeleteImages();  //�摜���폜

	DxLib_End();

	return 0;
}