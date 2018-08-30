#include <iostream>
#include "sphere.hpp"
#include "hitable_list.hpp"

/*
 * For getting the color for the current ray
 * */

vec3 color(const ray& r, hitable* world) {
	hit_record temp;

    // If it hits the world
    if (world->hit(r,0.0,MAXFLOAT,temp)) {
		// Color a nice normal map to visualize them
		return 0.5*vec3(temp.normal.z()+1.0f);
    }

    // If does not hit any entity then put a nice gradient behind it
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y()) + 1.0f;
    return (1.0 - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    int nx = 800;
    int ny = 600;
    float screen_ratio = float(nx) / float(ny);

    std::ios_base::sync_with_stdio(0);
    std::cout << "P3\n" << nx << ' ' << ny << "\n255\n";
    vec3 lower_left_corner(-screen_ratio / 2.0, -0.5f, -1.0f);

    vec3 horizontal(screen_ratio, 0.0f, 0.0f);
    vec3 vertical(0.0f, 1.0f, 0.0f);
    vec3 origin(0.0f, 0.0f, 0.0f);


	// Our World
	hitable *list[2];
	list[0] = new sphere(vec3(0.0,0.0,-1.0),0.25);
	list[1] = new sphere(vec3(0.0,-100.5,-1),100);
	hitable* world = new hitable_list(list,2);

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 col = color(r,world);
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return 0;
}
