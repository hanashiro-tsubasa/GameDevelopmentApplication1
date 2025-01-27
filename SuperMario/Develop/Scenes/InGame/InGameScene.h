#pragma once

#include "../../Character/Player/Player.h"
#include "../SceneBase.h"
#include "../../Objects/GameObject.h"

class InGameScene : public SceneBase //, GameObject
{
private:
	class Player* player;		// �v���C���[���
	int back_ground_image;		// �w�i�摜
	int back_ground_sound;		// BGM
	int sora;
	int image;
	//int img_num;
	int draw_x;
	int draw_y;
	std::vector<std::vector<int>> image_data;
	float scroll;
	bool pause_flag;			// �ꎞ��~�t���O

public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw()  override;
	virtual void Finalize() override;

	// ���݂̃V�[���^�C�v�����擾����
	virtual const eSceneType GetNowSceneType() const override;

	/// <summary>
	/// �����蔻��m�F����
	/// </summary>
	/// <param name="target">1�ڂ̃Q�[���I�u�W�F�N�g</param>
	/// <param name="partner">2�ڂ̃Q�[���I�u�W�F�N�g</param>
	virtual void CheckCollision(GameObjectBase* target, GameObjectBase* partner) override;

private:
	/// <summary>
	/// �X�e�[�W�}�b�v�i�ǁj�ǂݍ��ݏ���
	/// </summary>
	void LoadStageMapCSV();
	/// <summary>
	/// �X�e�[�W�}�b�v�a�ǂݍ��ݏ���
	/// </summary>
	void LoadStageMapFoodsCSV();

	//void img_num_reset();
};

