//
// Created by JoachimWagner on 14.10.2022.
//
#include <cmath>
#include <thread>
#include "threaded_number_vector_factory.h"
namespace vw::container {



    auto threaded_number_vector_factory::calculatePartitionSize(size_t elementCount) ->void {
        partitionSize_ =  static_cast<std::size_t>(std::floor(elementCount / workerCount_));
    }

    auto  threaded_number_vector_factory::initializeThreadHolder()  -> void{
        threadHolder_ =  std::vector<std::thread> {};
        threadHolder_.reserve(workerCount_);


    }

    std::vector<std::int32_t> threaded_number_vector_factory::create(std::size_t elementCount)  {
        auto result = std::vector<std::int32_t>(elementCount);
        calculatePartitionSize(elementCount);

        initializeThreadHolder();

        addWorkersToThreads(result);
        joinThreads();

        return result;
    }

    auto threaded_number_vector_factory::addWorkersToThreads(std::vector<std::int32_t>& result)  -> void
    {


        for (auto segment = 0U; segment < workerCount_; ++segment) {
            start_single_worker_for_segment(result, segment);
        }
    }

    void threaded_number_vector_factory::start_single_worker_for_segment( std::vector<std::int32_t> &result,unsigned int segment)  {
        threadHolder_.emplace_back(
                [this, &result](auto const startIndex, auto const endIndex) {
                    auto const numberGenerator = numberGeneratorFactory_.create();

                    for (auto i = startIndex; i < endIndex; ++i) {
                        result[i] = numberGenerator->next_item();
                    }
                },
                segment * partitionSize_, (segment + 1) * partitionSize_);

    }



    auto threaded_number_vector_factory::joinThreads() -> void
    {
        for (auto& thread : threadHolder_) {
            thread.join();
        }
    }

    auto threaded_number_vector_factory::fill_segment_worker(std::vector<std::int32_t> &result, std::size_t startIndex, std::size_t endIndex) -> void {
        auto const numberGenerator = numberGeneratorFactory_.create();

        for (auto i = startIndex; i < endIndex; ++i) {
            result[i] = numberGenerator->next_item();
        }
    }

    threaded_number_vector_factory::threaded_number_vector_factory(
            generators::number_generator_factory &numberGeneratorFactory, size_t workerCount) : numberGeneratorFactory_(
            numberGeneratorFactory), workerCount_(workerCount) {}




}