//
//  EMPTimerGLFW.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPTimerGLFW_hpp
#define EMPTimerGLFW_hpp

#include "IEMPTimer.h"

namespace EmpanadaEngine
{
    class EMPTimerGLFW: public IEMPTimer
    {
    public:
        //------------------------------------------------------------/
        EMPTimerGLFW();
        virtual ~EMPTimerGLFW() {}
        //------------------------------------------------------------/
        virtual void SetMaxFps(unsigned int fps) override;
        virtual int GetFPS() const override { return m_fps; }
        virtual float GetFrameRate() const override { return 1.0f / static_cast<float>(m_fps); }
        virtual float GetDeltaTime() const override { return  static_cast<float>(m_deltaTime); }
        //------------------------------------------------------------/
        virtual void CalculateTime() override;
        virtual void CalculateLastTime() override;
        //------------------------------------------------------------/
    private:
        unsigned int m_fps;
        double m_deltaTime;
        double m_lastTime;
    };
}

#endif /* EMPTimerGLFW_hpp */
