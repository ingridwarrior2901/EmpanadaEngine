//
//  EMPTimerGLFW.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPTimerGLFW.h"
#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif

namespace EmpanadaEngine
{
    
    // MARK: - Constructor
    
    EMPTimerGLFW::EMPTimerGLFW()
    {
        m_lastTime = 0.0f;
    }
    // MARK: - Public Methods
    
    void EMPTimerGLFW::SetMaxFps(unsigned int fps)
    {
        m_fps = fps;
    }
    void EMPTimerGLFW::CalculateTime()
    {
        m_deltaTime = glfwGetTime() - m_lastTime;
    }

    void EMPTimerGLFW::CalculateLastTime()
    {
        m_lastTime = glfwGetTime();
    }
}
