#include "RedEnemy.h"

RedEnemy::RedEnemy()
{

}


RedEnemy::~RedEnemy()
{

}
void RedEnemy::Initialize()
{
	EnemyBase::Initialize();
}

void RedEnemy::Update(float delta_second)
{
	EnemyBase::Update(delta_second);
}

void RedEnemy::Draw(const Vector2D& screen_offset)const
{
	EnemyBase::Draw(screen_offset);
}

void RedEnemy::Finalize()
{
	EnemyBase::Finalize();
}

void RedEnemy::OnHitCollision(GameObjectBase* hit_object)
{
	EnemyBase::OnHitCollision(hit_object);
}

eEnemyState RedEnemy::GetEnemyState() const
{
	return EnemyBase::GetEnemyState();
}

bool RedEnemy::GetDestroy()const
{

	return EnemyBase::GetDestroy();
}

void RedEnemy::Movement(float delta_second)
{
	//EnemyBase::Movement(delta_second);
}

void RedEnemy::AnimationControl(float delta_second)
{
	//EnemyBase::AnimationControl(delta_second);
}
