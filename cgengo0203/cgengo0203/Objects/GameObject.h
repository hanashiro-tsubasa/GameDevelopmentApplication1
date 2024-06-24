#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;    //色
	Vector2D location;     //座標
	Vector2D box_size;     //大きさ

public:
	GameObject();             //コンストラクタ
	virtual ~GameObject();    //デストラクタ

	virtual void Initialize();//初期化処理
	virtual void Update();    //更新処理
	virtual void Draw() const;//描画処理
	virtual void Finalize();  //終了処理

public:
	void SetLocation(Vector2D location);  //座標の設定
	Vector2D GetLocation() const;         //座標の取得
	Vector2D GetBoxSize() const;          //大きさの取得
};

