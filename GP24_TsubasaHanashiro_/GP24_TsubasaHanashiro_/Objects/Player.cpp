#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
//�R���X�g���N�^
Player::Player() : location(), direction(0.0f), radius(15.0f)
{
}
//�R���X�g���N�^
Player::Player(float x, float y) : location(x, y), direction(0.0f), radius(15.0f)
{
}
//�R���X�g���N�^
Player::Player(Vector2D location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}
//�f�X�g���N�^
Player::~Player()
{

}
//�v���C���[�̍X�V����
void Player::Update()
{
	Movement();
}
//�v���C���[�̕`�揈��
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);
}
//���W�ݒ菈��
void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}
//���W�ݒ菈��
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}
//���W�擾����
Vector2D Player::GetLocation() const
{
	return location;
}
//���a�擾����
float Player::GetRadius()
{
	return radius;
}
//�ړ�����
void Player::Movement()
{
	if (InputControl::GetKeyDown(KEY_INPUT_W))
	{
		direction.y = -1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_S))
	{
		direction.y = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_D))
	{
		direction.x = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_A))
	{
		direction.x = -1.0f;
	}

	location += direction;
}
