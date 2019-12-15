//
//  EMPEvent.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPEvent_h
#define EMPEvent_h

namespace EmpanadaEngine
{
    enum class EMPEventType
    {
        //Key types
        EMPInputKeyPressed, EMPInputKeyReleased, EMPInputKeyRepeat,
        
        //Mouse types
        EMPInputMouseButtonPressed, EMPInputMouseButtonReleased, EMPInputMouseCursorChange,
        
        //Windows types
        EMPWindowClose, EMPWindowResize
    };

    class EMPEvent
    {
    public:
        EMPEvent(EMPEventType eventType): m_eventType(eventType) {}
        //------------------------------------------------------------/
        bool isEventEnable = true;
        //------------------------------------------------------------/
        virtual EMPEventType GetEventType() { return m_eventType; }
    private:
        EMPEventType m_eventType;
    };

}

#endif /* EMPEvent_h */
