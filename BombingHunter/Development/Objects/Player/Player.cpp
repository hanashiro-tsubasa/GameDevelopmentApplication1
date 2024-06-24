#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

Player::Player() : animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

Player::~Player()
{

}

//����������
void Player::Initialize()
{
	serial_number = 1;
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
	animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("���p�C���b�g�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = Vector2D(64.0f);

	//�����摜�̐ݒ�
	image = animation[0];
}

//�X�V����
void Player::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Player::Draw() const
//2
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);
	
	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I��������
void Player::Finalize()
{
	//�g�p�����摜���J��
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Player::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}

//�ړ�����
void Player::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//���E�ړ�
	if ((InputControl::GetKey(KEY_INPUT_LEFT)|| InputControl::GetKey(KEY_INPUT_A))&&location.x>0)
	{
		velocity.x += -3.0f;
		flip_flag = TRUE;
	}
	else if ((InputControl::GetKey(KEY_INPUT_RIGHT)|| InputControl::GetKey(KEY_INPUT_D))&&location.x<640)
	{
		velocity.x += 3.0f;
		flip_flag = FALSE;
	}
	
	else
	{
		velocity.x = 0.0f;
	}
	//3
	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Player::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//15�t���[���ڂɓ��B������
	if (animation_count >=48)
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
