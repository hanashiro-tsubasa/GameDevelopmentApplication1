#include "BlueEnemy.h"

BlueEnemy::BlueEnemy()
{

}
	

BlueEnemy::~BlueEnemy()
{

}
void BlueEnemy::Initialize()
{
	EnemyBase::Initialize();
}

void BlueEnemy::Update(float delta_second)
{
	EnemyBase::Update(delta_second);
}

void BlueEnemy::Draw(const Vector2D& screen_offset)const
{
	EnemyBase::Draw(screen_offset);
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

void BlueEnemy::AnimationControl(float delta_second)
{
	//EnemyBase::AnimationControl(delta_second);
}
