#ifndef RAHH
#define RAYH
#include "vec3.hpp"

class ray
{
	public:
		vec3 o;
		vec3 d;
		ray() {}
		ray(const vec3& A, const vec3& B) : o(A), d(B){}
		vec3 origin() const {return o;}
		vec3 direction() const {return d;}
		vec3 point_at_parameter(float t)  {return o + t*d ;}
};
#endif
