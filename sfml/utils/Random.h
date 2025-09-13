//
// Created by luiza on 13/09/2025.
//

#pragma once
#include <random>
#include <type_traits>

namespace Random {
    template<typename T>
    inline T get(T min, T max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        if constexpr (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> dist(min, max);
            return dist(gen);
        } else {
            std::uniform_real_distribution<T> dist(min, max);
            return dist(gen);
        }
    }
}