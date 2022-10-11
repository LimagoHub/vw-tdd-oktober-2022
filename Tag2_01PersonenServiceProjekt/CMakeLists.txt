cmake_minimum_required (VERSION 3.12)

project(PersonenService)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




add_executable(PersonenService source/main.cpp  
"source/persistence/person.h" 
"source/persistence/personen_repository.h" 
"source/service/personen_service_impl.h" 
"source/service/personen_service_exception.h"

)


# Add tests
add_subdirectory(tests)

