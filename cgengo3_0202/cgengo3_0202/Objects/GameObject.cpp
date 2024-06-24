#include "GameObject.h"
#include "DxLib.h"
//コンストラクタ
GameObject::GameObject() : color(0x0), location(), box_size()
{

}
//デストラクタ
GameObject::~GameObject()
{

}
//ゲームオブジェクトの初期化
void GameObject::Initialize()
{
	location = Vector2D(32.0f, 24.0f);

	box_size = Vector2D(32.0f, 24.0f);

	color = GetColor(0, 255, 0);
}
//ゲームオブジェクトのアップデート
void GameObject::Update()
{
	location += 0.1f;
}
//ゲームオブジェクトの描画
void GameObject::Draw() const
{
	Vector2D tl = this->location - (this->box_size / 2.0f);
	Vector2D br = this->location + (this->box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, color, TRUE);
}
//ゲームオブジェクトの終了処理
void GameObject::Finalize()
{

}
//位置情報の設定
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}
//位置情報の取得
Vector2D GameObject::GetLocation() const
{
	return this->location;
}
//ボックスの大きさを取得
//2
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}