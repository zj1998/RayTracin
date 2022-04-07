#pragma once
#include"hitable.h"
#include<memory>
#include<vector>


using std::shared_ptr;
using std::make_shared;


class hittablelist:public hittable
{
public:
	hittablelist()=default;
	hittablelist(shared_ptr<hittable> object) { add(object); };
	~hittablelist() {};
	void clear() { objects.clear(); }
	void add(shared_ptr<hittable> object) { objects.push_back(object); };
	virtual bool hit(
		const ray& r, double t_min, double t_max, hit_record& rec)const override;
private:
	std::vector<shared_ptr<hittable>> objects;
};

