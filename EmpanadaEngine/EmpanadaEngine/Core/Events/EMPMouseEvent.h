//
//  EMPMouseEvent.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPMouseEvent_h
#define EMPMouseEvent_h

#include "EMPEvent.h"
#include "../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    class EMPMousePressedEvent : public EMPEvent
    {
    public:
        EMPMousePressedEvent(EMPEventType eventType) : EMPEvent(eventType) {}
    };

    class EMPCursorChangeEvent : public EMPEvent
    {
    public:
        EMPCursorChangeEvent(glm::vec2 cursorPosition) : m_cursorPosition(cursorPosition), EMPEvent(EMPEventType::EMPInputMouseCursorChange) {}
        
        inline glm::vec2 GetCursorPosition() const { return m_cursorPosition; }
    private:
        glm::vec2 m_cursorPosition;
    };
}

#endif /* EMPMouseEvent_h */
