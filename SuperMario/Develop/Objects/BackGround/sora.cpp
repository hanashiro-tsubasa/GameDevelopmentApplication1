#include "Sora.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

Sora::Sora()
{

}

Sora::~Sora()
{

}

void Sora::Initialize()
{

	// �摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	image = rm->GetImages("Resource/Images/sora.png")[0];

}

void Sora::Draw(const Vector2D& screen_offset) const
{
	// �I�t�Z�b�g�l����ɉ摜�̕`����s��
	Vector2D graph_location = this->location + screen_offset;
	DrawRotaGraphF(graph_location.x, graph_location.y, 1, 0.0, image, TRUE);
}

/// <summary>
/// �����蔻��ʒm����
/// </summary>
/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
//void Sora::OnHitCollision(GameObjectBase* hit_object)
//{
//	// ���������I�u�W�F�N�g���v���C���[��������A�폜����
//	if (hit_object->GetCollision().object_type == eObjectType::player)
//	{
//		DestroyObject(this);
//
//	}
//}
