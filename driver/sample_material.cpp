#include <iostream>
#include <random>
#include "camera.hpp"
#include "hitable_list.hpp"
#include "lambertian.hpp"
#include "specular.hpp"
#include "sphere.hpp"

/*
 * For getting the color for the current ray
 * */

vec3 color(const ray& r, hitable* world, int depth) {
    hit_record temp;

    // If it hits the world
    if (world->hit(r, 0.001, MAXFLOAT, temp)) {
        vec3 attenuation;
        ray target;

        if (depth < 50 && temp.mat_ptr->scatter(r, temp, attenuation, target))
            return attenuation * color(target, world, depth + 1);

        return vec3(0.);
    }

    // If does not hit any entity then put a nice gradient behind it
    float t = 0.5 * (r.direction().y()) + 1.0f;
    return (1.0 - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main() {
    int nx = 800;
    int ny = 400;
    int ss = 10;
    float screen_ratio = float(nx) / float(ny);

    std::ios_base::sync_with_stdio(0);
    std::cout << "P3\n" << nx << ' ' << ny << "\n255\n";

    // Our World
    hitable_list* world = new hitable_list();
    world->add(std::make_unique<sphere>(
        sphere(vec3(0.0, 0.0, -1.0), 0.25,
               std::make_shared<lambertian>(vec3(0.8, 0.3, 0.3)))));
    world->add(std::make_unique<sphere>(
        sphere(vec3(0.0, -100.5, -1.0), 100,
               std::make_shared<lambertian>(vec3(0.8, 0.3, 0.3)))));
    world->add(std::make_unique<sphere>(
        sphere(vec3(1.0, 0, -1), 0.25,
               std::make_shared<specular>(vec3(0.8, 0.6, 0.2)))));
    world->add(std::make_unique<sphere>(
        sphere(vec3(-1, 0, -1), 0.25,
               std::make_shared<specular>(vec3(0.8, 0.8, 0.8)))));
    camera c(screen_ratio);

	// Tracing rays for each pixel
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            vec3 avg_col;
            for (int s = 0; s < ss; s++) {
                float u = float(i + drand48()) / float(ny);
                float v = float(j + drand48()) / float(ny);
                vec3 col = color(c.get_ray(u, v), world, 0);
                avg_col += col;
            }
            avg_col /= float(ss);
            avg_col =
                vec3(sqrt(avg_col[0]), sqrt(avg_col[1]), sqrt(avg_col[2]));
            int ir = int(255.99 * avg_col[0]);
            int ig = int(255.99 * avg_col[1]);
            int ib = int(255.99 * avg_col[2]);
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    delete world;
    return 0;
}
