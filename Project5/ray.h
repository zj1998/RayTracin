#pragma once

#include"vec.h"


class ray
{
public:
		ray()=default;
		ray(const point3& org, const point3& di) :orig(org), dir(di) {};
		~ray() {};
		point3 origin() const { return orig; }
		vec3 direction() const { return dir; }

		point3 at(double t) const {
			return orig + t * dir;
		}

private:
	point3 orig;
	point3 dir;

};

 

