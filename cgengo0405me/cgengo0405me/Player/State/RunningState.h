#pragma once
#include "PlayerStateBase.h"
#include "../../Utility/Vector2D.h"

/// <summary>
/// �ړ����
/// </summary>
class RunningState : public PlayerStateBase
{
private:
	//�O�t���[���̍��W���
	Vector2D old_location;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="p">�v���C���[���</param>
	RunningState(class Player* p);

	//�f�X�g���N�^
	virtual ~RunningState();

public:
	//�����������֐�
	virtual void Initialize() override;

	//�I�������֐�
	virtual void Finalize() override;

	//�X�V����
	virtual void Update() override;

	//�`�揈��
	virtual void Draw() const override;

	//��Ԃ̎擾
	virtual ePlayerState GetState() const override;
};
