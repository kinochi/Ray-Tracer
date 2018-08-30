#include "sphere.hpp"

bool sphere::hit(const ray &r, float tmin, float tmax, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(r.direction(), oc);
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0) {
        float sqrdiscr = sqrt(discriminant);
        float root1 = (-b - sqrdiscr) / a;
        float root2 = (-b + sqrdiscr) / a;
        float temp = root1 < tmax && root1 > tmin
                         ? root1
                         : root2 < tmax && root2 > tmin ? root2 : tmax + 0.1;
        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(temp);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}
