
#include <thread>
#include "source/random/mersenne_twister_number_generator.h"
#include "source/random/mersenne_twister_number_generator_factory.h"
#include "source/application/measurement_application.h"
#include "source/time/stopwatch_impl.h"
#include "source/container/threaded_number_vector_factory.h"
#include "source/random/mersenne_twister_number_generator_factory.h"
int main() {
    auto const maxWorkerCount = std::thread::hardware_concurrency() + 1;
    vw::time::stopwatch_impl stopwatch;
    vw::generators::mersenne_twister_number_generator_factory number_factory_;


    for(std::size_t workerCount_ = 1 ; workerCount_ <= maxWorkerCount; workerCount_ ++) {
        std::cout << "Messung mit " << workerCount_ << " Threads" << std::endl;
        vw::container::threaded_number_vector_factory factory = vw::container::threaded_number_vector_factory{number_factory_, workerCount_} ;
        measurement_application application{stopwatch, factory};
        auto duration = application.get_duration();
        std::cout << "Dauer: " <<  duration << std::endl;
    }




    return 0;
}
