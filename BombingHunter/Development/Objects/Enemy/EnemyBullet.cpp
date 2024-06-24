#include "EnemyBullet.h"
#include "DxLib.h"


EnemyBullet::EnemyBullet() : animation_count(0), BombSpeed(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
}

EnemyBullet::~EnemyBullet()
{

}

//初期化処理
void EnemyBullet::Initialize()
{
	serial_number = 7;
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/EnemyBullet/1.png");
	animation[1] = LoadGraph("Resource/Images/EnemyBullet/eff1.png");
	animation[2] = LoadGraph("Resource/Images/EnemyBullet/eff2.png");
	animation[3] = LoadGraph("Resource/Images/EnemyBullet/eff3.png");

	//エラーチェック
	if (animation[0] == -1)
	{
		throw("テキ弾の画像がありません\n");
	}
	if (animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	{
		throw("テキの画像がありません\n");
	}

	//向きの設定
	//radian = 1.57f;

	//当たり判定の大きさを設定
	box_size = 10.0f;

	//初期画像の設定
	image = animation[0];

	//爆弾のスピードの設定
	BombSpeed = 1.0f;
}

//更新処理
void EnemyBullet::Update()
{


	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();

	//画像制御
	if (location.y < -20)
	{
		hitflg = TRUE;
		box_size = 0.00f;
		BombSpeed = 0.0f;
	}

}

//描画処理
void EnemyBullet::Draw() const
{
	//情報をもとに爆弾を描画する
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了時処理
void EnemyBullet::Finalize()
{
	//使用した画像を開放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//当たり判定通知処理
void EnemyBullet::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理

	if (hit_object->GetSerialNumber() == 1)
	{
		hitflg = TRUE;
		box_size = 0.00f;
		BombSpeed = 0.0f;
	}
}

//移動処理
void EnemyBullet::Movement()
{
	location.y -= BombSpeed;
}

//アニメーション制御
void EnemyBullet::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//10フレーム目に到達したら
	if (animation_count >= 10 && hitflg == TRUE)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			BombSpeed = 0;
			radian = 0.0f;
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
			deleteflg = TRUE;
		}
	}
}
	
