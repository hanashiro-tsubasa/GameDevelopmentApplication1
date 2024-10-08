#pragma once
#include "PlayerStateBase.h"
#include "../../Utility/Vector2D.h"

/// <summary>
/// 移動状態
/// </summary>
class RunningState : public PlayerStateBase
{
private:
	//前フレームの座標情報
	Vector2D old_location;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="p">プレイヤー情報</param>
	RunningState(class Player* p);

	//デストラクタ
	virtual ~RunningState();

public:
	//初期化処理関数
	virtual void Initialize() override;

	//終了処理関数
	virtual void Finalize() override;

	//更新処理
	virtual void Update() override;

	//描画処理
	virtual void Draw() const override;

	//状態の取得
	virtual ePlayerState GetState() const override;
};
