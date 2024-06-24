#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	int image;            //描画する画像データ
	Vector2D location;    //位置座標情報
	Vector2D box_size;    //矩形の大きさ

public:
	GameObject();
	virtual ~GameObject();

	//初期化処理
	virtual void Initialize();
	//更新処理
	virtual void Update();
	//描画処理
	virtual void Draw() const;
	//終了時処理
	virtual void Finalize();

public:
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;  //座標取得処理
	Vector2D GetBoxSize() const;   //当たり判定処理

};

