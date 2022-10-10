cmake_minimum_required (VERSION 3.12)

project(StapelProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




add_executable(
	StapelProjekt 
	source/main.cpp 
	source/stapel.cpp
	source/stapel.h
	source/staper_exception.h
)


# Add tests
add_subdirectory(tests)

