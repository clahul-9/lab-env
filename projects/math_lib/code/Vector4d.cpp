#include "Vector4d.h"
#include<stdio.h>
#include<math.h>
#include<iostream>
#pragma once

//

float v[4];

Vector4d::Vector4d(float x, float y, float z, float w) {
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = w;

}

Vector4d::Vector4d(){}



//functions

float Vector4d::leanght(){
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}

float Vector4d::normalize(){
	return ((v[0] * v[1] * v[2] * v[3]) / this->leanght());
}

float Vector4d::dotProduct(Vector4d w){
	return (v[0] * w[0] +v[1] * w[1] + v[2] * w[2] + v[3] * w[3]);
}

Vector4d Vector4d::crossProduct(Vector4d w) {
	Vector4d temp;
	temp[0] = (v[1] * w[2] - v[2] * w[1]);
	temp[1] = (v[2] * w[0] - v[0] * w[2]);
	temp[2] = (v[0] * w[1] - v[1] * w[0]);

	return temp;
}
//overided function

Vector4d Vector4d::operator+(Vector4d w) {

	Vector4d temp;

	temp[0] = (v[0] + w[0]);
	temp[1] = (v[1] + w[1]);
	temp[2] = (v[2] + w[2]);
	temp[3] = (v[3] + w[3]);

	return temp;
}

Vector4d Vector4d::operator-(Vector4d w){
	Vector4d temp;

	temp[0] = (v[0] - w[0]);
	temp[1] = (v[1] - w[1]);
	temp[2] = (v[0] - w[2]);
	temp[3] = v[3] - w[3];

	return temp;

}

Vector4d Vector4d::operator*(float n) {
	Vector4d temp;

	temp[0] = (v[0] * n);
	temp[1] = (v[1] * n);
	temp[2] = (v[2] * n);
	temp[3] = (v[3] * n);

	return temp;

}
float& Vector4d::operator[](int n) {
	return v[n];
}