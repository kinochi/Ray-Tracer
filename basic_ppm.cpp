#include <iostream>
#include "vec3.hpp"

int main() {
	int nx = 200;
	int ny = 100;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	for(int j = ny-1; j >= 0; j--){
		for(int i = 0; i < nx; i++){
			vec3 col(float(i)/nx, float(j)/ny, 0.2f);
			col*=255.99;
			int ir = int(col.r());
			int ig = int(col.g());
			int ib = int(col.b());
			std::cout << ir << ' ' << ig << ' ' << ib << ' ' << '\n';
		}
	}
}
