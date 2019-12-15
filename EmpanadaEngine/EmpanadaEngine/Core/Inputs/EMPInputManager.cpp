//
//  EMPInputManager.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPInputManager.h"
#include "EMPInputFactory.h"

namespace EmpanadaEngine
{
    EMPInputManager::EMPInputManager(API::EMPInterfaceType interfaceType, void* windowReference)
    {
        m_interface = IEMPInputPTR(EMPInputFactory::Build(interfaceType, windowReference));
    }
}
