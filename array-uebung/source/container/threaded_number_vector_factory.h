//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once

#include <vector>
#include "vector_factory.h"
#include "../generators/number_generator_factory.h"

namespace vw::container {
    class threaded_number_vector_factory : public vector_factory<int> {

    public:
        threaded_number_vector_factory(generators::number_generator_factory &numberGeneratorFactory,
                                       size_t workerCount);

        auto create(std::size_t elementCount) -> std::vector<int> override;

    private:

        vw::generators::number_generator_factory &numberGeneratorFactory_;
        std::size_t workerCount_;
        std::vector<std::thread> threadHolder_;
        std::size_t partitionSize_;

        auto calculatePartitionSize(size_t count) -> void;

        auto initializeThreadHolder()  -> void;

        auto addWorkersToThreads( std::vector<int> &result)  -> void;

        auto joinThreads() -> void;

        auto  start_single_worker_for_segment(std::vector<std::int32_t> &result,const unsigned int segment) -> void;

        auto fill_segment_worker(std::vector<std::int32_t> &result, std::size_t startIndex, std::size_t endIndexIndex) -> void;
    };
}




