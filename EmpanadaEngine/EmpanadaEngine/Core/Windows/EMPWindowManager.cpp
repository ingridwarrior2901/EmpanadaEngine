//
//  EMPWindow.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPWindowManager.h"
#include "EMPWindowFactory.h"

namespace EmpanadaEngine
{
    EMPWindowManager::EMPWindowManager(const EMPWindowConfiguration& windowInfo): m_windowInfo(windowInfo)
    {
        m_windowInfo = windowInfo;
        m_interface = IEMPWindowPTR(EMPWindowFactory::Build(windowInfo));
    }
}
