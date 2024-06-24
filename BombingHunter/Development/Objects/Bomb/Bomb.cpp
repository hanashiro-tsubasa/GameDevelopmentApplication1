#include "Bomb.h"
#include "DxLib.h"


Bomb::Bomb() : animation_count(0),BombSpeed(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
}

Bomb::~Bomb()
{

}

//����������
void Bomb::Initialize()
{
	serial_number = 3;
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/Bomb/Bomb.png");
	animation[1] = LoadGraph("Resource/Images/Blast/1.png");
	animation[2] = LoadGraph("Resource/Images/Blast/2.png");
	animation[3] = LoadGraph("Resource/Images/Blast/3.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1)
	{
		throw("���e�̉摜������܂���\n");
	}
	if (animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	{
		throw("�����̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 1.57f;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];

	//���e�̃X�s�[�h�̐ݒ�
	BombSpeed = 3.0f;
}

//�X�V����
void Bomb::Update()
{

	
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();

	//�摜����
    if (location.y > 410)
	{
		hitflg = TRUE;
		box_size = 0.00f;
		BombSpeed = 0.0f;
	}
	
}

//�`�揈��
void Bomb::Draw() const
{
	//�������Ƃɔ��e��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I��������
void Bomb::Finalize()
{
	//�g�p�����摜���J��
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//�����蔻��ʒm����
void Bomb::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	
	if (hit_object->GetSerialNumber() != 3)
	{
		hitflg = TRUE;
		box_size = 0.00f;
		BombSpeed = 0.0f;
	}
}

//�ړ�����
void Bomb::Movement()
{
	location.y += BombSpeed;
}

//�A�j���[�V��������
void Bomb::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//10�t���[���ڂɓ��B������
	if (animation_count >= 10&&hitflg==TRUE)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			BombSpeed = 0;
			radian = 0.0f;
			image = animation[1];
		}
		else if(image==animation[1])
		{
			image = animation[2];
		}
		else if (image == animation[2])
		{
			image = animation[3];
		}
		else if (image == animation[3])
		{
			deleteflg = TRUE;
		}
	}
}