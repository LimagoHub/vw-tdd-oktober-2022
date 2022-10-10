cmake_minimum_required (VERSION 3.12)

project(SchweinProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




add_executable(
	SchweinProjekt 
	source/main.cpp  
 "source/schwein.h")


# Add tests
add_subdirectory(tests)

