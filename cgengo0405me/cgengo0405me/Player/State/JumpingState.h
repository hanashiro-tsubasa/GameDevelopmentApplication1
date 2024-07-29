#pragma once
#include "PlayerStateBase.h"
#include "../../Utility/Vector2D.h"

/// <summary>
/// �W�����v���
/// </summary>
class JumpingState : public PlayerStateBase
{
private:
	//�O�t���[���̍��W���
	Vector2D old_location;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="p">�v���C���[���</param>
	JumpingState(class Player* p);

	//�f�X�g���N�^
	virtual ~JumpingState();

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

