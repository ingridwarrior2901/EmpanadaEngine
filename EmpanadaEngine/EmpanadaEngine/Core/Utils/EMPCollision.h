//
//  EMPCollision.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/7/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPCollision_h
#define EMPCollision_h

#include "../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    struct EMPCollisionObject
    {
        glm::vec2 position;
        glm::vec2 size;
    };
 
    class EMPCollision
    {
    private:
        static bool ValueInRange(double value, double min, double max)
        {
            return (value >= min) && (value <= max);
        }
        
    public:
        
        static bool isOverlappingRect(EMPCollisionObject objectOne, EMPCollisionObject objectTwo)
        {
            bool collisionX = ValueInRange(objectTwo.position.x, objectOne.position.x, objectOne.position.x + objectOne.size.x);
            bool collisionY = ValueInRange(objectOne.position.y, objectTwo.position.y, objectTwo.position.y + objectTwo.size.y) || ValueInRange(objectTwo.position.y, objectOne.position.y, objectOne.position.y + objectOne.size.y);
            
            return collisionX && collisionY;
        }
    };
}

#endif /* EMPCollision_h */
