#include "InGameScene.h"
/*#include "../../Objects/Player/Player.h"
#include "../../Objects/Enemy/EnemyBase.h"
#include "../../Objects/Enemy/RedEnemy.h"
#include "../../Objects/Enemy/PinkEnemy.h"
#include "../../Objects/Enemy/BlueEnemy.h"
#include "../../Objects/Enemy/YellowEnemy.h"
#include "../../Objects/Wall/Wall.h"
#include "../../Objects/Food/Food.h"
#include "../../Objects/Food/PowerFood.h"*/
#include"../../Character/Enemy/Kuribo.h"
#include"../../Character/Enemy/Nokonoko.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "../../Objects/Item/Coin.h"
#include "../../Objects/BackGround/sora.h"
#include "DxLib.h"
#include <fstream>
#define STAGE_WIDTH  (32*211)
#define STAGE_HEIGHT (32*15)
#define MAPCHIP_WIDTH (32)
#define MAPCHIP_HEIGHT (32)
#define MAP_SIZE_WIDTH (STAGE_WIDTH/MAPCHIP_WIDTH)
#define MAP_SIZE_HEIGHT (STAGE_HEIGHT/MAPCHIP_HEIGHT)




InGameScene::InGameScene()
	: player(nullptr)
	, back_ground_image(NULL)
	, back_ground_sound(NULL)
	, sora(NULL)
	, image(NULL)
	, draw_x(400)
	, draw_y(-200)
	//, img_num()
	, image_data()
	, pause_flag(false)
{

}

InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{
	
	std::vector<int> data(15, NULL);
	image_data = std::vector<std::vector<int>>(211, data);

	ResourceManager* rm = ResourceManager::GetInstance();
	/*image_data[0] = rm->GetImages("Resource/Images/cloud1.png", 1, 1, 1, 32, 32)[0];
	image_data[1] = rm->GetImages("Resource/Images/cloud2.png", 1, 1, 1, 32, 32)[0];
	image_data[2] = rm->GetImages("Resource/Images/cloud3.png", 1, 1, 1, 32, 32)[0];
	image_data[3] = rm->GetImages("Resource/Images/cloud4.png", 1, 1, 1, 32, 32)[0];
	image_data[4] = rm->GetImages("Resource/Images/cloud5.png", 1, 1, 1, 32, 32)[0];
	image_data[5] = rm->GetImages("Resource/Images/cloud6.png", 1, 1, 1, 32, 32)[0];
	image_data[6] = rm->GetImages("Resource/Images/dokan_left_down.png", 1, 1, 1, 32, 32)[0];
	image_data[7] = rm->GetImages("Resource/Images/dokan_left_up.png", 1, 1, 1, 32, 32)[0];
	image_data[8] = rm->GetImages("Resource/Images/dokan_right_down.png", 1, 1, 1, 32, 32)[0];
	image_data[9] = rm->GetImages("Resource/Images/dokan_right_up.png", 1, 1, 1, 32, 32)[0];
	image_data[10] = rm->GetImages("Resource/Images/ha0.png", 1, 1, 1, 32, 32)[0];
	image_data[11] = rm->GetImages("Resource/Images/ha1.png", 1, 1, 1, 32, 32)[0];
	image_data[12] = rm->GetImages("Resource/Images/ha2.png", 1, 1, 1, 32, 32)[0];
	image_data[13] = rm->GetImages("Resource/Images/mountain_left.png", 1, 1, 1, 32, 32)[0];
	image_data[14] = rm->GetImages("Resource/Images/mountain_right.png", 1, 1, 1, 32, 32)[0];
	image_data[15] = rm->GetImages("Resource/Images/mountain_surface.png", 1, 1, 1, 32, 32)[0];
	image_data[16] = rm->GetImages("Resource/Images/mountain_surface1.png", 1, 1, 1, 32, 32)[0];
	image_data[17] = rm->GetImages("Resource/Images/mountain_surface2.png", 1, 1, 1, 32, 32)[0];
	image_data[18] = rm->GetImages("Resource/Images/mountain_up.png", 1, 1, 1, 32, 32)[0];
	image_data[19] = rm->GetImages("Resource/Images/pole.png", 1, 1, 1, 32, 32)[0];
	image_data[20] = rm->GetImages("Resource/Images/pole_down.png", 1, 1, 1, 32, 32)[0];
	image_data[21] = rm->GetImages("Resource/Images/siro1.png", 1, 1, 1, 32, 32)[0];
	image_data[22] = rm->GetImages("Resource/Images/sora.png", 1, 1, 1, 32, 32)[0];
	image_data[23] = rm->GetImages("Resource/Images/yokodokan_left_down.png", 1, 1, 1, 32, 32)[0];
	image_data[24] = rm->GetImages("Resource/Images/yokodokan_left_up.png", 1, 1, 1, 32, 32)[0];
	image_data[25] = rm->GetImages("Resource/Images/yokodokan_middle_down.png", 1, 1, 1, 32, 32)[0];
	image_data[26] = rm->GetImages("Resource/Images/yokodokan_middle_up.png", 1, 1, 1, 32, 32)[0];
	image_data[27] = rm->GetImages("Resource/Images/yokodokan_right_down.png", 1, 1, 1, 32, 32)[0];
	image_data[28] = rm->GetImages("Resource/Images/yokodokan_right_up.png", 1, 1, 1, 32, 32)[0];
	image_data[29] = rm->GetImages("Resource/Images/Block/blackblock.png", 1, 1, 1, 32, 32)[0];
	image_data[30] = rm->GetImages("Resource/Images/Block/bloak_1.png", 1, 1, 1, 32, 32)[0];
	image_data[31] = rm->GetImages("Resource/Images/Block/block.png", 1, 1, 1, 32, 32)[0];
	image_data[32] = rm->GetImages("Resource/Images/Block/floor.png", 1, 1, 1, 32, 32)[0];
	image_data[33] = rm->GetImages("Resource/Images/Block/hatena.png", 1, 1, 1, 32, 32)[0];
	image_data[34] = rm->GetImages("Resource/Images/Block/kai_block.png", 1, 1, 1, 32, 32)[0];
	image_data[35] = rm->GetImages("Resource/Images/Block/kara_block.png", 1, 1, 1, 32, 32)[0];
	image_data[36] = rm->GetImages("Resource/Images/Block/tika_floor.png", 1, 1, 1, 32, 32)[0];
	image_data[37] = rm->GetImages("Resource/Images/Item/coin.png", 1, 1, 1, 32, 32)[0];*/

	//sora = rm->GetImages("Resource/Images/sora.png")[0];
	
	// マップデータ読み込み生成処理
	LoadStageMapCSV();
	LoadStageMapFoodsCSV();

	// スクリーンオフセットを設定
	screen_offset.y = D_OBJECT_SIZE * 3.0f;

	// 背景画像の読み込み
	//ResourceManager* rm = ResourceManager::GetInstance();
	//back_ground_image = rm->GetImages("Resource/Images/map.png")[0];
	// BGMの読み込み
	back_ground_sound = rm->GetSounds("Resource/Sounds/BGM_MarioGround.wav");
	//generate_location = (Vector2D((float)(spos_x + 10 /*- 1*/), (float)(spos_y /*- 1*/)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
	player = CreateObject<Player>(Vector2D(100,320));
	// 背景画像の描画
	//DrawRotaGraph(336, 432, 1.5, 0.0, back_ground_image, TRUE);
	//PlaySoundMem(back_ground_sound, DX_PLAYTYPE_BACK);
}

eSceneType InGameScene::Update(const float& delta_second)
{
	//LoadStageMapFoodsCSV();
	
	InputManager* input = InputManager::GetInstance();

	if (input->GetKeyDown(KEY_INPUT_P) || input->GetButtonDown(XINPUT_BUTTON_START))
	{
		pause_flag = !pause_flag;
	}

	if (!pause_flag)
	{
		// 親クラスの更新処理を呼び出す
		__super::Update(delta_second);

		// 全ての餌を食べたら、再スタート
		if (player->GetCoinCount() >= 246)
		{
			return eSceneType::re_start;
		}

		// プレイヤーが死んだら、再スタート
		if (player->GetDestroy())
		{
			return eSceneType::re_start;
		}
		
	}
    
	// シーン情報を返却する
	return GetNowSceneType();
}

//void InGameScene::img_num_reset()
//{
// img_num = 0;
//}

