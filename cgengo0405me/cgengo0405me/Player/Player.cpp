#include "Player.h"

#include <cmath>

#include "DxLib.h"
#include "State/Factory/PlayerStateFactory.h"

#define D_GRAVITY (9.807f)  //�d�͉����x(m/ss)

/// <summary>
/// ����������
/// </summary>
/// <param name="init_location">�������W</param>
void Player::Initialize(Vector2D init_location)
{
	state = PlayerStateFactory::Get((*this), ePlayerState::IDLE);
	next_state = ePlayerState::NONE;
	g_velocity = 0.0f;
	location = init_location;
	velocity = Vector2D(0.0f);
}

/// <summary>
/// �I������
/// </summary>
void Player::Finalize()
{
	PlayerStateFactory::Finalize();
}

/// <summary>
/// �I������
/// </sumary>
void Player::Update()
{
	//state�̕ύX����
	if (next_state != ePlayerState::NONE)
	{
		state = PlayerStateFactory::Get((*this), next_state);
		next_state = ePlayerState::NONE;
	}

	//�d�͑��x�̌v�Z
	g_velocity += D_GRAVITY / 444.0f;
	velocity.y += g_velocity;

	//��ԕʂ̍X�V�������s��
	state->Update();
	//2
	//�ړ��̎��s
	location += velocity;

	//400.0f�n�_��n�ʂƉ���
	if (400.0f < location.y)
	{
		location.y = 400.0f;
		g_velocity = 0.0f;
		velocity.y = 0.0f;
	}
}

/// <summary>
/// �`�揈��
/// </summary>
void Player::Draw() const
{
	//��ԕʂ̕`�揈�����s��
	state->Draw();
}

/// <summary>
/// ����State��ݒ�
/// </summary>
/// <param name="next_state">����State</param
void Player::SetNextState(ePlayerState next_state)
{
	this->next_state = next_state;
}

/// <summary>
/// ���W�̎擾
/// </summary>
Vector2D& Player::GetLocation()
{
	return this->location;
}
