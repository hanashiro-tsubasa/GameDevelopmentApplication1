#include "GameObject.h"
#include"../Utility/ResourceManager.h"
#include "DxLib.h"

//コンストラクタ
GameObject::GameObject() : image(NULL), location(0.0f), box_size(0.0f)
{

}

//デストラクタ
GameObject::~GameObject()
{

}
//初期化処理
void GameObject::Initialize()
{
	image = NULL;

	box_size = Vector2D(32.0f);

	location = box_size;
}
//更新処理
void GameObject::Update()
{
	location.x += 1.0f;

	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}
//描画処理
void GameObject::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y,
		GetColor(255, 0, 0), TRUE);
}
//終了時処理
void GameObject::Finalize()
{

}
//2
//位置情報の設定
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

//位置情報を取得する
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//矩形の大きさを取得する
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}