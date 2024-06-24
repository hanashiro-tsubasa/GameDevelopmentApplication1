#pragma once

class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D();                      //�R���X�g���N�^
	Vector2D(float scalar);          //�R���X�g���N�^
	Vector2D(float mx, float my);    //�R���X�g���N�^
	~Vector2D();                     //�R���X�g���N�^
	//���Z�q�I�[�o�[���[�h//////////////////////////////////
public:
	Vector2D& operator = (const Vector2D& location);

	const Vector2D operator + (const Vector2D& location)const;
	Vector2D& operator += (const Vector2D& location);

	const Vector2D operator - (const Vector2D& location)const;
	Vector2D& operator -= (const Vector2D& location);

	const Vector2D operator * (const float& scalar) const;
	const Vector2D operator * (const Vector2D&location) const;
	Vector2D& operator *= (const float& scalar);
	Vector2D& operator *= (const Vector2D& location);

	const Vector2D operator / (const float& scalar) const;
	const Vector2D operator / (const Vector2D& location) const;
	Vector2D& operator /= (const float& scalar);
	Vector2D& operator /= (const Vector2D& location);
///////////////////////////////////////////////////////////////////////////
	//�����^�ɕϊ�
	void ToInt(int *x, int *y)const;


};

