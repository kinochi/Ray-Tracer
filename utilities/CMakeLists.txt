add_library(
	utilities
	src/sphere.hpp
	src/sphere.cpp
	src/hitable_list.hpp
	src/hitable_list.cpp
)

target_include_directories(utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
