#include <iostream>
#include <ray.hpp>
#include <vec3.hpp>

bool hit_sphere(vec3 center, float radius, const ray& r) {
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(r.direction(), r.origin() - center);
    float c = dot(r.origin() - center, r.origin() - center) - radius * radius;
    float discr = b * b - 4 * a * c;
    return discr >= 0;
}

/*
 * For getting the color for the current ray
 * */
vec3 color(const ray& r) {
	// If it hits the sphere color the sphere 
    if (hit_sphere(vec3(0.0, 0.0, -1.0), 0.25, r)) return vec3(0.0, 0.0, 0.0);

	// If does not hit any entity then put a nice gradient behind it
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y()) + 1.0f;
    return (1.0 - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    int nx = 800;
    int ny = 400;
    std::ios_base::sync_with_stdio(0);
    std::cout << "P3\n" << nx << ' ' << ny << "\n255\n";
    vec3 lower_left_corner(-1.0f, -1.0f, -1.0f);
    vec3 horizontal(2.0f, 0.0f, 0.0f);
    vec3 vertical(0.0f, 2.0f, 0.0f);
    vec3 origin(0.0f, 0.0f, 0.0f);
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float u = float(i) / float(ny);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 col = color(r);
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    return 0;
}
