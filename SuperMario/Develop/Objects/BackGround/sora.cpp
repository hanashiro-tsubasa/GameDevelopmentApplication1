#include "Sora.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

Sora::Sora()
{

}

Sora::~Sora()
{

}

void Sora::Initialize()
{

	// 画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	image = rm->GetImages("Resource/Images/sora.png")[0];

}

void Sora::Draw(const Vector2D& screen_offset) const
{
	// オフセット値を基に画像の描画を行う
	Vector2D graph_location = this->location + screen_offset;
	DrawRotaGraphF(graph_location.x, graph_location.y, 1, 0.0, image, TRUE);
}

/// <summary>
/// 当たり判定通知処理
/// </summary>
/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
//void Sora::OnHitCollision(GameObjectBase* hit_object)
//{
//	// 当たったオブジェクトがプレイヤーだったら、削除する
//	if (hit_object->GetCollision().object_type == eObjectType::player)
//	{
//		DestroyObject(this);
//
//	}
//}
