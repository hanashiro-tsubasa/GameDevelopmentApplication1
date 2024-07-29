#pragma once

#define D_KEYCODE_MAX (256)

//���͐���N���X
class InputControl
{
private:
	static InputControl* instance;

	char now_key[D_KEYCODE_MAX];   //���݂̓��͒l
	char old_key[D_KEYCODE_MAX];   //�O��̓��͒l

private:
	InputControl();
	//�R�s�[�K�[�h
	InputControl(const InputControl&) = default;
	InputControl& operator = (const InputControl& v) = default;
	//~�R�s�[�K�[�h

public:
	~InputControl();

	//�C���X�^���X�擾����
	static InputControl* GetInstance();
	//�C���X�^���X�폜����
	static void DeleteInstance();

	//���͒l�̍X�V����
	void Update();

	//�L�[�擾
	bool GetKey(int key_code) const;
	bool GetKeyDown(int key_code) const;
	bool GetKeyUp(int key_code) const;

private:
	//�L�[�͈̓`�F�b�N
	bool CheckKeyCodeRange(int key_code) const;
};

