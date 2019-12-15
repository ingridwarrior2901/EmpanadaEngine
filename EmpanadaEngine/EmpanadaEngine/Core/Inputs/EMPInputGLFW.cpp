//
//  EMPInputGLFW.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPInputGLFW.h"
#include "../Events/EMPEventManager.h"
#include "../Events/EMPKeyEvent.h"
#include "../Events/EMPMouseEvent.h"

namespace EmpanadaEngine
{
    // MARK: - Constructor
    
    EMPInputGLFW::EMPInputGLFW(void* window): IEMPInput(window)
    {
        m_window = static_cast<GLFWwindow *>(window);
        if (m_window)
        {
            glfwSetKeyCallback(m_window, KeyCallback);
            glfwSetMouseButtonCallback(m_window, MouseButtonCallback);
            glfwSetCursorPosCallback(m_window, CursorPosCallback);
        }
    }

    // MARK: - Public Methods
    
    bool EMPInputGLFW::IsKeyPressed(unsigned int key)
    {
        if (!m_window) { return false; }
        
        auto keyPressed = glfwGetKey(m_window, key);
        return keyPressed == GLFW_PRESS;
    }

    bool EMPInputGLFW::IsKeyDown(unsigned int key)
    {
        if (!m_window) { return false; }
        
        auto keyPressed = glfwGetKey(m_window, key);
        return keyPressed == GLFW_REPEAT;
    }

    glm::vec2 EMPInputGLFW::GetMousePosition()
    {
        if (!m_window) { return glm::vec2(0.0f); }
        
        double positionX, positionY;
        glfwGetCursorPos(m_window, &positionX, &positionY);
        return glm::vec2(positionX, positionY);
    }

    //MARK: - Callbacks Methods
    
    void EMPInputGLFW::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        EMPEventType eventType = EMPEventType::EMPInputKeyPressed;
        
        switch (action)
        {
            case GLFW_PRESS:
            {
                eventType = EMPEventType::EMPInputKeyPressed;
                break;
            }
            case GLFW_RELEASE:
            {
                eventType = EMPEventType::EMPInputKeyReleased;
                break;
            }
            case GLFW_REPEAT:
            {
                eventType = EMPEventType::EMPInputKeyRepeat;
                break;
            }
        }
        
        EMPKeyEvent keyEvent(eventType, key);
        EMPEventManager::GetInstance().Notify(keyEvent.GetEventType(), keyEvent);
    }

    void EMPInputGLFW::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        EMPEventType eventType = action == GLFW_PRESS ? EMPEventType::EMPInputMouseButtonPressed :  EMPEventType::EMPInputMouseButtonReleased;
        EMPMousePressedEvent mouseEvent(eventType);
        EMPEventManager::GetInstance().Notify(mouseEvent.GetEventType(), mouseEvent);
    }

    void EMPInputGLFW::CursorPosCallback(GLFWwindow *window, double xPos, double yPos)
    {
        glm::vec2 cursorPosition = glm::vec2(xPos, yPos);
        EMPCursorChangeEvent cursorEvent(cursorPosition);
        EMPEventManager::GetInstance().Notify(cursorEvent.GetEventType(), cursorEvent);
    }
}
