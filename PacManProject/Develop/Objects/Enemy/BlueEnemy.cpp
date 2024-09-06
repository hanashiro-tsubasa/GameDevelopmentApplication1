#include "BlueEnemy.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

BlueEnemy::BlueEnemy()
{

}
	

BlueEnemy::~BlueEnemy()
{

}
void BlueEnemy::Initialize()
{
	direction_state = eEnemyDirectionState::DOWN;
	enemy_type = eEnemyType::BLUE;
	z_layer = 10;
	__super::Initialize();
}

void BlueEnemy::Update(float delta_second)
{

	__super::Update(delta_second);
}

void BlueEnemy::Draw(const Vector2D& screen_offset)const
{
	
	__super::Draw(screen_offset);
}

void BlueEnemy::Finalize()
{
	EnemyBase::Finalize();
}

void BlueEnemy::OnHitCollision(GameObjectBase* hit_object)
{
	EnemyBase::OnHitCollision(hit_object);
}

eEnemyState BlueEnemy::GetEnemyState() const
{
	return EnemyBase::GetEnemyState();
}

bool BlueEnemy::GetDestroy()const
{
	
	return EnemyBase::GetDestroy();
}

void BlueEnemy::Movement(float delta_second)
{
	//EnemyBase::Movement(delta_second);
}

/// <summary>
/// �A�j���[�V��������
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void BlueEnemy::AnimationControl(float delta_second)
{
	// �ړ����̃A�j���[�V����
	animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 2)
		{
			animation_count = 0;
		}
		// �摜�̐ݒ�
		image2 = move_animation[enemy_type * 2 + animation_count];
	}
}