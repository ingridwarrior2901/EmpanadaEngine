//
//  EMPTimer.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPTimer_h
#define EMPTimer_h

namespace EmpanadaEngine
{
    class IEMPTimer
    {
    public:
        //------------------------------------------------------------/
        IEMPTimer() {}
        virtual ~IEMPTimer() {}
        //------------------------------------------------------------/
        virtual void SetMaxFps(unsigned int fps) = 0;
        virtual int GetFPS() const = 0;
        virtual float GetFrameRate() const = 0;
        virtual float GetDeltaTime() const = 0;
        virtual void CalculateTime() = 0;
        virtual void CalculateLastTime() = 0;
    };
}

#endif /* EMPTimer_h */
