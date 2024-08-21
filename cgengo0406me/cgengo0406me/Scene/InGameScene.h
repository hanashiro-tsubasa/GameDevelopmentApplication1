#pragma once
#include "SceneBase.h"

class InGameScene : public SceneBase
{
private:
	class Player* Player;

public:
	InGameScene();
	virtual ~InGameScene();

	//����������
	virtual void Initialize() override;

	//�X�V����
	//���@���F�P�t���[��������̎���
	//�߂�l�F���̃V�[���^�C�v
	virtual eSceneType Update(float delta_second)override;

	//�`�揈��
	virtual void Draw() const override;

	//�I��������
	virtual void Finalize() override;

	//���݂̃V�[���^�C�v�i�I�[�o�[���C�h�K�{�j
	virtual eSceneType GetNowSceneType() const override;
};