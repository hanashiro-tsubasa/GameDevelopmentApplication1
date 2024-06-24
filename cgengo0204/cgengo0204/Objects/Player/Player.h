#pragma once

#include "../GameObject.h"
#include <vector>

class Player : public GameObject
{
private:
	Vector2D velocity;                     //�����x
	std::vector<int> animation_image;      //�A�j���[�V�����摜
	int animation_state;                   //
	int animation_count;                   //�A�j���[�V�����̎���

public:
	Player();
		virtual ~Player();
	
	//����������
	virtual void Initialize() override;
	//�X�V����
	virtual void Update() override;
	//�`�揈��
	virtual void Draw() const override;
	//�I��������
	virtual void Finalize() override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V�����̐���
	void AnimationControl();
};
