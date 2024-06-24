#pragma once

#include "../GameObject.h"

class EnemyBullet :public GameObject
{
private:
	int animation[4];               //�摜
	int animation_count;        //�A�j���[�V��������
	float BombSpeed;         //���e�̃X�s�[�h
public:
	EnemyBullet();
	~EnemyBullet();

	//����������
	virtual void Initialize() override;
	//�X�V����
	virtual void Update() override;
	//�`�揈��
	virtual void Draw() const override;
	//�I��������
	virtual void Finalize() override;

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimationControl();
};

