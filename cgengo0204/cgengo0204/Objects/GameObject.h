#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	int image;            //�`�悷��摜�f�[�^
	Vector2D location;    //�ʒu���W���
	Vector2D box_size;    //��`�̑傫��

public:
	GameObject();
	virtual ~GameObject();

	//����������
	virtual void Initialize();
	//�X�V����
	virtual void Update();
	//�`�揈��
	virtual void Draw() const;
	//�I��������
	virtual void Finalize();

public:
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;  //���W�擾����
	Vector2D GetBoxSize() const;   //�����蔻�菈��

};

