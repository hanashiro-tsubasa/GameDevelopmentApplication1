#include "Player.h"
#include "../Utility/InputEventManager.h"
#include "DxLib.h"

Player::Player()
	: location(0.0f)
	, velocity(0.0f)
	, box_size(0.0f)
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	location = Vector2D(320.0f, 400.0f);
	velocity = 0.0f;
	box_size = 32.0f;

	//入力イベントの登録
	InputEventManager* input_event = InputEventManager::GetInstance();
	input_event->ActionKeyBind(KEY_INPUT_LEFT, -1.0f, this, &Player::Movement);
	input_event->ActionKeyBind(KEY_INPUT_RIGHT, 1.0f, this, &Player::Movement);
}

void Player::Update(float delta_second)
{
	//移動量分だけずらす
	location += velocity * delta_second;

	//画面外に行かないようにする
	if (location.x >= 640.0f)
	{
		location.x = 640.0f;
		velocity.x = 0.0f;
	}
	if (location.x < 0.0f)
	{
		location.x = 0.0f;
		velocity.x = 0.0f;
	}

}

void Player::Draw() const
{
	Vector2D tl = location - (box_size * 0.5f);
	Vector2D br = tl + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), TRUE);
}

void Player::Finalize()
{

}

void Player::Movement(float param)
{
	velocity.x += param;
}

