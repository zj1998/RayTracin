#pragma once
#include"vec.h"
#include"hitable.h"

class sphere :public hittable {
public:
	sphere(vec3 cen,double rad):center(cen),radius(rad) {};
	virtual bool hit(const ray &r ,double t_min,double t_max,hit_record &rec)const override;

private:
	vec3 center;
	double radius;
};