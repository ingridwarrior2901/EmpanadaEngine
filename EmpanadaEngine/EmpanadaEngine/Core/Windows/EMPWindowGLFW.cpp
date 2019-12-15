//
//  EMPWindowGLW.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPWindowGLFW.h"
#include "../Events/EMPWindowEvent.h"
#include "../Events/EMPEventManager.h"

namespace EmpanadaEngine
{
    // MARK: - Constructor
    
    EMPWindowGLFW *instance = nullptr;

    EMPWindowGLFW::EMPWindowGLFW(const EMPWindowConfiguration& windowsInfo): m_windowsInfo(windowsInfo)
    {
        instance = this;
        Initialize();
    }

    EMPWindowGLFW::~EMPWindowGLFW()
    {
        Terminate();
    }
    
    // MARK: - Lifecycle

    bool EMPWindowGLFW::Initialize()
    {
        if (!glfwInit())
        {
            return false;
        }
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        
        m_window = glfwCreateWindow(m_windowsInfo.windowSize.x,
                                    m_windowsInfo.windowSize.y,
                                    m_windowsInfo.title.c_str(),
                                    nullptr,
                                    nullptr);
        
        glfwMakeContextCurrent(m_window);
        SetViewPort(glm::vec4(0, 0, m_windowsInfo.windowSize.x, m_windowsInfo.windowSize.y));
        
        glewExperimental = GL_TRUE;
        
        GLenum error = glewInit();
        if (error != GLEW_OK)
        {
            Close();
            Terminate();
            return false;
        }
        
        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_window, WindowSizeCallback);
        glfwSetWindowCloseCallback(m_window, WindowCloseCallback);
        
        return true;
    }

    void EMPWindowGLFW::StartFrame()
    {
        glClearColor(m_windowsInfo.backgroundColor.color.r,
                     m_windowsInfo.backgroundColor.color.g,
                     m_windowsInfo.backgroundColor.color.b,
                     m_windowsInfo.backgroundColor.color.a);
        
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void EMPWindowGLFW::EndFrame()
    {
        glfwPollEvents();
    }

    void EMPWindowGLFW::Terminate()
    {
        glfwTerminate();
    }

    void EMPWindowGLFW::Update()
    {
        if (!m_window) { return; }
        glfwSwapBuffers(m_window);
    }

    void EMPWindowGLFW::Close()
    {
        if (!m_window) { return; }
        glfwDestroyWindow(m_window);
    }

    // MARK: - Public Methods
    
    void EMPWindowGLFW::ResizeViewport(glm::vec2 windowSize)
    {
        m_windowsInfo.windowSize = windowSize;
        SetViewPort(glm::vec4(0, 0 , m_windowsInfo.windowSize.x, m_windowsInfo.windowSize.y));
    }

    void EMPWindowGLFW::SetBackgroundColor(glm::vec4 color)
    {
        m_windowsInfo.backgroundColor = {color};
    }

    void EMPWindowGLFW::SetViewPort(glm::vec4 viewPort)
    {
        m_viewPort = viewPort;
        glViewport(viewPort.x, viewPort.y, viewPort.z, viewPort.w);
        glScissor(viewPort.x, viewPort.y, viewPort.z, viewPort.w);
    }

    //MARK: - Callbacks Methods
    void EMPWindowGLFW::WindowSizeCallback(GLFWwindow *window, int width, int height)
    {
        if (instance)
        {
            glm::vec2 newWindowSize = glm::vec2(width, height);
            instance->ResizeViewport(newWindowSize);
            EMPWindowResizeEvent windowResizeEvent(newWindowSize);
            EMPEventManager::GetInstance().Notify(windowResizeEvent.GetEventType(), windowResizeEvent);
        }
    }

    void EMPWindowGLFW::WindowCloseCallback(GLFWwindow *window)
    {
        if (instance)
        {
            EMPWindowCloseEvent windowCloseEvent;
            EMPEventManager::GetInstance().Notify(windowCloseEvent.GetEventType(), windowCloseEvent);
        }
    }
}
