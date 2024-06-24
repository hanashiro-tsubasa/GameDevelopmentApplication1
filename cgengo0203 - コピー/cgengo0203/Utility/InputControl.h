#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];  //���͂��ꂽ���̃L�[
	static char old_key[D_KEYCODE_MAX];  //���͂��ꂽ�Â��L�[

public:
	static void Update();//�X�V����

	static bool GetKey(int key_code);      //�����Ă鎞�̏���
	static bool GetKeyDown(int key_code);  //�������u�Ԃ̏���
	static bool GetKeyUp(int key_code);    //�������Ƃ��̏���

private:
	static bool CheckKeyCodeRange(int key_code);//�L�[�R�[�h�̗L���͈̓`�F�b�N
};
