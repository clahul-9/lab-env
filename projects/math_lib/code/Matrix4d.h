#pragma once
#include "Vector4d.h"
class Matrix4d
{
private:
	float m[4][4];
public:
	Matrix4d();

	//sett/get
		//x
	float get(int xyzw,int i);
	void set(int xyzw, int i, float value);

	void print();
	//operator
	Matrix4d operator*(Matrix4d mix);
	Vector4d operator*(Vector4d v);

};

