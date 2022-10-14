//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include "../container/vector_factory.h"
#include "../time/stopwatch.h"


class measurement_application {
public:

    measurement_application(vw::time::stopwatch &stopwatch, vw::container::vector_factory<int> &factory);

    auto get_duration()  {
        stopwatch.start();
        std::vector<int> v = factory.create(INT_MAX/10);
        stopwatch.stop();
        return stopwatch.elapsedDuration().count();
    }

private:
    vw::time::stopwatch &stopwatch;
    vw::container::vector_factory<int> &factory;
};




