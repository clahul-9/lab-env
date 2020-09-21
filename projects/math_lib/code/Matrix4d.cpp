#include "Matrix4d.h"
#include <iostream>

float m[16];

Matrix4d::Matrix4d(float in[16]){
	for (int i = 0; i < 16; i++)
	{
		m[i] = in[i];
	}
}

//get/set


void Matrix4d::print() {
	std::cout << "[ ";
	for (int i = 0; i < 16; i++)
	{
		std::cout << m[i] <<" , ";
		if ((i+1)%4==0)
		{
			std::cout << std::endl;
		}
	}

	std::cout << "]" << std::endl;


}


void Matrix4d::rotation(Vector4d v,float r){
	//Matrix4d temp;
	//temp.set(0,0,cos(r) + (1 - cos(r)) * v.get(0) * v.get(0));
	//temp.set(1, 0, (1 - cos(r)) * v.get(0) * v.get(1) + v.get(2) * sin(r));
	//temp.set(2, 0, (1 - cos(r))* v.get(0)* v.get(2) - v.get(1) * sin(r));
	//temp.set(3, 0, 0);

	//temp.set(0, 1, (1 - cos(r)) * v.get(0) * v.get(1) - v.get(2) * sin(r));
	//temp.set(1, 1, )


	//temp.print();

}


//overided operator
//Vector4d Matrix4d::operator*(Vector4d v) {
//	Vector4d temp;
//	for (int i = 0; i < 4; i++)
//	{
//		temp.set(i, (m[i][0] * v.get(0) + m[i][1] * v.get(1) + m[i][2] * v.get(2)+m[i][3]*v.get(3)));
//	}
//	return temp;
//}
//
//Matrix4d Matrix4d::operator*(Matrix4d n) {
//	Matrix4d temp;
//	float t = 0;
//	for (int k = 0; k < 4; k++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			for (int i = 0; i < 4; i++)
//			{
//				t = t + (m[j][i] * n.get(i,k));
//			}
//
//			temp.set(j, k, t);
//			t = 0;
//		}
//	}
//	return temp;
//}




