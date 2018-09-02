#ifndef SPHEREH
#define SPHEREH

#include "hitable.hpp"

class sphere: public hitable{
	public:
		vec3 center;
		float radius;
		sphere() {}
		sphere(vec3 center, float r) : center(center) , radius(r){}
		virtual bool hit  (const ray& r, float tmin, float tmax, hit_record& rec) const override;
};

#endif
