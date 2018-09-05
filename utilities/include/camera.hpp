#ifndef CAMERAH
#define CAMERAH

#include "ray.hpp"

class camera {
  public:
    float screen_ratio;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 origin;
    camera() {}
    camera(float sc)
        : screen_ratio(sc),
          lower_left_corner(-screen_ratio / 2.0, -0.5f, -1.0f),
          horizontal(1.0f, 0.0f, 0.0f),
          vertical(0.0f, 1.0f, 0.0f),
          origin(0.0f, 0.0f, 0.0f) {}
    ray get_ray(float u, float v) {
        return ray(origin, lower_left_corner + u * horizontal + v * vertical);
    }
};

#endif
