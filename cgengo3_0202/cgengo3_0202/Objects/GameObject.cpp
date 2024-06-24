#include "GameObject.h"
#include "DxLib.h"
//�R���X�g���N�^
GameObject::GameObject() : color(0x0), location(), box_size()
{

}
//�f�X�g���N�^
GameObject::~GameObject()
{

}
//�Q�[���I�u�W�F�N�g�̏�����
void GameObject::Initialize()
{
	location = Vector2D(32.0f, 24.0f);

	box_size = Vector2D(32.0f, 24.0f);

	color = GetColor(0, 255, 0);
}
//�Q�[���I�u�W�F�N�g�̃A�b�v�f�[�g
void GameObject::Update()
{
	location += 0.1f;
}
//�Q�[���I�u�W�F�N�g�̕`��
void GameObject::Draw() const
{
	Vector2D tl = this->location - (this->box_size / 2.0f);
	Vector2D br = this->location + (this->box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, color, TRUE);
}
//�Q�[���I�u�W�F�N�g�̏I������
void GameObject::Finalize()
{

}
//�ʒu���̐ݒ�
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}
//�ʒu���̎擾
Vector2D GameObject::GetLocation() const
{
	return this->location;
}
//�{�b�N�X�̑傫�����擾
//2
Vector2D GameObject::GetBoxSize()const
{
	return this->box_size;
}