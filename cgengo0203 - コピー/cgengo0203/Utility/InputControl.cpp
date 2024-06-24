#include "InputControl.h"
#include "DxLib.h"

char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};
//���͋@�\�̍X�V����
void InputControl::Update()
{
	memcpy(old_key, now_key,(sizeof(char) * D_KEYCODE_MAX));
	GetHitKeyStateAll(now_key);
}
//�L�[��������Ă�Ԃ̏���
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}
//�L�[�������ꂽ�u�Ԃ̏���
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}
//�L�[�������ꂽ�Ƃ��̏���

bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}
//�L�[�R�[�h�̊m�F
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}
