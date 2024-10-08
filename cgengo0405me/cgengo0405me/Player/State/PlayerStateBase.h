#pragma once
#include "Enum/PlayerState.h"

/// <summary>
/// プレイヤー状態管理用のベースクラス
/// </summary>
class PlayerStateBase
{
protected:
	//プレイヤー状態
	class Player* player;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="p">プレイヤー情報</param>
	PlayerStateBase(class Player* p) : player(p)
	{
	}

	//デストラクタ
	virtual ~PlayerStateBase() = default;

public:
	//初期化処理関数
	virtual void Initialize() = 0;

	//終了時処理関数
	virtual void Finalize() = 0;

	//更新処理
	virtual void Update() = 0;

	//描画処理
	virtual void Draw() const = 0;

	//状態の取得
	virtual ePlayerState GetState() const = 0;
};

