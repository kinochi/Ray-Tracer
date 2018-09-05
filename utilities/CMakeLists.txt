add_library(
	utilities
	include/vec3.hpp
	include/ray.hpp
	include/camera.hpp
	include/hitable.hpp
	include/sphere.hpp
	include/hitable_list.hpp
	include/material.hpp
	include/lambertian.hpp
	include/specular.hpp
	src/sphere.cpp
	src/hitable_list.cpp
)

target_include_directories(utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
