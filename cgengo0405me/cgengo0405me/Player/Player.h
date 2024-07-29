#pragma once
#include <vector>
#include "State/Enum/PlayerState.h"
#include "../Utility/Vector2D.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player
{
private:
	class PlayerStateBase* state = nullptr;
	ePlayerState next_state = ePlayerState::NONE;
	float g_velocity = 0.0f;
	Vector2D location = Vector2D(0.0f);

public:
	Vector2D velocity = Vector2D(0.0f);
	Vector2D box_size = Vector2D(0.0f);

public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name="init_location">初期座標</param>
	void Initialize(Vector2D init_location = Vector2D(0.0f));

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() const;

public:
	/// <summary>
	/// 次のStateを設定
	/// </summary>
	/// <param name="next_state">次のState</param>
	void SetNextState(ePlayerState next_state);

	/// <summary>
	/// 座標の取得
	/// </summary>
	Vector2D& GetLocation();
};

