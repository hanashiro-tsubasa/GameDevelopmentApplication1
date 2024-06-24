#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

public:
	static void Update();                         //�X�V����
	
	static bool GetKey(int key_code);             //�L�[��������Ă���Ԃ̏���
	static bool GetKeyDown(int key_code);         //�L�[���������u�Ԃ̏���
	static bool GetKeyUp(int key_code);           //�L�[��b�����Ƃ��̏���

private:
	static bool CheckKeyCodeRange(int key_code);  //
};

