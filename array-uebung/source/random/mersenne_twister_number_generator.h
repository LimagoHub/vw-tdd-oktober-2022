//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
#include <random>
#include <climits>
#include "../generators/number_generator.h"
namespace vw::generators {
    class mersenne_twister_number_generator: public number_generator {
    public:
        explicit mersenne_twister_number_generator()
        : device_ {}
        , rng_ { device_() }
        , distribution_(INT_MIN, INT_MAX)
        {
            // NOOP
        }

        [[nodiscard]] auto next_item() const -> std::int32_t override { return distribution_(rng_); }

    private:
        std::random_device device_;
        mutable std::mt19937 rng_;
        std::uniform_int_distribution<std::int32_t> distribution_;
    };

}




