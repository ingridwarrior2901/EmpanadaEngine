//
//  EMPInputGLFW.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPInputGLFW_hpp
#define EMPInputGLFW_hpp

#include "IEMPInput.h"

#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif

namespace EmpanadaEngine
{
    class EMPInputGLFW: public IEMPInput
    {
    public:
        //------------------------------------------------------------/
        EMPInputGLFW(void* m_window);
        //------------------------------------------------------------/
        bool IsKeyPressed(unsigned int key) override;
        bool IsKeyDown(unsigned int key) override;
        glm::vec2 GetMousePosition() override;
        //------------------------------------------------------------/
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void CursorPosCallback(GLFWwindow* window, double xPos, double yPos);
    private:
        GLFWwindow *m_window;
    };
}

#endif /* EMPInputGLFW_hpp */
