//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
namespace vw::generators {
    template<class T>
    class item_generator {
    public:
        ~item_generator() = default;

        virtual T next_item() const = 0;
    };
}




