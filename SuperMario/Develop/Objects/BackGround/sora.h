#pragma once

#include "../GameObject.h"

// 通常餌クラス
class Sora : public GameObject
{
private:

public:
	Sora();
	virtual ~Sora();

	virtual void Initialize() override;
	virtual void Draw(const Vector2D& screen_offset) const override;

	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
	//virtual void OnHitCollision(GameObjectBase* hit_object) override;

};

