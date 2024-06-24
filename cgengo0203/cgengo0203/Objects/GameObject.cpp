#include "GameObject.h"
#include "DxLib.h"
//コンストラクタ
GameObject::GameObject() : color(0x0), location(0.0f), box_size(0.0f)
{

}
//デストラクタ
GameObject::~GameObject()
{

}
//ゲームオブジェクトの初期化
void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);

	box_size = Vector2D(32.0f);

	location = box_size;
}
//ゲームオブジェクトの更新処理
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
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color,
		TRUE);
}
//終了処理
void GameObject::Finalize()
{

}
//座標設定
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
	//2
}
//座標取得
Vector2D GameObject::GetLocation()const
{
	return this->location;
}
//大きさを取得
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}

