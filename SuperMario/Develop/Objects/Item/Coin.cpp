#include "Coin.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

Coin::Coin()
{

}

Coin::~Coin()
{

}

void Coin::Initialize()
{
	// �摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	image = rm->GetImages("Resource/Images/Item/coin.png",4,4,1,32,32)[0];

	// �����蔻��̐ݒ�
	collision.is_blocking = false;
	collision.object_type = eObjectType::coin;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.radius = 1.0f;

	z_layer = 1;
}

void Coin::Draw(const Vector2D& screen_offset) const
{
	// �I�t�Z�b�g�l����ɉ摜�̕`����s��
	Vector2D graph_location = this->location + screen_offset;
	DrawRotaGraphF(graph_location.x, graph_location.y, 1, 0.0, image, TRUE);
}

/// <summary>
/// �����蔻��ʒm����
/// </summary>
/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
void Coin::OnHitCollision(GameObjectBase* hit_object)
{
	// ���������I�u�W�F�N�g���v���C���[��������A�폜����
	if (hit_object->GetCollision().object_type == eObjectType::player)
	{
		DestroyObject(this);

	}
}
