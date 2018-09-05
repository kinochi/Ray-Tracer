#ifndef SPECULARH
#define SPECULARH

#include "material.hpp"

vec3 reflect(const vec3 &v, const vec3 &normal) {
    return v - 2.0 * dot(normal, v) * normal;
}
class specular : public material{
  public:
    specular(const vec3 &albedo) : albedo(albedo) {}
    bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation,
                 ray &scattered) const override {
        vec3 reflected_direction = reflect(r_in.direction(), rec.normal).make_unit_vector();
        scattered = ray(rec.p, reflected_direction);
        attenuation = albedo;
        return dot(scattered.direction(),rec.normal) > 0;
    }
    vec3 albedo;
};
#endif
