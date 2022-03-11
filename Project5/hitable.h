#pragma once
#include"ray.h"

struct hitrecond {
	point3 p;
	vec3 normal;
	double t;
};

class hittable {
	virtual bool hit()const = 0;
};