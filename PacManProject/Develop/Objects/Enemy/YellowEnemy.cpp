#include "YellowEnemy.h"

YellowEnemy::YellowEnemy()
{

}


YellowEnemy::~YellowEnemy()
{

}
void YellowEnemy::Initialize()
{
	direction_state = eEnemyDirectionState::DOWN;
	enemy_type = eEnemyType::YELLOW;
	EnemyBase::Initialize();
}

void YellowEnemy::Update(float delta_second)
{
	EnemyBase::Update(delta_second);
}

void YellowEnemy::Draw(const Vector2D& screen_offset)const
{
	EnemyBase::Draw(screen_offset);
}

void YellowEnemy::Finalize()
{
	EnemyBase::Finalize();
}

void YellowEnemy::OnHitCollision(GameObjectBase* hit_object)
{
	EnemyBase::OnHitCollision(hit_object);
}

eEnemyState YellowEnemy::GetEnemyState() const
{
	return EnemyBase::GetEnemyState();
}

bool YellowEnemy::GetDestroy()const
{

	return EnemyBase::GetDestroy();
}

void YellowEnemy::Movement(float delta_second)
{
	//EnemyBase::Movement(delta_second);
}

void YellowEnemy::AnimationControl(float delta_second)
{
	//EnemyBase::AnimationControl(delta_second);
}
