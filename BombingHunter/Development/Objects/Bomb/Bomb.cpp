#include "Bomb.h"
#include "DxLib.h"


Bomb::Bomb() : animation_count(0),BombSpeed(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
}

Bomb::~Bomb()
{

}

//初期化処理
void Bomb::Initialize()
{
	serial_number = 3;
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/Bomb/Bomb.png");
	animation[1] = LoadGraph("Resource/Images/Blast/1.png");
	animation[2] = LoadGraph("Resource/Images/Blast/2.png");
	animation[3] = LoadGraph("Resource/Images/Blast/3.png");

	//エラーチェック
	if (animation[0] == -1)
	{
		throw("爆弾の画像がありません\n");
	}
	if (animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	{
		throw("爆風の画像がありません\n");
	}

	//向きの設定
	radian = 1.57f;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = animation[0];

	//爆弾のスピードの設定
	BombSpeed = 3.0f;
}

//更新処理
void Bomb::Update()
{

	
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();

	//画像制御
    if (location.y > 410)
	{
		hitflg = TRUE;
		box_size = 0.00f;
		BombSpeed = 0.0f;
	}
	
}

//描画処理
void Bomb::Draw() const
{
	//情報をもとに爆弾を描画する
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了時処理
void Bomb::Finalize()
{
	//使用した画像を開放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//当たり判定通知処理
void Bomb::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	
	if (hit_object->GetSerialNumber() != 3)
	{
		hitflg = TRUE;
		box_size = 0.00f;
		BombSpeed = 0.0f;
	}
}

//移動処理
void Bomb::Movement()
{
	location.y += BombSpeed;
}

//アニメーション制御
void Bomb::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//10フレーム目に到達したら
	if (animation_count >= 10&&hitflg==TRUE)
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
		else if(image==animation[1])
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