cmake_minimum_required (VERSION 3.12)

project(SchweinProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




add_executable(
	SchweinProjekt 
	source/main.cpp  
	"source/schwein.h" 
	"source/calculator.h" 
	"source/calculator_client.h" "source/calulator_impl.h" "source/calculator_logger.h")


# Add tests
add_subdirectory(tests)

