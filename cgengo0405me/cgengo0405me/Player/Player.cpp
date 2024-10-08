#include "Player.h"

#include <cmath>

#include "DxLib.h"
#include "State/Factory/PlayerStateFactory.h"

#define D_GRAVITY (9.807f)  //重力加速度(m/ss)

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="init_location">初期座標</param>
void Player::Initialize(Vector2D init_location)
{
	state = PlayerStateFactory::Get((*this), ePlayerState::IDLE);
	next_state = ePlayerState::NONE;
	g_velocity = 0.0f;
	location = init_location;
	velocity = Vector2D(0.0f);
}

/// <summary>
/// 終了処理
/// </summary>
void Player::Finalize()
{
	PlayerStateFactory::Finalize();
}

/// <summary>
/// 終了処理
/// </sumary>
void Player::Update()
{
	//stateの変更処理
	if (next_state != ePlayerState::NONE)
	{
		state = PlayerStateFactory::Get((*this), next_state);
		next_state = ePlayerState::NONE;
	}

	//重力速度の計算
	g_velocity += D_GRAVITY / 444.0f;
	velocity.y += g_velocity;

	//状態別の更新処理を行う
	state->Update();
	//2
	//移動の実行
	location += velocity;

	//400.0f地点を地面と仮定
	if (400.0f < location.y)
	{
		location.y = 400.0f;
		g_velocity = 0.0f;
		velocity.y = 0.0f;
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() const
{
	//状態別の描画処理を行う
	state->Draw();
}

/// <summary>
/// 次のStateを設定
/// </summary>
/// <param name="next_state">次のState</param
void Player::SetNextState(ePlayerState next_state)
{
	this->next_state = next_state;
}

/// <summary>
/// 座標の取得
/// </summary>
Vector2D& Player::GetLocation()
{
	return this->location;
}
