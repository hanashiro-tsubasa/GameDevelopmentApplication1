#include "GameObject.h"
#include "DxLib.h"
//�R���X�g���N�^
GameObject::GameObject() : color(0x0), location(0.0f), box_size(0.0f)
{

}
//�f�X�g���N�^
GameObject::~GameObject()
{

}
//�Q�[���I�u�W�F�N�g�̏�����
void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);

	box_size = Vector2D(32.0f);

	location = box_size;
}
//�Q�[���I�u�W�F�N�g�̍X�V����
void GameObject::Update()
{
	location.x += 1.0f;

	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}
//�`�揈��
void GameObject::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color,
		TRUE);
}
//�I������
void GameObject::Finalize()
{

}
//���W�ݒ�
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
	//2
}
//���W�擾
Vector2D GameObject::GetLocation()const
{
	return this->location;
}
//�傫�����擾
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}

