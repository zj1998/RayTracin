#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"

struct hit_record;

class material {
public:
    
    virtual bool scatter(
        const ray& r_in,const hit_record& rec, color& attenuation, ray& scattered
    ) const = 0;
};



class lambertian :public material {
public:
    
    lambertian(const color& albe) :albedo(albe) {}
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    )const override {
        auto scatter_direction = rec.normal + random_unit_vector();
        scattered = ray(rec.p,scatter_direction);
        attenuation = albedo;
        return true;
    
    }
private:
    color albedo;
};



class metal : public material {
public:
    metal(const color& a) : albedo(a) {}

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

public:
    color albedo;
};


class dielectric :public material {
public:
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const override {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

        vec3 unit_direction = unit_vector(r_in.direction());
        vec3 refracted = refract(unit_direction, rec.normal, refraction_ratio);

        scattered = ray(rec.p, refracted);
        return true;

    }

private:
    double ir;
};
#endif