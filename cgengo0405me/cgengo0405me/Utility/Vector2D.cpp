#include "Vector2D.h"


//引数付きコンストラクタ
Vector2D::Vector2D(float scalar)
	: x(scalar)
	, y(scalar)
{
}
//引数付きコンストラクタ
Vector2D::Vector2D(float mx, float my)
	: x(mx)
	, y(my)
{
}
//デストラクタ
Vector2D::~Vector2D()
{
}
//演算処理///////////////////////////////////////////////
Vector2D& Vector2D::operator=(const Vector2D& location)
{
	this->x = location.x;
	this->y = location.y;

	return (*this);
}

const Vector2D Vector2D::operator+(const Vector2D& location)const
{
	return Vector2D((this->x + location.x), (this->y + location.y));
}

Vector2D& Vector2D::operator+=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;
	return (*this);
}

Vector2D& Vector2D::operator-=(const Vector2D& location)
{
	this->x -= location.x;
	this->y -= location.y;
	return (*this);
	//2
}

const Vector2D Vector2D::operator*(const float& scalar)const
{
	return Vector2D((this->x * scalar), (this->y * scalar));
}

const Vector2D Vector2D ::operator*(const Vector2D& location)const
{
	return Vector2D((this->x * location.x), (this->y * location.y));
}

Vector2D& Vector2D::operator *= (const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	return (*this);
}

Vector2D& Vector2D::operator*=(const Vector2D& location)
{
	this->x *= location.x;
	this->y *= location.y;
	return(*this);
}

const Vector2D Vector2D::operator/(const float& scalar)const
{
	return Vector2D((this->x / scalar), (this->y / scalar));
}

const Vector2D Vector2D::operator/(const Vector2D& location)const
{
	return Vector2D((this->x / location.x), (this->y / location.y));
}

Vector2D& Vector2D::operator/=(const float& scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	return (*this);
}

Vector2D& Vector2D::operator/=(const Vector2D& location)
{
	this->x /= location.x;
	this->y /= location.y;
	return (*this);
}

void Vector2D::ToInt(int* x, int* y)const
{
	(*x) = static_cast<int>(this->x);
	(*y) = static_cast<int>(this->y);
}