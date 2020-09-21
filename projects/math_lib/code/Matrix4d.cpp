#include "Matrix4d.h"
#include <iostream>

float m[4][4];

Matrix4d::Matrix4d(){
}

//get/set
float Matrix4d::get(int xyzw, int i) { return m[xyzw][i]; }
void Matrix4d::set(int xyzw, int i, float value) { m[xyzw][i] = value; }

void Matrix4d::print() {
	for (int i = 0; i < 4; i++)
	{
		std::cout << "[ ";

		for (int j = 0; j < 4; j++)
		{
			std::cout << m[i][j]<<", ";
		}
		std::cout <<"]" <<std::endl;
	}
	

}

Matrix4d Matrix4d::rotation(char axis, float degres){
	switch (axis)
	{
	case 'x':
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i==j && i ==3 || j==4)
				{
					set(i, j, 1);
				}
				else
				{
					set(i, j, 0);
				}
			}
		}
		break;
	default:
		break;
	}
}

//overided operator
Vector4d Matrix4d::operator*(Vector4d v) {
	Vector4d temp;
	for (int i = 0; i < 4; i++)
	{
		temp.set(i, (m[i][0] * v.get(0) + m[i][1] * v.get(1) + m[i][2] * v.get(2)+m[i][3]*v.get(3)));
	}
	return temp;
}

Matrix4d Matrix4d::operator*(Matrix4d n) {
	Matrix4d temp;
	float t = 0;
	for (int k = 0; k < 4; k++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				t = t + (m[j][i] * n.get(i,k));
			}

			temp.set(j, k, t);
			t = 0;
		}
	}
	return temp;
}




