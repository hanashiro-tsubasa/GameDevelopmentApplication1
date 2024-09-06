#pragma once

#include"../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //ˆÊ’uî•ñ
	Vector2D velocity;  //ˆÊ’uî•ñ
	Vector2D box_size;  //ˆÊ’uî•ñ

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

