//
//  EMPVertex.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPVertex_h
#define EMPVertex_h

#include "../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    struct EMPVertex
    {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 textureCoord;
    };
}

#endif /* EMPVertex_h */
