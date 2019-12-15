//
//  EMPEventDelegate.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/23/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPEventDelegate_h
#define EMPEventDelegate_h

#include "EMPEvent.h"

namespace EmpanadaEngine
{
    class EMPEventDelegate
    {
    public:
        virtual void OnWindowSizeChange(EMPEvent& event) {}
        virtual void OnWindowClose(EMPEvent& event) {}
        virtual void OnMousePressed(EMPEvent& event) {}
        virtual void OnCursorChanged(EMPEvent& event) {}
        virtual void OnKeyChanged(EMPEvent& event) {}
    };
}

#endif /* EMPEventDelegate_h */
