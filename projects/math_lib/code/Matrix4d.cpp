#include "Matrix4d.h"
#include <iostream>

float m[16];

Matrix4d::Matrix4d(float in[16]){
	for (int i = 0; i < 16; i++)
	{
		m[i] = in[i];
	}
}
Matrix4d::Matrix4d() {}

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
Vector4d Matrix4d::operator*(Vector4d v) {
	Vector4d temp;
	
	for (int i = 0; i < 4; i++)
	{
		temp[i] = (m[0 + i * 4] * v[0] + m[1 + i * 4] * v[1] + m[2 + i * 4] * v[2] + m[3 + i * 4] * v[3]);
	}
	return temp;
}

Matrix4d Matrix4d::operator*(Matrix4d n) {
	float temp[16];
	for (int i = 0; i < 16; i++)//temp
	{
		if (i)
		{

		}
	}
}




