#pragma once

#include "../../Objects/GameObject.h"

//�v���C���[���
enum ePlayerState
{
	IDLE,		// �ҋ@���
	MOVE,		// �ړ����
	JUMP,		// �W�����v���
	STAR,		// �X�^�[���
	DIE,		// ���S���
};
class Player : public GameObject
{
private:
	//�i�s�������
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NONE,
	};
private:
	std::vector<int> move_animation;
	std::vector<int> jump_animation;
	std::vector<int> star_animation;
	std::vector<int> dying_animation;
	Vector2D old_location;					// �O���location
	Vector2D velocity;						// �ړ���
	ePlayerState player_state;				// �v���C���[���
	eDirectionState now_direction_state;	// ���ݐi�s�������
	eDirectionState next_direction_state;	// ����i�s�������
	int coin_count=0;							// ������R�C���̐�
	float animation_time;					// �A�j���[�V��������
	int animation_count;					// �A�j���[�V�����Y��
	bool is_star;						// �X�^�[����������H
	bool is_destroy;						// ���񂾏�ԂɂȂ������H

	//�ړ��A�j���[�V�����̏���
	const int animation_num[4] = { 3,4,5,4 };

public:
	Player();
	virtual ~Player();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screen_offset) const override;
	virtual void Finalize() override;

	/// <summary>
	/// �����蔻��ʒm����
	/// </summary>
	/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
	virtual void OnHitCollision(GameObjectBase* hit_object) override;

public:
	/// <summary>
	/// �R�C������������擾
	/// </summary>
	/// <returns>�R�C�����������</returns>
	int GetCoinCount() const;

	/// <summary>
	/// �v���C���[�̏�Ԃ��擾����
	/// </summary>
	/// <returns>�v���C���[�̏��</returns>
	ePlayerState GetPlayerState() const;

	/// <summary>
	/// �v���C���[���p���[�A�b�v���Ă邩�m�F����
	/// </summary>
	/// <returns>�v���C���[�̏��</returns>
	bool GetPowerUp() const;

	/// <summary>
	/// �p���[�_�E��������
	/// </summary>
	void SetPowerDown();

	/// <summary>
	/// �v���C���[���p���[�A�b�v���Ă邩�m�F����
	/// </summary>
	/// <returns>�v���C���[�̏��</returns>
	bool GetDestroy() const;


private:
	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void Movement(float delta_second);
	/// <summary>
	/// �A�j���[�V��������
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void AnimationControl(float delta_second);
};
