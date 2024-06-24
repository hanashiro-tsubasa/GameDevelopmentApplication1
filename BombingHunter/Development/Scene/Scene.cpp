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
	//����Y��h�~
	Finalize();
}






//����������
void Scene::Initialize()
{
	//�v���C���[����ʒ���������ɐ�������
	CreateObject<Player>(Vector2D(320.0f, 60.0f));
	//�w�i�̓ǂݍ���
	back_ground=LoadGraph("Resource/Images/BackGround.png");
	srand((unsigned int)time(NULL));
}


void Scene::Update()
{
	//�I�u�W�F�N�g���X�g���̃I�u�W�F�N�g���X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}



	//�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j<objects.size(); j++)
		{
			//�����蔻��`�F�b�N����
			HitCheckObject(objects[i], objects[j]);
		}
	}
	//�����_���Ńn�R�G�𐶐�����/////////////////
	
	int Createrand = rand() % 100 + 1;
	int GoldCreaterand = rand() % 10000 + 1;
	int HarpyCreaterand = rand() % 2000 + 1;
	
	if (Createrand == 1&&EnemyNumber < 6)//�n�R�e�L�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Enemy>(Vector2D(-40.0f, 400.0f));
		EnemyNumber += 1;
	}
	if (Createrand == 2 && EnemyNumber < 6)//�n�R�e�L�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Enemy>(Vector2D(679.0f, 400.0f));
		EnemyNumber += 1;
	}
	/////////////////////////////////////////////

	//�����_���Ńn�l�G�𐶐�����/////////////////


	if (Createrand == 3 && WingEnemyNumber < 6)//�n�l�e�L�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{ 
		CreateObject<WingEnemy>(Vector2D(-40.0f, 150.0f+rand()%150));
		WingEnemyNumber += 1;
	}
	if (Createrand == 4 && WingEnemyNumber < 6)//�n�l�e�L�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<WingEnemy>(Vector2D(679.0f, 150.0f+rand()%150));
		WingEnemyNumber += 1;
	}
	/////////////////////////////////////////////

	//�����_���ŋ��̓G�𐶐�����/////////////////


	if (GoldCreaterand == 5 && GoldEnemyNumber < 1)//���e�L�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<GoldEnemy>(Vector2D(-40.0f, 420.0f));
		GoldEnemyNumber += 1;
	}
	if (GoldCreaterand == 6 && GoldEnemyNumber < 1)//���e�L�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<GoldEnemy>(Vector2D(679.0f, 420.0f));
		GoldEnemyNumber += 1;
	}
	/////////////////////////////////////////////

	//�����_���Ńn�[�s�[�𐶐�����/////////////////


	if (HarpyCreaterand == 7 && HarpyNumber < 2)//�n�[�s�[�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Harpy>(Vector2D(-40.0f, 150.0f + rand() % 150));
		HarpyNumber += 1;
	}
	if (HarpyCreaterand == 8 && HarpyNumber < 2)//�n�[�s�[�̈�x�̐��������) /*(InputControl::GetKeyDown(KEY_INPUT_Z))*/
	{
		CreateObject<Harpy>(Vector2D(679.0f, 150.0f + rand() % 150));
		HarpyNumber += 1;
	}
	/////////////////////////////////////////////


	

	//�X�y�[�X�L�[����������{���𐶐�����//////
	if (InputControl::GetKeyDown(KEY_INPUT_SPACE)||GetMouseInput())
	{
		CreateObject<Bomb>(Vector2D(objects[0]->GetLocation().x, objects[0]->GetLocation().y + 70.0f));
	}
	////////////////////////////////////////////


	
	//�������ꂽ�I�u�W�F�N�g�����ׂČ���
	for (int i = 0; i < objects.size(); i++)
	{
		//�����V���b�g�t���O��TRUE�ɂȂ�����
		if(objects[i]->GetShotFlg() == TRUE)
		{
			CreateObject<EnemyBullet>(Vector2D(objects[i]->GetLocation()));
		}

		//�����f���[�g�t���O��TRUE�ɂȂ�����
		if (objects[i]->GetDeleteFlg() == TRUE)
		{
			//�n�R�e�L����������EnemyNumber�����炷
			if (objects[i]->GetSerialNumber()==2)
			{
				EnemyNumber -= 1;
			}
			//�n�l�e�L����������WingEnemyNumber�����炷
			if (objects[i]->GetSerialNumber() == 4)
			{
				WingEnemyNumber -= 1;
			}
			//���e�L����������GoldEnemyNumber�����炷
			if (objects[i]->GetSerialNumber() == 5)
			{
				GoldEnemyNumber -= 1;
			}
			//�n�[�s�[����������HarpyNumber�����炷
			if (objects[i]->GetSerialNumber() == 6)
			{
				HarpyNumber -= 1;
			}
			
			//�f���[�g�t���O��TRUE�ɂȂ����I�u�W�F�N�g������
			objects.erase(objects.begin() + i);
		}
	}
	
}


void Scene::Draw()const
{
	//�w�i�̕`��
    DrawExtendGraph(0, 0,640,480, back_ground, TRUE);
	//�I�u�W�F�N�g���X�g���̃I�u�W�F�N�g��`�悷��
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
	//�I�u�W�F�N�g���X�g������Ȃ珈�����I������
	if (objects.empty())
		
	{
		return;
	}

	//�I�u�W�F�N�g���X�g���̃I�u�W�F�N�g���������
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//���I�Ɋm�ۂ������X�g���J������
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//�����蔻��`�F�b�N�����i��`�̒��S�œ����蔻������j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);

	}
}
//3
#else

//�����蔻��`�F�b�N�����i���㒸�_�̍��W���瓖���蔻��v�Z���s���j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�����_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//��`A�Ƌ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVOT_CNETER