

#include <map>
#include "SFML/System/Vector2.hpp"

enum class TypeEntities{
    character,
    circle,
    triangle,
    square
};

struct ShapeProperties{
    int sides;
    int type;
    float rotation;
    int radius;
};

inline const std::map<TypeEntities , ShapeProperties>& MapShapes{
        {TypeEntities::character, ShapeProperties{8,0, 0, 20}},
        {TypeEntities::circle, ShapeProperties{100,1, 30, 20}},
        {TypeEntities::triangle, ShapeProperties{3,2, 30, 20}},
        {TypeEntities::square, ShapeProperties{4,3, 30, 20}}
};



