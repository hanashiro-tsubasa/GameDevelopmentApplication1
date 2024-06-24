#include "Vector2D.h"
#include <math.h>
//コンストラクタ
Vector2D::Vector2D() : x(0.0f), y(0.0f)
{
}
//引数付きコンストラクタ
Vector2D::Vector2D(float scalar) : x(scalar), y(scalar)
{
}
//引数付きコンストラクタ
Vector2D::Vector2D(float mx, float my) : x(mx), y(my)
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

	return *this;
}

const Vector2D Vector2D::operator + (const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + location.x;
	result.y = this->y + location.y;

	return result;
}

Vector2D& Vector2D::operator+=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;

	return *this;

}

const Vector2D Vector2D::operator - (const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);
	//2
	result.x = this->x - location.x;
	result.y = this->y - location.y;

	return result;
}

Vector2D& Vector2D::operator-=(const Vector2D& location)
{
	this->x -= location.x;
	this->y -= location.y;

	return *this;
}

const Vector2D Vector2D::operator*(const float& scalar) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}

const Vector2D Vector2D::operator*(const Vector2D& location)const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * location.x;
	result.y = this->y * location.y;

	return result;
}

Vector2D& Vector2D::operator*=(const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& location)
{
	this->x *= location.x;
	this->y *= location.y;

	return *this;
}
//3
const Vector2D Vector2D::operator/(const float& scalar) const
{
	if (fabsf(scalar) < 1e-6f)
	{
		return Vector2D(0.0f);
	}

	return Vector2D(this->x / scalar, this->y / scalar);
}

const Vector2D Vector2D::operator/(const Vector2D& location) const
{
	if ((fabsf(location.x) < 1e-6f) || (fabsf(location.y) < 1e-6f))
	{
		return Vector2D(0.0f);
	}
	return Vector2D(this->x / location.x, this->y / location.y);
}

Vector2D& Vector2D::operator/=(const float& scalar)
{
	if (fabsf(scalar) < 1e-6f)
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= scalar;
		this->y /= scalar;
	}
	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& location)
{
	if ((fabsf(location.x) < 1e-6f) || (fabsf(location.y) < 1e-6f))
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= location.x;
		this->y /= location.y;
	}
	//4
	return *this;
}//////////////////////////////////////////////////////

//int型への変更　　整数型データに変換　ｘとｙ成分を整数型に変換し、対応する引数に代入する
void Vector2D::ToInt(int* x, int* y) const
{
	*x = static_cast<int>(this->x);
	*y = static_cast<int>(this->y);
}