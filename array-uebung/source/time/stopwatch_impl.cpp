//
// Created by JoachimWagner on 14.10.2022.
//

#include "stopwatch_impl.h"
namespace vw::time {
    void stopwatch_impl::start() {
        startTime_ = std::chrono::high_resolution_clock::now();
    }

    void stopwatch_impl::stop() {
        endTime_ = std::chrono::high_resolution_clock::now();
    }

    std::chrono::milliseconds stopwatch_impl::elapsedDuration() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime_ - startTime_);
    }
}