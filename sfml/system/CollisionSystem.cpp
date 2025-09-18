#include <cmath>
#include "CollisionSystem.h"
#include "component/Moviment.h"
#include "component/Shape.h"


bool CollisionSystem::checkCollision(sf::Vector2f pos1, sf::Vector2f pos2, float angle1, float angle2) {

    sf::Vector2f vecRadius = sf::Vector2f(20, 20);

    sf::Vector2f rotatedPos1 = pos1;
    sf::Vector2f rotatedPos2 = pos2;

    float angleRad = angle1 * 3.14159265f / 180.f;
    float angleRad2 = angle2 * 3.14159265f / 180.f;

    // rotatedPos1.x += vecRadius.x * cos(angleRad);
    // rotatedPos1.y += vecRadius.y * sin(angleRad);
    // rotatedPos2.x += vecRadius.x * cos(angleRad2);
    // rotatedPos2.y += vecRadius.y * sin(angleRad2);

    rotatedPos1.x += vecRadius.x ;
    rotatedPos1.y += vecRadius.y;
    rotatedPos2.x += vecRadius.x;
    rotatedPos2.y += vecRadius.y ;

    float x = pos1.x - pos2.x;
    float y = pos1.y - pos2.y;
    float distanceSquared = x*x + y*y;
    float radiumsumSquared = 40*40;
    return distanceSquared <= radiumsumSquared;


}

bool CollisionSystem::collision(EntityManager &em) {

    auto entities = em.getEntities();

    for(size_t i=0; i < entities.size(); i++){

        for( size_t j = i+1; j < entities.size(); j++){

            Entity e1 = entities[i];
            Entity e2 = entities[j];

            if(checkCollision(em.getComponent<Position>(e1)->value, em.getComponent<Position>(e2)->value, em.getComponent<Rotation>(e1)->angle, em.getComponent<Rotation>(e2)->angle) ){

                int type1 = em.getComponent<Type>(e1)->value;
                int type2 = em.getComponent<Type>(e2)->value;

                if (type1 == 0){
                    em.getComponent<Visible>(e2)->value = false;
                } else if(type2 == 0){
                    em.getComponent<Visible>(e1)->value = false;
                }
            }

        }
    }
    return true;
}