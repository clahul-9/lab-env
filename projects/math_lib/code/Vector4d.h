#pragma once
class Vector4d
{
private:
	float v[4];
public:
	Vector4d();

	float get(int xyzw);
	void set(int xyzw, float value);

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

