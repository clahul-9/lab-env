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

//functions

void Matrix4d::rotation(Vector4d v,float r){
	float temp[16];
	temp[0] = (cos(r) + (1 - cos(r) * v[0]*v[0]));
	temp[1] = (1 - cos(r)) * v[0] * v[1] - v[2] * sin(r);
	temp[2] = (1 - cos(r)) * v[0] * v[2] - v[1] * sin(r);
	temp[3] = 0;

	temp[4] = (1 - cos(r)) * v[0] * v[1] - v[2] * sin(r);
	temp[5] = (cos(r) + (1 - cos(r) * v[1] * v[1]));
	temp[6] = (1 - cos(r)) * v[1] * v[2] - v[0] * sin(r);
	temp[7] = 0;

	temp[8] = (1 - cos(r)) * v[0] * v[2] - v[1] * sin(r);
	temp[9] = (1 - cos(r)) * v[1] * v[2] - v[0] * sin(r);
	temp[10] = (cos(r) + (1 - cos(r) * v[2] * v[2]));
	temp[11] = 0;

	temp[12] = 0;
	temp[13] = 0;
	temp[14] = 0;
	temp[15] = 1;

	Matrix4d out(temp);
	out = this->operator*(out);

	for (int i = 0; i < 16; i++)
	{
		m[i] = out[i];
	}
}
void Matrix4d::transpose() {
	float temp[16];
	for (int i = 0; i < 16; i++) { temp[i] = m[i]; }
	int k = 0;

	for (int i = 0; i < 16; i++)
	{
		m[i] = temp[k + (i % 4) * 4];
		if ((i + 1) % 4 == 0) { k++; }
	}
}

void Matrix4d::inverse() {
	float inv[16], det;

    inv[0] = m[5] * m[10] * m[15] -
        m[5] * m[11] * m[14] -
        m[9] * m[6] * m[15] +
        m[9] * m[7] * m[14] +
        m[13] * m[6] * m[11] -
        m[13] * m[7] * m[10];

    inv[4] = -m[4] * m[10] * m[15] +
        m[4] * m[11] * m[14] +
        m[8] * m[6] * m[15] -
        m[8] * m[7] * m[14] -
        m[12] * m[6] * m[11] +
        m[12] * m[7] * m[10];

    inv[8] = m[4] * m[9] * m[15] -
        m[4] * m[11] * m[13] -
        m[8] * m[5] * m[15] +
        m[8] * m[7] * m[13] +
        m[12] * m[5] * m[11] -
        m[12] * m[7] * m[9];

    inv[12] = -m[4] * m[9] * m[14] +
        m[4] * m[10] * m[13] +
        m[8] * m[5] * m[14] -
        m[8] * m[6] * m[13] -
        m[12] * m[5] * m[10] +
        m[12] * m[6] * m[9];

    inv[1] = -m[1] * m[10] * m[15] +
        m[1] * m[11] * m[14] +
        m[9] * m[2] * m[15] -
        m[9] * m[3] * m[14] -
        m[13] * m[2] * m[11] +
        m[13] * m[3] * m[10];

    inv[5] = m[0] * m[10] * m[15] -
        m[0] * m[11] * m[14] -
        m[8] * m[2] * m[15] +
        m[8] * m[3] * m[14] +
        m[12] * m[2] * m[11] -
        m[12] * m[3] * m[10];

    inv[9] = -m[0] * m[9] * m[15] +
        m[0] * m[11] * m[13] +
        m[8] * m[1] * m[15] -
        m[8] * m[3] * m[13] -
        m[12] * m[1] * m[11] +
        m[12] * m[3] * m[9];

    inv[13] = m[0] * m[9] * m[14] -
        m[0] * m[10] * m[13] -
        m[8] * m[1] * m[14] +
        m[8] * m[2] * m[13] +
        m[12] * m[1] * m[10] -
        m[12] * m[2] * m[9];

    inv[2] = m[1] * m[6] * m[15] -
        m[1] * m[7] * m[14] -
        m[5] * m[2] * m[15] +
        m[5] * m[3] * m[14] +
        m[13] * m[2] * m[7] -
        m[13] * m[3] * m[6];

    inv[6] = -m[0] * m[6] * m[15] +
        m[0] * m[7] * m[14] +
        m[4] * m[2] * m[15] -
        m[4] * m[3] * m[14] -
        m[12] * m[2] * m[7] +
        m[12] * m[3] * m[6];

    inv[10] = m[0] * m[5] * m[15] -
        m[0] * m[7] * m[13] -
        m[4] * m[1] * m[15] +
        m[4] * m[3] * m[13] +
        m[12] * m[1] * m[7] -
        m[12] * m[3] * m[5];

    inv[14] = -m[0] * m[5] * m[14] +
        m[0] * m[6] * m[13] +
        m[4] * m[1] * m[14] -
        m[4] * m[2] * m[13] -
        m[12] * m[1] * m[6] +
        m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] +
        m[1] * m[7] * m[10] +
        m[5] * m[2] * m[11] -
        m[5] * m[3] * m[10] -
        m[9] * m[2] * m[7] +
        m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] -
        m[0] * m[7] * m[10] -
        m[4] * m[2] * m[11] +
        m[4] * m[3] * m[10] +
        m[8] * m[2] * m[7] -
        m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] +
        m[0] * m[7] * m[9] +
        m[4] * m[1] * m[11] -
        m[4] * m[3] * m[9] -
        m[8] * m[1] * m[7] +
        m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] -
        m[0] * m[6] * m[9] -
        m[4] * m[1] * m[10] +
        m[4] * m[2] * m[9] +
        m[8] * m[1] * m[6] -
        m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det != 0)
    {
        for (int i = 0; i < 16; i++)
        {
            m[i] = inv[i] * (1.0 / det);
        }
    }
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
	for (int t = 0; t < 16; t++) { temp[t] = 0; }

	int k = 0;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i] = temp[i] +( m[j + 4*k] * n[((j+ 4 * k) - 4 * k) * 4 + (i%4)]);
		}

		if ((i+1)%4==0)
		{
			k++;
		}
	}
	
	Matrix4d out(temp);
	return out;
}

float& Matrix4d::operator[](int n) {
	return m[n];
}