void InGameScene::Draw() 
{
	//img_num_reset();
	for (int i = 0; i < image_data.size(); i++)
	{
		for(int j=0;j<image_data[i].size();j++)
		{
			Vector2D generate_location = (Vector2D((float)i, (float)j) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
		DrawRotaGraph(generate_location.x, generate_location.y, 1.0, 0.0, image_data[i][j], TRUE);
		}
		
	}
	DrawRotaGraph(16,16, 1.0, 0.0, image, TRUE);
	//draw_x += 16;
	// 親クラスの描画処理を呼び出す
	__super::Draw();

	// UI系の描画処理
	if (pause_flag)
	{
		DrawString(10, 10, " P A U S E ", GetColor(255, 255, 255), TRUE);
	}
}

void InGameScene::Finalize()
{
	// 親クラスの終了時処理を呼び出す
	__super::Finalize();
}

const eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::in_game;
}

/// <summary>
/// 当たり判定確認処理
/// </summary>
/// <param name="target">1つ目のゲームオブジェクト</param>
/// <param name="partner">2つ目のゲームオブジェクト</param>
void InGameScene::CheckCollision(GameObjectBase* target, GameObjectBase* partner)
{
	// ヌルポチェック
	if (target == nullptr || partner == nullptr)
	{
		return;
	}

	// 当たり判定情報を取得
	CapsuleCollision tc = target->GetCollision();
	CapsuleCollision pc = partner->GetCollision();

	// 当たり判定が有効か確認する
	if (tc.IsCheckHitTarget(pc.object_type) || pc.IsCheckHitTarget(tc.object_type))
	{

		// 線分の始点と終点を設定する
		tc.point[0] += target->GetLocation();
		tc.point[1] += target->GetLocation();
		pc.point[0] += partner->GetLocation();
		pc.point[1] += partner->GetLocation();

		// カプセル同士の当たり判定
		if (IsCheckCollision(tc, pc))
		{
			// 当たっていることを通知する
			target->OnHitCollision(partner);
			partner->OnHitCollision(target);
		}

	}
}

/// <summary>
/// ステージマップ（壁）読み込み処理
/// </summary>
void InGameScene::LoadStageMapCSV()
{
	// 読み込むファイル名
	std::string file_name = "Resource/Map/mariomap2.csv";
	// 指定ファイルを読み込む
	std::ifstream ifs(file_name);

	// エラーチェック
	if (ifs.fail())
	{
		throw (file_name + "が開けません\n");
	}
		
	
	// ファイルから1行ずつ読み込む
	std::string line;
	while (std::getline(ifs, line))
	{
		// 文字列を書式指定で分解して値を各変数に格納する
		char mode = NULL;		// 生成するオブジェクトモード
		int x_size = NULL;		// 生成する数（横）
		int y_size = NULL;		// 生成する数（縦）
		int spos_x = 0;			// 生成位置情報（横）
		int spos_y = 0;			// 生成位置情報（縦）
		sscanf_s(
			line.c_str(),
			"%c,%d,%d,%d,%d",
			&mode, (unsigned int)sizeof(mode),
			&x_size, &y_size,
			&spos_x, &spos_y
		);
		int image_x = 50;
		int image_y = 52;
		
		// モードによって、生成するオブジェクトを変える
		Vector2D generate_location;		// 生成位置の情報
		switch (mode)
		{
		//case 'm':

			/*DrawGraph(image_x,image_y,sora, FALSE);
			DrawFormatString(10, 10, (255, 0, 255), "通ってる",1);*/
			/*DrawRotaGraphF(image_x, image_y, 1, 0.0, sora, TRUE);*/
			
			// プレイヤー
		//case 'P':
		//	generate_location = (Vector2D((float)(spos_x+10 /*- 1*/), (float)(spos_y /*- 1*/)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
		//	player = CreateObject<Player>(generate_location);
		//	break;
		/*case 'm':
			int */
			// エネミー
		case 'E':
			if (spos_x == 14)
			{
				generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
				CreateObject<Kuribo>(generate_location);
				//break;

			}
			if (spos_x == 17)
			{
				generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
				CreateObject<Nokonoko>(generate_location);
				//break;

			}
			//if (spos_x == 13)
			//{
			//	generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
			//	CreateObject<BlueEnemy>(generate_location);
			//	//break;

			//}
			//if (spos_x == 15)
			//{
			//	generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
			//	CreateObject<PinkEnemy>(generate_location);
			//	//break;

			//}
			/*case 'I':
				generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
				CreateObject<PinkEnemy>(generate_location);
				break;
			case 'L':
				generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
				CreateObject<BlueEnemy>(generate_location);
				break;
			case 'Y':
				generate_location = (Vector2D((float)(spos_x - 1), (float)(spos_y - 1)) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
				CreateObject<YellowEnemy>(generate_location);
				break;*/
				// 上記以外
		default:
			break;
		}

	}
}

