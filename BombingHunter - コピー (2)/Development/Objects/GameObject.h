#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER //座標の原点を画像の中心にする

//ゲームオブジェクト基礎クラス
class GameObject
{
protected:
	Vector2D location;      //位置情報
	Vector2D box_size;      //矩形の大きさ
	Vector2D vector;        //移動方向
	double radian;          //向き
	int image;              //画像
	int sound;              //音源
	bool deleteflg;         //デリートフラグ
	bool hitflg;            //当たったかフラグ
	bool shotflg;           //ショットフラグ
	int score;              //合計スコア
	int serial_number;      //識別番号

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();    //初期化処理
	virtual void Update();        //更新処理
	virtual void Draw() const;    //描画処理
	virtual void Finalize();      //終了時処理
	int GetSerialNumber() const;  //識別番号取得処理
	int GetScore();               //スコア取得処理

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object);

	//位置情報取得処理
	Vector2D GetLocation() const;
	//デリートフラグ取得処理
	bool GetDeleteFlg() const;
	//ショットフラグ取得処理
	bool GetShotFlg() const;
	//敵弾角度取得
	void SetBulletVector(const	Vector2D& vector);

	//位置情報変更処理
	void SetLocation(const Vector2D& location);

	//当たり判定の大きさを取得する
	Vector2D GetBoxSize() const;
};

