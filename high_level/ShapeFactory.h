//
// Created by mats_ on 25/08/2025.
//

#pragma once
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "ShapeConfig.h"

class ShapeFactory {
    public:
        static std::vector<std::unique_ptr<ShapeConfig>> loadShapes(const nlohmann::json& config);
};
