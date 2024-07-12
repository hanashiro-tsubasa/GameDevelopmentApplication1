#pragma once

#include "../GameObject.h"

class EnemyBase : public GameObject
{
protected:

public:

	

	
	virtual void OnHitCollision(GameObjectBase* hit_object)override;

	void Finalize()override;

	virtual void Draw(const Vector2D& screen_ofset)const override;

	void Update(float)override;

	void Initialize()override;

	EnemyBase();
	virtual ~EnemyBase();

private:
	float Movement(float);
};