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
    vec3& operator= (vec3& v) ;
	double& operator[](int i) {
		return this->e[i];
	}
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

private:
	double e[3];
};

using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

inline vec3& vec3::operator=(vec3 &v) {
    (*this).e[0] = v[0];
    (*this).e[1] = v[1];
    (*this).e[2] = v[2];
    return *this;
}
inline vec3 operator+(vec3 &v1,vec3 &v2) {
    vec3 sum = v1;
    sum += v2;
    return sum;
}
