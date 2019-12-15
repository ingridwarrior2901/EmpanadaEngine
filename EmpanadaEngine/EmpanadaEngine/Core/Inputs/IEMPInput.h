//
//  IEMPInput.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef IEMPInput_h
#define IEMPInput_h

#include <iostream>
#include "../Game/EMPGameConfiguration.h"
#include "../../Lib/Common/glm/glm/glm.hpp"


namespace EmpanadaEngine
{
    class IEMPInput
    {
    public:
        //------------------------------------------------------------/
        IEMPInput(void *window) {}
        virtual ~IEMPInput() {}
        //------------------------------------------------------------/
        virtual bool IsKeyPressed(unsigned int key) = 0;
        virtual bool IsKeyDown(unsigned int key) = 0;
        virtual glm::vec2 GetMousePosition() = 0;
    };
}

#endif /* IEMPInput_h */
