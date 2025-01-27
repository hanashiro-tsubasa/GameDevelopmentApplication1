#include "EnemyBase.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"


#define D_ENEMY_SPEED (50.0f)

EnemyBase::EnemyBase() :
	//image2(),
	move_animation(),
	//eyes_animation(),
	velocity(0.0f),
	enemy_state(eEnemyState::WALK),
	direction_state(eEnemyDirectionState::RIGHT),
	animation_time(0.0f),
	move_animation_time(0.0f),
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
	move_animation = rm->GetImages("Resource/Images/monster.png", 20, 20, 1, 32, 32);
	//eyes_animation = rm->GetImages("Resource/Images/eyes.png", 4, 4, 1, 32, 32);

	//�����蔻��̐ݒ�
	collision.is_blocking = true;
	collision.object_type = eObjectType::enemy;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::wall);
	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	//�����̐ݒ�
	mobility = eMobilityType::Movable;
	//image2 = move_animation[enemy_type * 2];
}

void EnemyBase::Update(float delta_second)
{
	//�G�l�~�[��Ԃɂ���āA�����ς���

	Movement(delta_second);
	AnimationControl(delta_second);


//	switch (direction_state)//���E�㉺�Ŗڂ̉摜��ς���@
//	{
//	case eEnemyDirectionState::UP:
//		animation_count = 0;
//		break;
//	case eEnemyDirectionState::RIGHT:
//		animation_count = 1;
//		break;
//	case eEnemyDirectionState::DOWN:
//		animation_count = 2;
//		break;
//	case eEnemyDirectionState::LEFT:
//		animation_count = 3;
//		break;
//	}
//	image = eyes_animation[animation_count];
}


void EnemyBase::Draw(const Vector2D& screen_offset)const
{
	//Draw(screen_offset);	

	Vector2D graph_location = location + screen_offset;
	//DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, image2, TRUE); //��
	//__super::Draw(screen_offset);												//��
}

void EnemyBase::Finalize()
{
	move_animation.clear();
	//eyes_animation.clear();
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

EnemyBase::eEnemyDirectionState EnemyBase::GetEnemyDirectionState() const
{
	return direction_state;
}


bool EnemyBase::GetDestroy() const
{
	return is_destroy;
}






void EnemyBase::Movement(float delta_second)
{
	//�G�l�~�[��Ԃɂ���ē�����ς���
	switch (enemy_state)
	{
	/*case eEnemyState::TUISEKI:
		break;
	case eEnemyState::eIDLE:
		move_animation_time += delta_second;
		if (move_animation_time >= (1.0f / 1.0f))
		{
			move_animation_time = 0.0f;
			if (direction_state == UP)
			{
				direction_state = DOWN;
			}
			else if (direction_state == DOWN)
			{
				direction_state = UP;
			}
		}
		break;
	case eEnemyState::NAWABARI:
		break;*/
	case eEnemyState::WALK:
		break;
	case eEnemyState::eDIE:
		break;

	}


	// �i�s�����̈ړ��ʂ�ǉ�
	switch (direction_state)
	{
	
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
	animation_time += delta_second;
	if (animation_time >= (1.0f / 8.0f))
	{
		animation_time = 0.0f;
		m_animation_count++;
		if (m_animation_count >= 2)
		{
			m_animation_count = 0;
		}
		// �摜�̐ݒ�
		//image2 = move_animation[enemy_type * 2 + m_animation_count];
	}
}

