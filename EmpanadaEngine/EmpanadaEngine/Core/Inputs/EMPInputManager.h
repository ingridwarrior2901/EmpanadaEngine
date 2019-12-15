//
//  EMPInputManager.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPInputManager_hpp
#define EMPInputManager_hpp

#include "IEMPInput.h"

namespace EmpanadaEngine
{
    using IEMPInputPTR = std::shared_ptr<IEMPInput>;
    
class EMPInputManager
    {
    public:
        //------------------------------------------------------------/
        EMPInputManager(API::EMPInterfaceType interfaceType, void* windowReference);
        ~EMPInputManager() {}
        //------------------------------------------------------------/
        IEMPInputPTR GetInputInterface() const { return m_interface; }
        //------------------------------------------------------------/
        
    private:
        IEMPInputPTR m_interface;
    };
    
}

#endif /* EMPInputManager_hpp */
