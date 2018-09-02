#ifndef RAYH
#define RAYH
#include "vec3.hpp"

class ray
{
    public:
		vec3 o;
		vec3 d;
        ray() {}
        ray(const vec3& a, const vec3& b) : o(a), d(unit_vector(b)){}  
        vec3 origin() const       { return o; }
        vec3 direction() const    { return d; }
        vec3 point_at_parameter(float t) const { return o + t*d; }

};

#endif 


