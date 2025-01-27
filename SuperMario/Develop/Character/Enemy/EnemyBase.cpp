#include "EnemyBase.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"


#define D_ENEMY_SPEED (50.0f)

EnemyBase::EnemyBase() :
	//image2(),
	move_animation(),
	//eyes_animation(),
	velocity(0.0f),
	enemy_state(eEnemyState::WALK),
	direction_state(eEnemyDirectionState::RIGHT),
	animation_time(0.0f),
	move_animation_time(0.0f),
	animation_count(0),
	m_animation_count(0),
	is_destroy(false)
{

}

EnemyBase::~EnemyBase()
{
}
void EnemyBase::Initialize()
{
	//アニメーション画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm->GetImages("Resource/Images/monster.png", 20, 20, 1, 32, 32);
	//eyes_animation = rm->GetImages("Resource/Images/eyes.png", 4, 4, 1, 32, 32);

	//当たり判定の設定
	collision.is_blocking = true;
	collision.object_type = eObjectType::enemy;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::wall);
	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	//可動性の設定
	mobility = eMobilityType::Movable;
	//image2 = move_animation[enemy_type * 2];
}

void EnemyBase::Update(float delta_second)
{
	//エネミー状態によって、動作を変える

	Movement(delta_second);
	AnimationControl(delta_second);


//	switch (direction_state)//左右上下で目の画像を変える　
//	{
//	case eEnemyDirectionState::UP:
//		animation_count = 0;
//		break;
//	case eEnemyDirectionState::RIGHT:
//		animation_count = 1;
//		break;
//	case eEnemyDirectionState::DOWN:
//		animation_count = 2;
//		break;
//	case eEnemyDirectionState::LEFT:
//		animation_count = 3;
//		break;
//	}
//	image = eyes_animation[animation_count];
}


void EnemyBase::Draw(const Vector2D& screen_offset)const
{
	//Draw(screen_offset);	

	Vector2D graph_location = location + screen_offset;
	//DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, image2, TRUE); //体
	//__super::Draw(screen_offset);												//目
}

void EnemyBase::Finalize()
{
	move_animation.clear();
	//eyes_animation.clear();
}

/// <summary>
/// 当たり判定通知処理
/// </summary>
/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{
	// 当たった、オブジェクトが壁だったら
	if (hit_object->GetCollision().object_type == eObjectType::wall)
	{
		// 当たり判定情報を取得して、カプセルがある位置を求める
		CapsuleCollision hc = hit_object->GetCollision();
		hc.point[0] += hit_object->GetLocation();
		hc.point[1] += hit_object->GetLocation();

		// 最近傍点を求める
		Vector2D near_point = NearPointCheck(hc, this->location);

		// Playerからnear_pointへの方向ベクトルを取得
		Vector2D dv2 = near_point - this->location;
		Vector2D dv = this->location - near_point;

		// めり込んだ差分
		float diff = (this->GetCollision().radius + hc.radius) - dv.Length();

		// diffの分だけ戻る
		location += dv.Normalize() * diff;
	}

}
/// <summary>
/// エネミーの状態を取得する
/// </summary>
/// <returns>エネミーの状態</returns>
eEnemyState EnemyBase::GetEnemyState() const
{
	return enemy_state;
}

EnemyBase::eEnemyDirectionState EnemyBase::GetEnemyDirectionState() const
{
	return direction_state;
}


bool EnemyBase::GetDestroy() const
{
	return is_destroy;
}






void EnemyBase::Movement(float delta_second)
{
	//エネミー状態によって動きを変える
	switch (enemy_state)
	{
	/*case eEnemyState::TUISEKI:
		break;
	case eEnemyState::eIDLE:
		move_animation_time += delta_second;
		if (move_animation_time >= (1.0f / 1.0f))
		{
			move_animation_time = 0.0f;
			if (direction_state == UP)
			{
				direction_state = DOWN;
			}
			else if (direction_state == DOWN)
			{
				direction_state = UP;
			}
		}
		break;
	case eEnemyState::NAWABARI:
		break;*/
	case eEnemyState::WALK:
		break;
	case eEnemyState::eDIE:
		break;

	}


	// 進行方向の移動量を追加
	switch (direction_state)
	{
	
	case EnemyBase::DOWN:
		velocity.y = 1.0f;
		break;
	case EnemyBase::LEFT:
		velocity.x = -1.0f;
		break;
	case EnemyBase::RIGHT:
		velocity.x = 1.0f;
		break;
	default:
		break;
	}
	// 移動量 * 速さ * 時間 で移動先を決定する
	location += velocity * D_ENEMY_SPEED * delta_second;
}

/// <summary>
/// アニメーション制御
/// </summary>
/// <param name="delta_second">1フレームあたりの時間</param>
void EnemyBase::AnimationControl(float delta_second)
{
	// 移動中のアニメーション
	animation_time += delta_second;
	if (animation_time >= (1.0f / 8.0f))
	{
		animation_time = 0.0f;
		m_animation_count++;
		if (m_animation_count >= 2)
		{
			m_animation_count = 0;
		}
		// 画像の設定
		//image2 = move_animation[enemy_type * 2 + m_animation_count];
	}
}

