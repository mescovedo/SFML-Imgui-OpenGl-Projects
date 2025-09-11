//
// Created by mats_ on 25/08/2025.
//

#include "CircleConfig.h"
#include "RectangleConfig.h"
#include "shapeFactory.h"
#include "SquareConfig.h"
#include "TriangleConfig.h"
#include "../external/sfml/include/SFML/Graphics/Color.hpp"
#include "../external/sfml/include/SFML/System/Vector2.hpp"

using json = nlohmann::json;

std::vector<std::unique_ptr<ShapeConfig>> ShapeFactory::loadShapes(const json& config) {
    std::vector<std::unique_ptr<ShapeConfig>> shapes;

    for (auto& obj : config["shapes"]) {
        std::string type = obj["type"];
        std::string name = obj["name"];
        const auto& colorArray = obj["color"];
        sf::Color color(colorArray[0], colorArray[1], colorArray[2]) ;
        sf::Vector2f pos(obj["position"][0], obj["position"][1]);
        sf::Vector2f velocity(obj["velocity"][0], obj["velocity"][1]);

        if (type == "circle") {
            auto shape = std::make_unique<CircleConfig>();
            shape->name = name;
            shape->color = color;
            shape->position = pos;
            shape->radius = obj["radius"];
            shape->velocity = velocity;
            shapes.push_back(std::move(shape));

        } else if (type == "square") {
            auto shape = std::make_unique<SquareConfig>();
            shape->name = name;
            shape->color = color;
            shape->position = pos;
            shape->size = obj["size"];
            shape->velocity = velocity;
            shapes.push_back(std::move(shape));

        } else if (type == "rectangle") {
            auto shape = std::make_unique<RectangleConfig>();
            shape->name = name;
            shape->color = color;
            shape->position = pos;
            shape->width = obj["width"];
            shape->height = obj["height"];
            shape->velocity = velocity;
            shapes.push_back(std::move(shape));

        } else if (type == "triangle") {
            auto shape = std::make_unique<TriangleConfig>();
            shape->name = name;
            shape->color = color;
            shape->position = pos;
            shape->size = obj["size"];
            shape->velocity = velocity;
            shapes.push_back(std::move(shape));
        }
    }

    return shapes;

}
