//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once
namespace vw::container {
    template<class T>
    class vector_factory {
    public:
        virtual ~vector_factory() = default;

        [[nodiscard]] virtual auto create(std::size_t elementCount) -> std::vector <T> = 0;
    };
}




