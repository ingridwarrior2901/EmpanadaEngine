//
//  EMPWindowEvent.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPWindowEvent_h
#define EMPWindowEvent_h

#include "EMPEvent.h"
#include "../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    class EMPWindowResizeEvent : public EMPEvent
    {
    public:
        EMPWindowResizeEvent(glm::vec2 windowSize)
            : m_windowSize(windowSize), EMPEvent(EMPEventType::EMPWindowResize) {}

        inline glm::vec2 GetWindowSize() const { return m_windowSize; }
        
    private:
       glm::vec2 m_windowSize;
    };

    class EMPWindowCloseEvent : public EMPEvent
    {
    public:
        EMPWindowCloseEvent() : EMPEvent(EMPEventType::EMPWindowClose) {}
    };
}

#endif /* EMPWindowEvent_h */
