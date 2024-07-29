#pragma once
#include <vector>
#include "State/Enum/PlayerState.h"
#include "../Utility/Vector2D.h"

/// <summary>
/// �v���C���[�N���X
/// </summary>
class Player
{
private:
	class PlayerStateBase* state = nullptr;
	ePlayerState next_state = ePlayerState::NONE;
	float g_velocity = 0.0f;
	Vector2D location = Vector2D(0.0f);

public:
	Vector2D velocity = Vector2D(0.0f);
	Vector2D box_size = Vector2D(0.0f);

public:
	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="init_location">�������W</param>
	void Initialize(Vector2D init_location = Vector2D(0.0f));

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw() const;

public:
	/// <summary>
	/// ����State��ݒ�
	/// </summary>
	/// <param name="next_state">����State</param>
	void SetNextState(ePlayerState next_state);

	/// <summary>
	/// ���W�̎擾
	/// </summary>
	Vector2D& GetLocation();
};

