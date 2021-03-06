#pragma once
#include "Vector4d.h"
class Matrix4d
{
private:
	float m[16];
public:
	Matrix4d(float in[16]);
	Matrix4d();

	void rotation(Vector4d v,float radians);
	void transpose();
	void inverse();
	//operator
	Matrix4d operator*(Matrix4d mix);
	Vector4d operator*(Vector4d v);
	float& operator[](int n1);

};

