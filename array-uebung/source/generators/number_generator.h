//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
#include "item_generator.h"
namespace vw::generators {
    class number_generator : public item_generator<std::int32_t> {
    public:
        int32_t next_item() const  override = 0;
    };
}




