#ifndef SPHEREH
#define SPHEREH

#include "hitable.hpp"
#include "material.hpp"
#include <memory>

class sphere: public hitable{
	public:
		vec3 center;
		float radius;
		std::shared_ptr<material> mat_ptr;
		sphere() {}
		sphere(vec3 center, float r, std::shared_ptr<material> mat_ptr) : center(center) , radius(r), mat_ptr(mat_ptr){}
		virtual bool hit (const ray& r, float tmin, float tmax, hit_record& rec) const override;
};

#endif
