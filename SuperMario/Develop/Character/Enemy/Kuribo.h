#pragma once

#include "EnemyBase.h"



class Kuribo : public EnemyBase
{
public:

	Kuribo();
	~Kuribo();

	virtual void Initialize() override;
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

	/// <summary>
	/// �A�j���[�V��������
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void AnimationControl(float delta_second);

};
