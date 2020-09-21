#include "Vector4d.h"
#include "Matrix4d.h"
#include <iostream>
#include <math.h>

int main() {
	/*Vector4d v;
	Matrix4d m;

	Vector4d v1;
	v1.set(0,1);
	v1.set(1,1);
	v1.set(2,1);
	v1.set(3,1);

	Matrix4d m1;
	Matrix4d m2;

	int q=1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m1.set(i,j, q);
			q++;

			if (i ==j)
			{
				m2.set(i, j, 1);
			}
			else
			{
				m2.set(i, j, 0);
			}
		}
	}
	m1.print();
	std::cout << std::endl;
	m2.print();
	std::cout << std::endl;

	m = m1 * m2;

	m.print();*/

	/*v1.print();
	
	v = m1 * v1;
	v.print();*/

	float m[16];

	for (int i = 0; i < 16; i++)
	{
		m[i] = 1;
	}

	Matrix4d m1(m);


	m1.print();
}