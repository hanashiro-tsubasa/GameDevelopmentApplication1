#include "RunningState.h"

#include "DxLib.h"
#include "../../Utility/InputControl.h"
#include "../Player.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="p">�v���C���[���</param>
RunningState::RunningState(class Player* p)
	:PlayerStateBase(p)
	, old_location(Vector2D(0.0f))
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
RunningState::~RunningState()
{

}

/// <summary>
/// ����������
/// </summary>
void RunningState::Initialize()
{
	InputControl* input = InputControl::GetInstance();
	if (input->GetKey(KEY_INPUT_A))
	{
		this->player->velocity.x = -2.0f; //�W�����v��
	}
	else if (input->GetKey(KEY_INPUT_D))
	{
		this->player->velocity.x = 2.0f;
	}
	if (this->player->GetLocation().x <= 0 &&input->GetKey(KEY_INPUT_A) ||
		this->player->GetLocation().x >= 608 &&input->GetKey(KEY_INPUT_D))
	{
		this->player->velocity.x = 0.0f;
	}

}

/// <summary>
/// �I������
/// </summary>
void RunningState::Finalize()
{

}

/// <summary>
/// �X�V����
/// </summary>
void RunningState::Update()
{
	// �n�ʂɐG�ꂽ��
	if (old_location.y == player->GetLocation().y)
		//2
	{
		//���E���͂�����Ȃ�
		InputControl* input = InputControl::GetInstance();
		if (input->GetKey(KEY_INPUT_A) || input->GetKey(KEY_INPUT_D))
		{
			//�ړ���ԂɑJ��
			player->SetNextState(ePlayerState::RUN);
		}
		else
		{
			//��~��ԂɑJ��
			player->SetNextState(ePlayerState::IDLE);
		}
	}

	//�O����W�̍X�V
	old_location = player->GetLocation();
}

/// <summary>
/// �`�揈��
/// </summary>
void RunningState::Draw() const
{
	//���W���𐮐��l�ɕϊ�
	int x = 0, y = 0;
	player->GetLocation().ToInt(&x, &y);

	//�`��
	DrawBox(x, y, x + (int)(player->box_size.x), y + (int)(player->box_size.y),
		GetColor(0, 255, 0), FALSE);
}

/// <summary>
/// ���݂̃X�e�[�g�����擾����
/// </summary>���݂̃X�e�[�g���</returns>
ePlayerState RunningState::GetState() const
{
	return ePlayerState::RUN;
}
