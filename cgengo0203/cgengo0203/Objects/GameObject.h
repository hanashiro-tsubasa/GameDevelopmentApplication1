#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;    //�F
	Vector2D location;     //���W
	Vector2D box_size;     //�傫��

public:
	GameObject();             //�R���X�g���N�^
	virtual ~GameObject();    //�f�X�g���N�^

	virtual void Initialize();//����������
	virtual void Update();    //�X�V����
	virtual void Draw() const;//�`�揈��
	virtual void Finalize();  //�I������

public:
	void SetLocation(Vector2D location);  //���W�̐ݒ�
	Vector2D GetLocation() const;         //���W�̎擾
	Vector2D GetBoxSize() const;          //�傫���̎擾
};
