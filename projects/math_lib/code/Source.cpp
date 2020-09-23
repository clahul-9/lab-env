#include "Vector4d.h"
#include "Matrix4d.h"
#include <iostream>
#include <math.h>

int main() {

	float temp[16];
	
	for (int j = 0; j < 16; j++)
	{
		temp[j] = 1;
	}

	Matrix4d m1(temp);
	m1.print();
	m1.inverse();
	m1.print();

}