cmake_minimum_required(VERSION 3.20)
project(array_uebung)

set(CMAKE_CXX_STANDARD 17)

add_executable(array_uebung main.cpp source/time/stopwatch.h source/time/stopwatch_impl.cpp source/time/stopwatch_impl.h source/generators/item_generator.h source/generators/number_generator.h source/random/mersenne_twister_number_generator.h source/generators/number_generator_factory.h source/random/mersenne_twister_number_generator_factory.h source/container/vector_factory.h source/container/threaded_number_vector_factory.cpp source/container/threaded_number_vector_factory.h source/application/measurement_application.cpp source/application/measurement_application.h)
