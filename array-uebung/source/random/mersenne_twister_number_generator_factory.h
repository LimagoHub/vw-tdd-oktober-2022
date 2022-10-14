//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
#include <memory>
#include "mersenne_twister_number_generator.h"
#include "../generators/number_generator_factory.h"
namespace vw::generators {
    class mersenne_twister_number_generator_factory: public number_generator_factory{
    public:
        [[nodiscard]] auto create() const -> std::unique_ptr<number_generator> override
        {
            return std::make_unique<mersenne_twister_number_generator>();
        }
    };
}




