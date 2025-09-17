

#include <map>
#include "SFML/System/Vector2.hpp"

enum class GameVelocity{
    regular,
    slow,
    fast
};

inline const std::map<GameVelocity, sf::Vector2f>& VelocityMap ={
        {GameVelocity::regular,   sf::Vector2f(2.5f,2.5f)},
        {GameVelocity::slow,   sf::Vector2f(0.25f,0.25f)},
        {GameVelocity::fast,   sf::Vector2f(5.0f,5.0f)}
};