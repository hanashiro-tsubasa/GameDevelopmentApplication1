#include "Score.h"
#include "DxLib.h"

Score::Score() :kazuimage()
{
	kazuimage[0] = NULL;
	kazuimage[1] = NULL;
	kazuimage[2] = NULL;
	kazuimage[3] = NULL;
	kazuimage[4] = NULL;
	kazuimage[5] = NULL;
	kazuimage[6] = NULL;
	kazuimage[7] = NULL;
	kazuimage[8] = NULL;
	kazuimage[9] = NULL;
	text1 = NULL;
	text2 = NULL;
}

Score::~Score()
{

}

void Score::Initialize()
{
	//�摜�̓ǂݍ���
	kazuimage[0] = LoadGraph("Resource/Images/Score/0.png");
	kazuimage[1] = LoadGraph("Resource/Images/Score/1.png");
	kazuimage[2] = LoadGraph("Resource/Images/Score/2.png");
	kazuimage[3] = LoadGraph("Resource/Images/Score/3.png");
	kazuimage[4] = LoadGraph("Resource/Images/Score/4.png");
	kazuimage[5] = LoadGraph("Resource/Images/Score/5.png");
	kazuimage[6] = LoadGraph("Resource/Images/Score/6.png");
	kazuimage[7] = LoadGraph("Resource/Images/Score/7.png");
	kazuimage[8] = LoadGraph("Resource/Images/Score/8.png");
	kazuimage[9] = LoadGraph("Resource/Images/Score/9.png");
	text1 = LoadGraph("Resource/Images/Score/font-21.png");
	text2 = LoadGraph("Resource/Images/Score/hs.png");
	timer = LoadGraph("Resource/Images/TimeLimit/timer-03.png");

	if (kazuimage[0] == -1 || kazuimage[1] == -1 || kazuimage[2] == -1 || kazuimage[3] == -1 || kazuimage[4] == -1 || kazuimage[5] == -1 || kazuimage[6] == -1 || kazuimage[7] == -1 || kazuimage[8] == -1 || kazuimage[9] == -1)
	{
		throw("�����̉摜������܂���\n");
	}
	if (text1 == -1 || text2 == -1)
	{
		throw("�����̉摜������܂���\n");
	}


	image = kazuimage[0];
	
}

//�X�V����
void Score::Update()
{
	//�A�j���[�V��������
	//AnimationControl();
}


//2
//�`�揈��
void Score::Draw()const
{
	//�������ƂɃX�R�A��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.7, 0.0, image, TRUE, 0);

	DrawRotaGraphF(200, 460, 1, 0.0, text1, TRUE, 0);
	DrawRotaGraphF(400, 460, 1, 0.0, text2, TRUE, 0);
	DrawRotaGraphF(20, 460, 0.7, 0.0, timer , TRUE, 0);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I��������
void Score::Finalize()
{
	//�g�p�����摜���J��
	DeleteGraph(kazuimage[0]);
	DeleteGraph(kazuimage[1]);
	DeleteGraph(kazuimage[2]);
	DeleteGraph(kazuimage[3]);
	DeleteGraph(kazuimage[4]);
	DeleteGraph(kazuimage[5]);
	DeleteGraph(kazuimage[6]);
	DeleteGraph(kazuimage[7]);
	DeleteGraph(kazuimage[8]);
	DeleteGraph(kazuimage[9]);
	DeleteGraph(text1);
	DeleteGraph(text2);

}

//void Score::AnimatonControl()
//{
//	//
//}
