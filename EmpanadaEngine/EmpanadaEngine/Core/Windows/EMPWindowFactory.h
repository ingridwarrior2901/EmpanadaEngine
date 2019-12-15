//
//  EMPWindowFactory.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPWindowFactory_h
#define EMPWindowFactory_h

#include "IEMPWindow.h"
#include "EMPWindowGLFW.h"

namespace EmpanadaEngine
{
    class EMPWindowFactory
    {
    public:
        static IEMPWindow *Build(const EMPWindowConfiguration& windowsInfo)
        {
            switch (windowsInfo.windowAPI)
            {
                case API::EMPInterfaceType::GLFW:
                    return new EMPWindowGLFW(windowsInfo);
            }
            return nullptr;
        }
    };
}

#endif /* EMPWindowFactory_h */
