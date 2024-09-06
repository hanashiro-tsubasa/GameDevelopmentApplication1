#pragma once

#include"../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //�ʒu���
	Vector2D velocity;  //�ʒu���
	Vector2D box_size;  //�ʒu���

public:
	Player();
	~Player();

public:
	void Initialize();
	void Update(float delta_second);
	void Draw() const;
	void Finalize();

public:
	void Movement(float param);
};

