//
//  EMPWindowConfiguration.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPWindowConfiguration_h
#define EMPWindowConfiguration_h

#include "../Utils/EMPColor.h"
#include "../Game/EMPGameConfiguration.h"
#include <iostream>
#include <string>

namespace EmpanadaEngine
{
    struct EMPWindowConfiguration
    {
        //------------------------------------------------------------/
        std::string title;
        glm::vec2 windowSize;
        EMPColor backgroundColor;
        API::EMPInterfaceType windowAPI;
        //------------------------------------------------------------/
        EMPWindowConfiguration(API::EMPInterfaceType windowAPI, const std::string& title = "EmpanadaDemo",
                               glm::vec2 windowSize = glm::vec2(800.0f, 600.0f),
                               EMPColor backgroundColor = {glm::vec4(0.0f)})
        : title(title), windowSize(windowSize), backgroundColor(backgroundColor), windowAPI(windowAPI) { }
    };
}

#endif /* EMPWindowConfiguration_h */
