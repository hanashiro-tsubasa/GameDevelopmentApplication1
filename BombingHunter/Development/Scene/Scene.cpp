#include "Scene.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Enemy/WingEnemy.h"
#include "../Objects/Enemy/GoldEnemy.h"
#include "../Objects/Enemy/Harpy.h"
#include "../Objects/Bomb/Bomb.h"
#include "../Objects/Enemy/EnemyBullet.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define D_PIVOT_CENTER

Scene::Scene() : objects(),back_ground(NULL),EnemyNumber(),WingEnemyNumber(),GoldEnemyNumber(),HarpyNumber()
{

}


Scene::~Scene()
{
	//解放忘れ防止
	Finalize();
}






//初期化処理
void Scene::Initialize()
{
	//プレイヤーを画面中央あたりに生成する
	CreateObject<Player>(Vector2D(320.0f, 60.0f));
	//背景の読み込み
	back_ground=LoadGraph("Resource/Images/BackGround.png");
	srand((unsigned int)time(NULL));
}


void Scene::Update()
{
	//オブジェクトリスト内のオブジェクトを更新する
	for (GameObject* obj : objects)
	{
		obj->Update();
	}



	//オブジェクト同士の当たり判定チェック
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j<objects.size(); j++)
		{
			//当たり判定チェック処理
			HitCheckObject(objects[i], objects[j]);
		}
	}
	//ランダムでハコ敵を生成する/////////////////
	
	int Createrand = rand() % 100 + 1;
	int GoldCreaterand = rand() % 10000 + 1;
	int HarpyCreaterand = rand() % 2000 + 1;
	
	if (Createrand == 1&&EnemyNumber < 6)//ハコテキの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Enemy>(Vector2D(-40.0f, 400.0f));
		EnemyNumber += 1;
	}
	if (Createrand == 2 && EnemyNumber < 6)//ハコテキの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Enemy>(Vector2D(679.0f, 400.0f));
		EnemyNumber += 1;
	}
	/////////////////////////////////////////////

	//ランダムでハネ敵を生成する/////////////////


	if (Createrand == 3 && WingEnemyNumber < 6)//ハネテキの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{ 
		CreateObject<WingEnemy>(Vector2D(-40.0f, 150.0f+rand()%150));
		WingEnemyNumber += 1;
	}
	if (Createrand == 4 && WingEnemyNumber < 6)//ハネテキの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<WingEnemy>(Vector2D(679.0f, 150.0f+rand()%150));
		WingEnemyNumber += 1;
	}
	/////////////////////////////////////////////

	//ランダムで金の敵を生成する/////////////////


	if (GoldCreaterand == 5 && GoldEnemyNumber < 1)//金テキの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<GoldEnemy>(Vector2D(-40.0f, 420.0f));
		GoldEnemyNumber += 1;
	}
	if (GoldCreaterand == 6 && GoldEnemyNumber < 1)//金テキの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<GoldEnemy>(Vector2D(679.0f, 420.0f));
		GoldEnemyNumber += 1;
	}
	/////////////////////////////////////////////

	//ランダムでハーピーを生成する/////////////////


	if (HarpyCreaterand == 7 && HarpyNumber < 2)//ハーピーの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Harpy>(Vector2D(-40.0f, 150.0f + rand() % 150));
		HarpyNumber += 1;
	}
	if (HarpyCreaterand == 8 && HarpyNumber < 2)//ハーピーの一度の生成上限数) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Harpy>(Vector2D(679.0f, 150.0f + rand() % 150));
		HarpyNumber += 1;
	}
	/////////////////////////////////////////////


	

	//スペースキーを押したらボムを生成する//////
	if (InputControl::GetKeyDown(KEY_INPUT_SPACE)||GetMouseInput())
	{
		CreateObject<Bomb>(Vector2D(objects[0]->GetLocation().x, objects[0]->GetLocation().y + 70.0f));
	}
	////////////////////////////////////////////


	
	//生成されたオブジェクトをすべて見る
	for (int i = 0; i < objects.size(); i++)
	{
		//もしショットフラグがTRUEになったら
		if(objects[i]->GetShotFlg() == TRUE)
		{
			CreateObject<EnemyBullet>(Vector2D(objects[i]->GetLocation()));
		}

		//もしデリートフラグがTRUEになったら
		if (objects[i]->GetDeleteFlg() == TRUE)
		{
			//ハコテキが消えたらEnemyNumberを減らす
			if (objects[i]->GetSerialNumber()==2)
			{
				EnemyNumber -= 1;
			}
			//ハネテキが消えたらWingEnemyNumberを減らす
			if (objects[i]->GetSerialNumber() == 4)
			{
				WingEnemyNumber -= 1;
			}
			//金テキが消えたらGoldEnemyNumberを減らす
			if (objects[i]->GetSerialNumber() == 5)
			{
				GoldEnemyNumber -= 1;
			}
			//ハーピーが消えたらHarpyNumberを減らす
			if (objects[i]->GetSerialNumber() == 6)
			{
				HarpyNumber -= 1;
			}
			
			//デリートフラグがTRUEになったオブジェクトを消す
			objects.erase(objects.begin() + i);
		}
	}
	
}


void Scene::Draw()const
{
	//背景の描画
    DrawExtendGraph(0, 0,640,480, back_ground, TRUE);
	//オブジェクトリスト内のオブジェクトを描画する
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
	DrawFormatString(50, 50, 0x000000, "%d", EnemyNumber);
	
	DrawFormatString(70, 50, 0x000000, "%d", WingEnemyNumber);

	DrawFormatString(90, 50, 0x000000, "%d", GoldEnemyNumber);

	DrawFormatString(110, 50, 0x000000, "%d", HarpyNumber);
}

//2
void Scene::Finalize()
{
	//オブジェクトリスト内が空なら処理を終了する
	if (objects.empty())
		
	{
		return;
	}

	//オブジェクトリスト内のオブジェクトを解放する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//動的に確保したリストを開放する
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//当たり判定チェック処理（矩形の中心で当たり判定を取る）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//当たったことをオブジェクトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);

	}
}
//3
#else

//当たり判定チェック処理（左上頂点の座標から当たり判定計算を行う）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右下頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//矩形Aと矩形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVOT_CNETER