#include "EnemyBase.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

#define D_ENEMY_SPEED (50.0f)

EnemyBase::EnemyBase() :
	move_animation(),
	eyes_animation(),
	velocity(0.0f),
	enemy_state(eEnemyState::TUISEKI),
	direction_state(eEnemyDirectionState::UP),
	animation_time(0.0f),
	animation_count(0),
	m_animation_count(0),
	is_destroy(false)
{

}

EnemyBase::~EnemyBase()
{
}
void EnemyBase::Initialize()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm-> GetImages("Resource/Images/monster.png",20,20,1,32,32);
	eyes_animation = rm-> GetImages("Resource/Images/eyes.png",4,4,1,32,32);

	//�����蔻��̐ݒ�
	collision.is_blocking = true;
	collision.object_type = eObjectType::enemy;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::wall);
	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	//�����̐ݒ�
	mobility = eMobilityType::Movable;
}

void EnemyBase::Update(float delta_second)
{
	//�G�l�~�[��Ԃɂ���āA�����ς���
	switch (enemy_state)
	{
		case eEnemyState::TUISEKI:
			Movement(delta_second);
			AnimationControl(delta_second);
		case eEnemyState::EYE:
			animation_time += delta_second;
			if (animation_time >= 0.07f)
			{
				animation_time = 0.0f;
				animation_count++;
				m_animation_count++;
				
				if (animation_count >= eyes_animation.size())
				{
					enemy_state = eEnemyState::TUISEKI;
					animation_count = 0;
					is_destroy = true;
				}
				if (m_animation_count >= move_animation.size())
				{
					m_animation_count = 0;
				}

			}
			image = eyes_animation[animation_count];
			image2 = move_animation[m_animation_count];
			
			break;
		default:
			break;
	}

}

void EnemyBase::Draw(const Vector2D& screen_offset)const
{
	//Draw(screen_offset);
	
	Vector2D graph_location = this->location + screen_offset;
	DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, image2, TRUE);
	__super::Draw(screen_offset);
}

void EnemyBase::Finalize()
{
	move_animation.clear();
	eyes_animation.clear();
}

/// <summary>
/// �����蔻��ʒm����
/// </summary>
/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{
	// ���������A�I�u�W�F�N�g���ǂ�������
	if (hit_object->GetCollision().object_type == eObjectType::wall)
	{
		// �����蔻������擾���āA�J�v�Z��������ʒu�����߂�
		CapsuleCollision hc = hit_object->GetCollision();
		hc.point[0] += hit_object->GetLocation();
		hc.point[1] += hit_object->GetLocation();

		// �ŋߖT�_�����߂�
		Vector2D near_point = NearPointCheck(hc, this->location);

		// Player����near_point�ւ̕����x�N�g�����擾
		Vector2D dv2 = near_point - this->location;
		Vector2D dv = this->location - near_point;

		// �߂荞�񂾍���
		float diff = (this->GetCollision().radius + hc.radius) - dv.Length();

		// diff�̕������߂�
		location += dv.Normalize() * diff;
	}

}
/// <summary>
/// �G�l�~�[�̏�Ԃ��擾����
/// </summary>
/// <returns>�G�l�~�[�̏��</returns>
eEnemyState EnemyBase::GetEnemyState() const
{
	return enemy_state;
}

bool EnemyBase::GetDestroy() const
{
	return is_destroy;
}






void EnemyBase::Movement(float delta_second)
{
// �i�s�����̈ړ��ʂ�ǉ�
	switch (direction_state)
	{
	case EnemyBase::UP:
	velocity.y = -1.0f;
	break;
	case EnemyBase::DOWN:
	velocity.y = 1.0f;
	break;
	case EnemyBase::LEFT:
	velocity.x = -1.0f;
	break;
	case EnemyBase::RIGHT:
	velocity.x = 1.0f;
	break;
	default:
	break;
	}
	// �ړ��� * ���� * ���� �ňړ�������肷��
	location += velocity * D_ENEMY_SPEED * delta_second;
}

/// <summary>
/// �A�j���[�V��������
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::AnimationControl(float delta_second)
{
	// �ړ����̃A�j���[�V����
	/*animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 2)
		{
			animation_count = 0;
		}
		// �摜�̐ݒ�
		int dir_num = (int)direction_state;
		if (0 <= dir_num && dir_num < 2)
		{
			image = move_animation[(dir_num * 1) + animation_num[animation_count]];
		}
          
	}*/
}

	