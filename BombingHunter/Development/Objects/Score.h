#pragma once
#include"GameObject.h"

class Score : public GameObject
{
private:
	int kazuimage[10];         //�����̉摜
	int text1;           //�e�L�X�g�̉摜
	int text2;           //�e�L�X�g�̉摜
	int timer;
public:
	Score();
	~Score();

	//����������
	virtual void Initialize() override;
	//�X�V����
	virtual void Update() override;
	//�`�揈��
	virtual void Draw() const override;
	//�I��������
	virtual void Finalize() override;

};


