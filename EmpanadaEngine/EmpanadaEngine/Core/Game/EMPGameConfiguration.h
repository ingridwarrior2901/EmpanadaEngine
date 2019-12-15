//
//  EMPGameConfiguration.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPGameConfiguration_h
#define EMPGameConfiguration_h

namespace EmpanadaEngine
{

    namespace API
    {
        enum class EMPInterfaceType
        {
            GLFW
        };

        enum class EMPRenderType
        {
            OpenGL,
            Metal
        };
    }

    struct EMPGameConfiguration
    {
        //------------------------------------------------------------/
        API::EMPInterfaceType interfaceType;
        API::EMPRenderType renderType;
        //------------------------------------------------------------/
        EMPGameConfiguration(API::EMPInterfaceType interfaceType = API::EMPInterfaceType::GLFW,
                             API::EMPRenderType renderType = API::EMPRenderType::OpenGL)
        : interfaceType(interfaceType), renderType(renderType) { }
    };
}

#endif /* EMPGameConfiguration_h */
