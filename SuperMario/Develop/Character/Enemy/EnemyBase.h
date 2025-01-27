#pragma once

#include "../../Objects/GameObject.h"
//#include "../../Utility/StageData.h"

enum eEnemyState
{
	WALK = 0,     //�ǐՏ��
	eDIE,          //���S���
};

class EnemyBase : public GameObject
{
protected:
	enum eEnemyType : unsigned char {
		KURIBO = 0,
		NOKONOKO,
	};

	eEnemyType enemy_type;
private:



protected:
	//�i�s�������
	enum eEnemyDirectionState : unsigned char {
		RIGHT = 0,
		DOWN,
		LEFT,
	};



	std::vector<int>move_animation;     //�ړ��̃A�j���[�V����
	//std::vector<int>eyes_animation;     //�ڂ̃A�j���[�V����
	//int image2;
	//Vector2D location;                  //�ʒu
	Vector2D velocity;                  //�ړ���
	eEnemyState enemy_state;            //�G�l�~�[���
	eEnemyDirectionState direction_state;    //�i�s�������
protected:
	float animation_time;               //�A�j���[�V��������
	float move_animation_time;
	int animation_count;                //�A�j���[�V�����Y����

	bool is_destroy;                    //���񂾏�ԂɂȂ������H

	//�ړ��A�j���[�V�����̏���
	const int animation_num[2] = { 0,1 };

protected:
	int m_animation_count;

public:



	EnemyBase();
	virtual ~EnemyBase();

	virtual void Initialize()override;
	virtual void Update(float)override;
	virtual void Draw(const Vector2D& screen_offset)const override;
	virtual void Finalize()override;

	/// <summary>
	/// �����蔻��ʒm����
	/// </summary>
	/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
	virtual void OnHitCollision(GameObjectBase* hit_object)override;

	/// <summary>
	/// �G�l�~�[�̏�Ԃ��擾����
	/// </summary>
	/// <returns>�G�l�~�[�̏��</returns>
	eEnemyState GetEnemyState() const; //

	/// <summary>
	/// �G�l�~�[�̐i�s������Ԃ��擾����
	/// </summary>
	/// <returns>�G�l�~�[�̏��</returns>
	eEnemyDirectionState GetEnemyDirectionState() const; //

	/// <summary>
	/// �G�l�~�[�����񂾏�Ԃ��m�F����
	/// </summary>
	/// <returns>�G�l�~�[�̏��</returns>
	bool GetDestroy() const; //



private:
	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="">1�t���[��������̎���</param>
	/// <returns></returns>
	void Movement(float delta_second);

protected:
	/// <summary>
	/// �A�j���[�V��������
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void AnimationControl(float delta_second);
};