#include "Vector4d.h"
#include<stdio.h>
#include<math.h>
#include<iostream>
#pragma once

//

float v[4];

Vector4d::Vector4d() {

}


//get/set
	//x
float Vector4d::get(int xyzw) { return v[xyzw]; }
void Vector4d::set(int xyzw, float value) { v[xyzw] = value; }



//functions
void Vector4d::print() {
	std::cout << "[" << v[0] <<", "<< v[1] << ", "<< v[2] <<", "<< v[3] <<"]"<< std::endl;
}

float Vector4d::leanght(){
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}

float Vector4d::normalize(){
	return ((v[0] * v[1] * v[2] * v[3]) / this->leanght());
}

float Vector4d::dotProduct(Vector4d w){
	return (v[0] * w.get(0) +v[1] * w.get(1) + v[2] * w.get(2) + v[3] * w.get(3));
}

Vector4d Vector4d::crossProduct(Vector4d w) {
	Vector4d temp;
	temp.set(0, ((v[1] * w.get(2)) - (v[2] * w.get(1))));
	temp.set(1,( (v[2] * w.get(0))-(v[0] * w.get(2))  ));
	temp.set(2,((v[0] * w.get(1)) - (v[1] * w.get(0))));

	return temp;
}
//overided function

Vector4d Vector4d::operator+(Vector4d w) {

	Vector4d temp;

	temp.set(0, (v[0] + w.get(0)));
	temp.set(1, (v[1] + w.get(1)));
	temp.set(2, (v[2] + w.get(2)));
	temp.set(3, (v[3] + w.get(3)));

	return temp;
}

Vector4d Vector4d::operator-(Vector4d w){
	Vector4d temp;

	temp.set(0, (v[0] - w.get(0)));
	temp.set(1, (v[1] - w.get(1)));
	temp.set(2, (v[0] - w.get(2)));
	temp.set(3, (v[3] - w.get(3)));

	return temp;

}

Vector4d Vector4d::operator*(float n) {
	Vector4d temp;

	temp.set(0, (v[0] * n));
	temp.set(1, (v[1] * n));
	temp.set(2, (v[2] * n));
	temp.set(3, (v[3] * n));

	return temp;

}
float& Vector4d::operator[](int n) {
	return v[n];
}