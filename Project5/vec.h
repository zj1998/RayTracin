#pragma once
#include<cmath>
#include<iostream>



class vec3
{
public:
	vec3():e{0,0,0} {}
	vec3(double a, double b, double c) :e{ a,b,c } {}

	double x() { return e[0]; }
	double y() { return e[1]; }
	double z() { return e[2]; }

	vec3 operator-() { return { -e[0],-e[1] ,-e[2] }; }
	double operator[](int i) const {
		return e[i];
	}
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

private:
	double e[3];
};

using point3 = vec3;   // 3D point
using color = vec3;    // RGB color
