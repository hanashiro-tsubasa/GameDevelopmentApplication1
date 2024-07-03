#include "GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	radian(0.0),
	vector(0.0f),
	score(0),
	image(NULL),
	sound(NULL),
	deleteflg(FALSE)
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{

}

//�X�V����
void GameObject::Update()
{

}

//�`�揈��
void GameObject::Draw() const
{
	//�����蔻��̉���
#ifdef D_PIVOT_CENTER
	Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#else
	Vector2D tl = location;
	Vector2D br = location + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif // D_PIVOT_CENTER
}

//�f���[�g�t���O�擾����
bool GameObject::GetDeleteFlg()const
{
	return deleteflg;
}

//�V���b�g�t���O�擾����
bool GameObject::GetShotFlg()const
{
	return shotflg;
}

void GameObject::SetBulletVector(const Vector2D& vector)
{
	this->vector = vector;
}


//�I��������
void GameObject::Finalize()
{

}

//���ʔԍ��擾����
int GameObject::GetSerialNumber() const
{
	return serial_number;
}

int GameObject::GetScore()
{
	return score;
}

//�����蔻��ʒm����
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//�����������ɍs������
}
//2
//�ʒu���擾����
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//�ʒu���ݒ菈��
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}

Vector2D GameObject::GetBoxSize() const
{
	return box_size;
}