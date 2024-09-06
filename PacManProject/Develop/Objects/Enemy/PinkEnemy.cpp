#include "PinkEnemy.h"

PinkEnemy::PinkEnemy()
{

}


PinkEnemy::~PinkEnemy()
{

}
void PinkEnemy::Initialize()
{
	enemy_type = eEnemyType::PINK;
	EnemyBase::Initialize();
}

void PinkEnemy::Update(float delta_second)
{
	EnemyBase::Update(delta_second);
}

void PinkEnemy::Draw(const Vector2D& screen_offset)const
{
	EnemyBase::Draw(screen_offset);
}

void PinkEnemy::Finalize()
{
	EnemyBase::Finalize();
}

void PinkEnemy::OnHitCollision(GameObjectBase* hit_object)
{
	EnemyBase::OnHitCollision(hit_object);
}

eEnemyState PinkEnemy::GetEnemyState() const
{
	return EnemyBase::GetEnemyState();
}

bool PinkEnemy::GetDestroy()const
{

	return EnemyBase::GetDestroy();
}

void PinkEnemy::Movement(float delta_second)
{
	//EnemyBase::Movement(delta_second);
}

void PinkEnemy::AnimationControl(float delta_second)
{
	//EnemyBase::AnimationControl(delta_second);
}
