#pragma once

#include "../GameObject.h"

// �ʏ�a�N���X
class Sora : public GameObject
{
private:

public:
	Sora();
	virtual ~Sora();

	virtual void Initialize() override;
	virtual void Draw(const Vector2D& screen_offset) const override;

	/// <summary>
	/// �����蔻��ʒm����
	/// </summary>
	/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
	//virtual void OnHitCollision(GameObjectBase* hit_object) override;

};

