#include "Nokonoko.h"

Nokonoko::Nokonoko()
{

}


Nokonoko::~Nokonoko()
{

}
void Nokonoko::Initialize()
{
	direction_state = eEnemyDirectionState::DOWN;
	enemy_type = eEnemyType::NOKONOKO
		;
	EnemyBase::Initialize();
}

void Nokonoko::Update(float delta_second)
{
	EnemyBase::Update(delta_second);
}

void Nokonoko::Draw(const Vector2D& screen_offset)const
{
	EnemyBase::Draw(screen_offset);
}

void Nokonoko::Finalize()
{
	EnemyBase::Finalize();
}

void Nokonoko::OnHitCollision(GameObjectBase* hit_object)
{
	EnemyBase::OnHitCollision(hit_object);
}

eEnemyState Nokonoko::GetEnemyState() const
{
	return EnemyBase::GetEnemyState();
}

bool Nokonoko::GetDestroy()const
{

	return EnemyBase::GetDestroy();
}

void Nokonoko::Movement(float delta_second)
{
	//EnemyBase::Movement(delta_second);
}

void Nokonoko::AnimationControl(float delta_second)
{
	//EnemyBase::AnimationControl(delta_second);
}
