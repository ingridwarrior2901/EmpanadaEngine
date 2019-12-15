//
//  EMPCharacter.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPCharacter_hpp
#define EMPCharacter_hpp

#include "../Render/IEMPTexture.h"

namespace EmpanadaEngine
{
    struct EMPCharacter
    {
        IEMPTexturePTR texture;
        glm::ivec2 size;
        glm::ivec2 bearing;
        unsigned int horizontalOffset;
    };
}
#endif /* EMPCharacter_hpp */
