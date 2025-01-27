#include "Kuribo.h"

Kuribo::Kuribo()
{

}


Kuribo::~Kuribo()
{

}
void Kuribo::Initialize()
{
	direction_state = eEnemyDirectionState::DOWN;
	enemy_type = eEnemyType::KURIBO;
	EnemyBase::Initialize();
}

void Kuribo::Update(float delta_second)
{
	EnemyBase::Update(delta_second);
}

void Kuribo::Draw(const Vector2D& screen_offset)const
{
	EnemyBase::Draw(screen_offset);
}

void Kuribo::Finalize()
{
	EnemyBase::Finalize();
}

void Kuribo::OnHitCollision(GameObjectBase* hit_object)
{
	EnemyBase::OnHitCollision(hit_object);
}

eEnemyState Kuribo::GetEnemyState() const
{
	return EnemyBase::GetEnemyState();
}

bool Kuribo::GetDestroy()const
{

	return EnemyBase::GetDestroy();
}

void Kuribo::Movement(float delta_second)
{
	//EnemyBase::Movement(delta_second);
}

void Kuribo::AnimationControl(float delta_second)
{
	//EnemyBase::AnimationControl(delta_second);
}
