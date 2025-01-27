#pragma once

#include "EnemyBase.h"



class Kuribo : public EnemyBase
{
public:

	Kuribo();
	~Kuribo();

	virtual void Initialize() override;
	virtual void Update(float)override;
	virtual void Draw(const Vector2D& screen_offset)const override;
	virtual void Finalize()override;

	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
	virtual void OnHitCollision(GameObjectBase* hit_object)override;

	/// <summary>
	/// エネミーの状態を取得する
	/// </summary>
	/// <returns>エネミーの状態</returns>
	eEnemyState GetEnemyState() const; //

	/// <summary>
	/// エネミーが死んだ状態か確認する
	/// </summary>
	/// <returns>エネミーの状態</returns>
	bool GetDestroy() const; //



private:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="">1フレームあたりの時間</param>
	/// <returns></returns>
	void Movement(float delta_second);

	/// <summary>
	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void AnimationControl(float delta_second);

};
