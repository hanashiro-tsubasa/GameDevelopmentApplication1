#pragma once

#include "../../Objects/GameObject.h"

//プレイヤー状態
enum ePlayerState
{
	IDLE,		// 待機状態
	MOVE,		// 移動状態
	JUMP,		// ジャンプ状態
	STAR,		// スター状態
	DIE,		// 死亡状態
};
class Player : public GameObject
{
private:
	//進行方向状態
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NONE,
	};
private:
	std::vector<int> move_animation;
	std::vector<int> jump_animation;
	std::vector<int> star_animation;
	std::vector<int> dying_animation;
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	ePlayerState player_state;				// プレイヤー状態
	eDirectionState now_direction_state;	// 現在進行方向状態
	eDirectionState next_direction_state;	// 次回進行方向状態
	int coin_count=0;							// 取ったコインの数
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字
	bool is_star;						// スターを取ったか？
	bool is_destroy;						// 死んだ状態になったか？

	//移動アニメーションの順番
	const int animation_num[4] = { 3,4,5,4 };

public:
	Player();
	virtual ~Player();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screen_offset) const override;
	virtual void Finalize() override;

	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
	virtual void OnHitCollision(GameObjectBase* hit_object) override;

public:
	/// <summary>
	/// コインを取った数取得
	/// </summary>
	/// <returns>コインを取った数</returns>
	int GetCoinCount() const;

	/// <summary>
	/// プレイヤーの状態を取得する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	ePlayerState GetPlayerState() const;

	/// <summary>
	/// プレイヤーがパワーアップしてるか確認する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	bool GetPowerUp() const;

	/// <summary>
	/// パワーダウンさせる
	/// </summary>
	void SetPowerDown();

	/// <summary>
	/// プレイヤーがパワーアップしてるか確認する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	bool GetDestroy() const;


private:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void Movement(float delta_second);
	/// <summary>
	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void AnimationControl(float delta_second);
};
