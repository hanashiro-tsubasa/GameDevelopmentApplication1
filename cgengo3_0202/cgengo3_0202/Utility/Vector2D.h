#pragma once

class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D();                      //コンストラクタ
	Vector2D(float scalar);          //コンストラクタ
	Vector2D(float mx, float my);    //コンストラクタ
	~Vector2D();                     //コンストラクタ
	//演算子オーバーロード//////////////////////////////////
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
	//整数型に変換
	void ToInt(int *x, int *y)const;


};

