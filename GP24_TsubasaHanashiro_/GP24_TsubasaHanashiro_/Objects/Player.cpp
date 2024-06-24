#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
//コンストラクタ
Player::Player() : location(), direction(0.0f), radius(15.0f)
{
}
//コンストラクタ
Player::Player(float x, float y) : location(x, y), direction(0.0f), radius(15.0f)
{
}
//コンストラクタ
Player::Player(Vector2D location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}
//デストラクタ
Player::~Player()
{

}
//プレイヤーの更新処理
void Player::Update()
{
	Movement();
}
//プレイヤーの描画処理
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);
}
//座標設定処理
void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}
//座標設定処理
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}
//座標取得処理
Vector2D Player::GetLocation() const
{
	return location;
}
//半径取得処理
float Player::GetRadius()
{
	return radius;
}
//移動処理
void Player::Movement()
{
	if (InputControl::GetKeyDown(KEY_INPUT_W))
	{
		direction.y = -1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_S))
	{
		direction.y = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_D))
	{
		direction.x = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_A))
	{
		direction.x = -1.0f;
	}

	location += direction;
}
