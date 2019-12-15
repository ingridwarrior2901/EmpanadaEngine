//
//  EMPTimerManager.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/26/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPTimerManager_h
#define EMPTimerManager_h

#include "EMPGameConfiguration.h"
#include "EMPTimerGLFW.h"

namespace EmpanadaEngine
{
    class EMPTimerManager
    {
    public:
        static std::unique_ptr<IEMPTimer> LoadTimer(API::EMPInterfaceType interfaceType)
        {
                switch (interfaceType)
                {
                    case API::EMPInterfaceType::GLFW:
                        return std::make_unique<EMPTimerGLFW>();
                }
            
            return nullptr;
        }
    };
}


#endif /* EMPTimerManager_h */
