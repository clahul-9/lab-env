#pragma once
class Vector4d
{
private:
	float v[4];
public:
	Vector4d(float x, float y, float z, float w = 0 );
	Vector4d();

	float leanght();
	float normalize();
	float dotProduct(Vector4d v);
	Vector4d crossProduct(Vector4d v);
	void print();

	Vector4d operator+(Vector4d v);
	Vector4d operator-(Vector4d v);
	Vector4d operator*(float n);
	float& operator[](int n);

};

