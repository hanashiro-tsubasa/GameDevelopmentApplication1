#include "InputControl.h"
#include "DxLib.h"

//�ÓI�����o�ϐ���`
InputControl* InputControl::instance = nullptr;  //�N���X�̃C���X�^���X�̃|�C���^

//���͐���N���X�̃C���X�^���X�擾���鏈��
InputControl* InputControl::GetInstance()
{
	//�C���X�^���X���Ȃ���΁A��������
	if (instance == nullptr)
	{
		instance = new InputControl();
	}

	//�������g�̃|�C���^��ԋp����
	return instance;
}

//���͐���N���X�̃C���X�^���X�폜���鏈��
void InputControl::DeleteInstance()
{
	//�C���X�^���X�����݂��Ă���΁A�폜����
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputControl::Update()
{
	//�ϐ��̍쐬
	XINPUT_STATE input_controller;

	GetJoypadXInputState(DX_INPUT_PAD1, &input_controller);
	for (int i = 0; i < 16; i++)
	{
		old_button[i] = now_button[i];
		if (input_controller.Buttons[i] == TRUE)
		{
			now_button[i] = true;
		}
		else
		{
			now_button[i] = false;
		}
	}
	//�O����͒l�̍X�V
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//���ݓ��͒l�̍X�V
	GetHitKeyStateAll(now_key);
}

//�L�[��������Ă��邩�m�F���鏈��
bool InputControl::GetKey(int key_code)const
{
	return(CheckKeyCodeRange(key_code) && (now_key[key_code] == TRUE &&
		old_key[key_code] == TRUE));
}

//�L�[�������ꂽ�u�Ԃ��m�F���鏈��
bool InputControl::GetKeyDown(int key_code) const
//2
{
	return(CheckKeyCodeRange(key_code) && (now_key[key_code] == TRUE &&
		old_key[key_code] == FALSE));
}

//�L�[�������ꂽ�u�Ԃ��m�F���鏈��
bool InputControl::GetKeyUp(int key_code)const
{
	return(CheckKeyCodeRange(key_code) && (now_key[key_code] == FALSE &&
		old_key[key_code] == TRUE));
}
bool InputControl::GetButton(int button)const
{
	if (now_button[button] == true && old_button[button] == true)
	{
		return  true;
	}
	return false;
}
bool InputControl::GetButtonDown(int button)const
{
	if (now_button[button] == true && old_button[button] == false)
	{
		return  true;
	}
	return false;
}

bool InputControl::GetButtonUp(int button)const
{
	if (now_button[button] == false && old_button[button] == true)
	{
		return  true;
	}
	return false;
}

bool InputControl::CheckButtonRange(int button)const
{
	return (0 <= button && button < 16);
}
//�L�[�R�[�h�͈͓̔����m�F���鏈��
bool InputControl::CheckKeyCodeRange(int key_code) const
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}
