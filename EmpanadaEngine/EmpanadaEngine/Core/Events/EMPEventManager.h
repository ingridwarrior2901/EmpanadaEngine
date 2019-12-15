//
//  EMPEventManager.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPEventManager_hpp
#define EMPEventManager_hpp

#include "EMPEventDelegate.h"
#include "../Game/EMPSinglenton.h"
#include <iostream>
#include <map>
#include <vector>

namespace EmpanadaEngine
{
    using EMPEventDelegatePTR = std::shared_ptr<EMPEventDelegate>;

    class EMPEventManager: public EMPSinglenton<EMPEventManager>
    { 
    public:
        //------------------------------------------------------------/
        void Register(EMPEventType eventType, EMPEventDelegate *observer);
        void UnRegister(EMPEventType eventType, EMPEventDelegate *observer);
        void Notify(EMPEventType eventType, EMPEvent& event);
        //------------------------------------------------------------/
    private:
        std::map<EMPEventType, std::vector<EMPEventDelegate *>> m_observers;
    };
}

#endif /* EMPEventManager_hpp */
