#include <iostream>
#include <ray.hpp>
#include <vec3.hpp>

/*
 *	If ray intersects returns the parameter for the intersection
 *	else returns -1.0f to denote no intersection
 */

float hit_sphere(vec3 center, float radius, const ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(r.direction(), oc);
    float c = dot(oc, oc) - radius * radius;
    float discr = b * b - 4 * a * c;
    if (discr < 0) {
        return -1.0;
    }
    return (-b - sqrt(discr)) / (2.0 * a);
}

/*
 * For getting the color for the current ray
 * */

vec3 color(const ray& r) {
    // If it hits the sphere color the sphere
    float t = hit_sphere(vec3(0.0, 0.0, -1.0), 0.25, r);
    if (t >= 0.0f) {
        vec3 N = unit_vector(r.point_at_parameter(t) - vec3(0, 0, -1));
		// Color a nice normal map to visualize them
        return 0.5 * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }

    // If does not hit any entity then put a nice gradient behind it
    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5 * (unit_direction.y()) + 1.0f;
    return (1.0 - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    int nx = 1366;
    int ny = 768;
    float screen_ratio = float(nx) / float(ny);

    std::ios_base::sync_with_stdio(0);
    std::cout << "P3\n" << nx << ' ' << ny << "\n255\n";
    vec3 lower_left_corner(-screen_ratio / 2.0, -0.5f, -1.0f);

    vec3 horizontal(screen_ratio, 0.0f, 0.0f);
    vec3 vertical(0.0f, 1.0f, 0.0f);
    vec3 origin(0.0f, 0.0f, 0.0f);

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
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
