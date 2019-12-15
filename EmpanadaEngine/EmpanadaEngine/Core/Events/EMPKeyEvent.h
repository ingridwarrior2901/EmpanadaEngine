//
//  EMPKeyEvent.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPKeyEvent_h
#define EMPKeyEvent_h

#include "EMPEvent.h"

namespace EmpanadaEngine
{
    class EMPKeyEvent : public EMPEvent
    {
    public:
        //------------------------------------------------------------/
        EMPKeyEvent(EMPEventType eventType, unsigned int key) : m_key(key), EMPEvent(eventType) {}
        //------------------------------------------------------------/
        inline unsigned int GetKey() const { return m_key; }
        
    private:
        unsigned int m_key;
    };
}

#endif /* EMPKeyEvent_h */