/// <summary>
/// ステージマップ餌読み込み処理
/// </summary>
void InGameScene::LoadStageMapFoodsCSV()
{
	
	ResourceManager* rm = ResourceManager::GetInstance();

	FILE* fp = NULL;
	//std::string file_name = "Resource/Map/mariotikamap.csv";
	std::string file_name = "Resource/Map/mariomap2.csv";

	// 指定されたファイルを開く
	errno_t result = fopen_s(&fp, file_name.c_str(), "r");

	// エラーチェック
	if (result != 0)
	{
		throw (file_name + "が開けません");
	}

	int x = 0;
	int y = 0;

	// ファイル内の文字を確認していく
	while (true)
	{
		// ファイルから1文字抽出する
		int c = fgetc(fp);

		// 抽出した文字がEOFならループ終了
		if (c == EOF)
		{
			break;
		}
		 //抽出した文字がドットなら、コインを生成
		else if (c == '[')
		{
			Vector2D generate_location = (Vector2D((float)x, (float)y) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
			
			
			CreateObject<Coin>(generate_location);
			x++;
			
		}

		else if (c == '0')
		{
			
			
			image_data[x][y]= rm->GetImages("Resource/Images/cloud1.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '1')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/cloud2.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '2')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/cloud3.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '3')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/cloud4.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '4')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/cloud5.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '5')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/cloud6.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '6')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/dokan_left_down.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '7')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/dokan_left_up.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		
		else if (c == '8')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/dokan_right_down.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
		
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == '9')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/dokan_right_up.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

		}
		else if (c == 'a')
		{
		
			image_data[x][y] = rm->GetImages("Resource/Images/ha0.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
		
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'b')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/ha1.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'c')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/ha2.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'd')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/mountain_left.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'e')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/mountain_right.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'f')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/mountain_surface.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'g')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/mountain_surface1.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'h')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/mountain_surface2.png", 1, 1, 1, 32, 32)[0];
			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'i')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/mountain_up.png", 1, 1, 1, 32, 32)[0];

			x++;


			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'j')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/pole.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'k')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/pole_down.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'l')
		{
		
			image_data[x][y] = rm->GetImages("Resource/Images/siro1.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'm')
		{
			image_data[x][y] = rm->GetImages("Resource/Images/sora.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'n')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/yokodokan_left_down.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'o')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/yokodokan_left_up.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'p')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/yokodokan_middle_down.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++ ;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'q')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/yokodokan_middle_up.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'r')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/yokodokan_right_down.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 's')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/yokodokan_right_up.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 't')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/blackblock.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'u')
		{
			;
			image_data[x][y] = rm->GetImages("Resource/ImagesBlock/bloak_1.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'v')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/block.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'w')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/floor.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'x')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/hatena.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'y')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/kai_block.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == 'z')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/kara_block.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}
		else if (c == '.')
		{
			
			image_data[x][y] = rm->GetImages("Resource/Images/Block/tika_floor.png", 1, 1, 1, 32, 32)[0];

			x++;
			//img_num++;
			
			//DrawRotaGraphF(generate_location.x, generate_location.y, 1, 0, 0.0, image, TRUE);

			}

		/*else if (c == ',')
		{
			draw_x += 16;
			x++;
		}*/
		
		//// 抽出した文字がPなら、パワー餌を生成
		//else if (c == 'P')
		//{
		//	Vector2D generate_location = (Vector2D((float)x, (float)y) * D_OBJECT_SIZE) + (D_OBJECT_SIZE / 2.0f);
		//	CreateObject<PowerFood>(generate_location);
		//	x++;
		//}
		// 抽出した文字が空白文字なら、生成しないで次の文字を見に行く
 		else if (c == ' ')
		{
			image_data[x][y] = NULL;
			x++;
			draw_x += 16;
		}
		// 抽出した文字が改行文字なら、次の行を見に行く
		else if (c == '\n')
		{
			x = 0;
			y++;
			//draw_x = 16;
			//draw_y += 16;
		}

	}

	// 開いたファイルを閉じる
	fclose(fp);
}
