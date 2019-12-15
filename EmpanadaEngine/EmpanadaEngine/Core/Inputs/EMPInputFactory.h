//
//  EMPInputFactory.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPInputFactory_h
#define EMPInputFactory_h

#include "IEMPInput.h"
#include "EMPInputGLFW.h"

namespace EmpanadaEngine
{
    class EMPInputFactory
    {
    public:
        static IEMPInput *Build(API::EMPInterfaceType interfaceType, void *windowReference)
        {
            switch (interfaceType)
            {
                case API::EMPInterfaceType::GLFW:
                    return new EMPInputGLFW(windowReference);
            }
            return nullptr;
        }
    };
}

#endif /* EMPInputFactory_h */
