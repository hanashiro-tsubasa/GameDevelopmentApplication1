#include "WingEnemy.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



WingEnemy::WingEnemy() : animation_count(0), direction(0.0f), EnemySpeed(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

WingEnemy::~WingEnemy()
{

}

//����������
void WingEnemy::Initialize()
{
	serial_number = 4;
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/WingEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/WingEnemy/2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�l�e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];
	//�G�̃X�s�[�h�̐ݒ�
	EnemySpeed = (rand() % 4 + 1);

	//�����i�s�����̐ݒ�
	if (location.x < 41.0f)
	{
		direction = Vector2D(EnemySpeed, 0.0f /*-0.5f*/);
	}
	else
	{
		direction = Vector2D(EnemySpeed * -1, 0.0f);
	}
}

//�X�V����
void WingEnemy::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();

	int ShotCreaterand = rand() % 100 + 1;
	if (ShotCreaterand == 1)
	{
		shotflg = TRUE;
	}
	else
	{
		shotflg = FALSE;
	}

	if (location.x > 680 || location.x < -50)
	{
		deleteflg = TRUE;
	}
}
//2
//�`�揈��
void WingEnemy::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//�������ƂɃn�l�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I��������
void WingEnemy::Finalize()
{
	//�g�p�����摜���J��
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void WingEnemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	//direction = 1.0f;
	if (hit_object->GetSerialNumber() == 3)
	{
		deleteflg = TRUE;
	}
}

//�ړ�����
void WingEnemy::Movement()
{
	//��ʒ[�ɓ��B������A�i�s�����𔽓]����
	//if (((location.x + direction.x) < box_size.x) ||
	//	(640.0f - box_size.x) < (location.x + direction.x))
	//{
	//	direction.x *= -1.0f;
	//}
	////2
	//if (((location.y + direction.y) < box_size.y) ||
	//	(480.0f - box_size.y) < (location.y + direction.y))
	//{
	//	direction.y *= -1.0f;
	//}

	//�i�s�����Ɍ������āA�ʒu���W��ύX����

	location += direction;

}

//�A�j���[�V��������
void WingEnemy::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//30�t���[���ڂɓ��B������
	if (animation_count >= 30)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}
