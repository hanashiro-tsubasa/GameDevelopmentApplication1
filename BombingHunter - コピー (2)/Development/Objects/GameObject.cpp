#include "GameObject.h"
#include "DxLib.h"

//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	radian(0.0),
	vector(0.0f),
	score(0),
	image(NULL),
	sound(NULL),
	deleteflg(FALSE)
{

}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{

}

//更新処理
void GameObject::Update()
{

}

//描画処理
void GameObject::Draw() const
{
	//当たり判定の可視化
#ifdef D_PIVOT_CENTER
	Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#else
	Vector2D tl = location;
	Vector2D br = location + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif // D_PIVOT_CENTER
}

//デリートフラグ取得処理
bool GameObject::GetDeleteFlg()const
{
	return deleteflg;
}

//ショットフラグ取得処理
bool GameObject::GetShotFlg()const
{
	return shotflg;
}

void GameObject::SetBulletVector(const Vector2D& vector)
{
	this->vector = vector;
}


//終了時処理
void GameObject::Finalize()
{

}

//識別番号取得処理
int GameObject::GetSerialNumber() const
{
	return serial_number;
}

int GameObject::GetScore()
{
	return score;
}

//当たり判定通知処理
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//当たった時に行う処理
}
//2
//位置情報取得処理
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//位置情報設定処理
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}

Vector2D GameObject::GetBoxSize() const
{
	return box_size;
}