//
//  EMPWindowGLW.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPWindowGLW_hpp
#define EMPWindowGLW_hpp

#include "IEMPWindow.h"
#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif

namespace EmpanadaEngine
{
    class EMPWindowGLFW: public IEMPWindow
    {
    public:
        //------------------------------------------------------------/
        EMPWindowGLFW(const EMPWindowConfiguration& windowsInfo);
        virtual ~EMPWindowGLFW();
        //------------------------------------------------------------/
        bool Initialize() override;
        void Terminate() override;
        void StartFrame() override;
        void EndFrame() override;
        void Update() override;
        void Close() override;
        void ResizeViewport(glm::vec2 windowSize) override;
        void SetBackgroundColor(glm::vec4 color) override;
        void SetViewPort(glm::vec4 viewPort) override;
        //------------------------------------------------------------/
        inline glm::vec2 GetWindowSize() const override { return m_windowsInfo.windowSize; }
        inline glm::vec4 GetViewPort() const override { return m_viewPort; }
        void* GetWindow() const override { return m_window; }
        //------------------------------------------------------------/
        static void WindowSizeCallback(GLFWwindow* window, int width, int height);
        static void WindowCloseCallback(GLFWwindow* window);
        
    private:
        GLFWwindow *m_window;
        EMPWindowConfiguration m_windowsInfo;
        glm::vec4 m_viewPort;
    };
}

#endif /* EMPWindowGLW_hpp */
