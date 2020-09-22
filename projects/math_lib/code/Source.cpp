#include "Vector4d.h"
#include "Matrix4d.h"
#include <iostream>
#include <math.h>

int main() {

	float temp[16];
	for (int i = 0; i < 16; i++)
	{
		if (i % 4 == 0) { temp[i] = 1; }
		else { temp[i] = 0; }
	}
	Matrix4d m1(temp);

	for (int j = 0; j < 16; j++)
	{
		temp[j] = j;
	}
	Matrix4d m2(temp);

	m1.print();
	m2.print();

	Matrix4d m;

	m = m1 * m2;

	m.print();
}