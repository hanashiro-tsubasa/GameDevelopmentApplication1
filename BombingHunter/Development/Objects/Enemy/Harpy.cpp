#include "Harpy.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



Harpy::Harpy() : animation_count(0), direction(0.0f), EnemySpeed(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

Harpy::~Harpy()
{

}

//初期化処理
void Harpy::Initialize()
{
	serial_number = 6;
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/Harpy/1.png");
	animation[1] = LoadGraph("Resource/Images/Harpy/2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハーピーの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = animation[0];
	//敵のスピードの設定
	EnemySpeed = (rand() % 4 + 1);

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
void Harpy::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();

	if (location.x > 680 || location.x < -50)
	{
		deleteflg = TRUE;
	}
}
//2
//描画処理
void Harpy::Draw() const
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

	//情報をもとにハーピー画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了時処理
void Harpy::Finalize()
{
	//使用した画像を開放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Harpy::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	//direction = 1.0f;
	if (hit_object->GetSerialNumber() == 3)
	{
		deleteflg = TRUE;
	}
}

//移動処理
void Harpy::Movement()
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
void Harpy::AnimationControl()
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
		else
		{
			image = animation[0];
		}
	}
}
