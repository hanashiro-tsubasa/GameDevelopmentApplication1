#pragma once

#include "../GameObject.h"

class Player
{
private:
	int animation[2];      //�A�j���[�V�����摜
	int animation_count;   //�A�j���[�V��������
	int filp_flag;         //���]�O���t

public:
	Player();
	~Player();

	virtual void Initialize() override;   //����������
	virtual void Update() override;       //�X�V����
	virtual void Draw() const override;   //�`�揈��
	virtual void Finaleze() override;     //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object)override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();
};

