#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"

enum eEnemyState
{
	TUISEKI,     //追跡状態
	NAWABARI,    //ナワバリ状態
	EYE,         //目玉状態
	IJIKE,       //イジケ状態
};

class EnemyBase : public GameObject
{
protected:

private:
	//進行方向状態
	enum eEnemyDirectionState : unsigned char {
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};

	std::vector<int>move_animation;     //移動のアニメーション
	std::vector<int>eyes_animation;     //死亡のアニメーション
	Vector2D location;                  //位置
	Vector2D velocity;                  //移動量
	eEnemyState enemy_state;            //エネミー状態
	eEnemyDirectionState direction_state;    //進行方向情報
	float animation_time;               //アニメーション時間
	int animation_count;                //アニメーション添え字
	bool is_destroy;                    //死んだ状態になったか？
	
	//移動アニメーションの順番
	const int animation_num[2] = { 1,2 };
public:

	

	EnemyBase();
	virtual ~EnemyBase();

	virtual void Initialize()override;
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