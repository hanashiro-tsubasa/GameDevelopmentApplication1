#pragma once

#include "../SceneBase.h"
#include "../../Objects/GameObjectManager.h"

// �^�C�g���V�[��
class TitleScene : public SceneBase
{
private:
	int title_img;
public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw() override;
	virtual void Finalize() override;

	// ���݂̃V�[���^�C�v�����擾����
	virtual const eSceneType GetNowSceneType() const override;
};

