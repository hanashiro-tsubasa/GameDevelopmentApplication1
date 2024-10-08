#pragma once

#include"../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //位置情報
	Vector2D velocity;  //位置情報
	Vector2D box_size;  //位置情報

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

