#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER //���W�̌��_���摜�̒��S�ɂ���

//�Q�[���I�u�W�F�N�g��b�N���X
class GameObject
{
protected:
	Vector2D location;      //�ʒu���
	Vector2D box_size;      //��`�̑傫��
	Vector2D vector;        //�ړ�����
	double radian;          //����
	int image;              //�摜
	int sound;              //����
	bool deleteflg;         //�f���[�g�t���O
	bool hitflg;            //�����������t���O
	bool shotflg;           //�V���b�g�t���O
	int score;              //���v�X�R�A
	int serial_number;      //���ʔԍ�

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();    //����������
	virtual void Update();        //�X�V����
	virtual void Draw() const;    //�`�揈��
	virtual void Finalize();      //�I��������
	int GetSerialNumber() const;  //���ʔԍ��擾����
	int GetScore();               //�X�R�A�擾����

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;
	//�f���[�g�t���O�擾����
	bool GetDeleteFlg() const;
	//�V���b�g�t���O�擾����
	bool GetShotFlg() const;
	//�G�e�p�x�擾
	void SetBulletVector(const	Vector2D& vector);

	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize() const;
};

