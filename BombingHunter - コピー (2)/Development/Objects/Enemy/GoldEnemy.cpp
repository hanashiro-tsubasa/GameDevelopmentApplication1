#include "GoldEnemy.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



GoldEnemy::GoldEnemy() : animation_count(0), direction(0.0f), EnemySpeed(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	animation[4] = NULL;
}

GoldEnemy::~GoldEnemy()
{

}

//初期化処理
void GoldEnemy::Initialize()
{
	score = 1000;
	serial_number = 5;
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/GoldEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/GoldEnemy/2.png");
	animation[2] = LoadGraph("Resource/Images/GoldEnemy/3.png");
	animation[3] = LoadGraph("Resource/Images/GoldEnemy/4.png");
	animation[4] = LoadGraph("Resource/Images/GoldEnemy/5.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1 || animation[2] == -1 || animation[3] == -1 || animation[4] == -1)
	{
		throw("金テキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = animation[0];
	//敵のスピードの設定
	EnemySpeed = 1;

	//初期進行方向の設定
	if (location.x < 41.0f)
	{
		direction = Vector2D(EnemySpeed, 0.0f /*-0.5f*/);
	}
	else
	{
		direction = Vector2D(EnemySpeed * -1, 0.0f);
	}
}

//更新処理
void GoldEnemy::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();

	/*int ShotCreaterand = rand() % 100 + 1;
	if (ShotCreaterand == 1)
	{
		shotflg = TRUE;
	}
	else
	{
		shotflg = FALSE;
	}*/

	if (location.x > 680 || location.x < -50)
	{
		deleteflg = TRUE;
	}
}
//2
//描画処理
void GoldEnemy::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;

	//進行方向によって、反転状態を決定する
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//情報をもとに金のテキ画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.7, 0.0, image, TRUE, flip_flag);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了時処理
void GoldEnemy::Finalize()
{
	//使用した画像を開放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
}

//当たり判定通知処理
void GoldEnemy::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	//direction = 1.0f;
	if (hit_object->GetSerialNumber() == 3)
	{
		deleteflg = TRUE;
	}
}

//移動処理
void GoldEnemy::Movement()
{
	//画面端に到達したら、進行方向を反転する
	//if (((location.x + direction.x) < box_size.x) ||
	//	(640.0f - box_size.x) < (location.x + direction.x))
	//{
	//	direction.x *= -1.0f;
	//}
	////2
	//if (((location.y + direction.y) < box_size.y) ||
	//	(480.0f - box_size.y) < (location.y + direction.y))
	//{
	//	direction.y *= -1.0f;
	//}

	//進行方向に向かって、位置座標を変更する

	location += direction;

}

//アニメーション制御
void GoldEnemy::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//30フレーム目に到達したら
	if (animation_count >= 30)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			image = animation[1];
		}
		else if (image == animation[1])
		{
			image = animation[2];
		}
		else if (image == animation[2])
		{
			image = animation[3];
		}
		else if (image == animation[3])
		{
			image = animation[4];
		}
		else
		{
			image = animation[0];
		}
	}
}
