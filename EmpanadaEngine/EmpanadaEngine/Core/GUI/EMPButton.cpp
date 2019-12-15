//
//  EMPButton.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/12/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPButton.h"
#include "../Events/EMPEventManager.h"
#include "../Events/EMPMouseEvent.h"

namespace EmpanadaEngine
{
    // MARK: - Constructor
    EMPButton::EMPButton(IEMPShaderPTR defaultShader, std::string buttonImage, glm::vec2 position, glm::vec2 size, const ButtonCallback& callback): m_defaultShader(defaultShader), m_position(position), m_size(size), m_callback(callback)
    {
        m_buttonTexture = IEMPTexture::Load(buttonImage);
        std::vector<GLuint> indexs = { 0, 1, 2, 3, 4, 5 };
        SetMesh(CreateMaterial(GenerateVertices(position, size, 0.0f, 0.0f, 1.0f, 1.0f), indexs, defaultShader, m_buttonTexture));
        
        EMPEventManager::GetInstance().Register(EMPEventType::EMPInputMouseButtonPressed, this);
        EMPEventManager::GetInstance().Register(EMPEventType::EMPInputMouseCursorChange, this);
    }

    EMPButton::~EMPButton()
    {
        EMPEventManager::GetInstance().UnRegister(EMPEventType::EMPInputMouseButtonPressed, this);
        EMPEventManager::GetInstance().UnRegister(EMPEventType::EMPInputMouseCursorChange, this);
    }

    // MARK: - Public Methods
    void EMPButton::Draw()
    {
        
        EMPModel::Draw();
    }

    void EMPButton::Update(float deltaTime)
    {
        EMPModel::Update(deltaTime);
    }

    void EMPButton::OnMousePressed(EMPEvent &event)
    {
        float height = m_size.y <= 50.0f ? m_size.y * 2.0f : m_size.y;
        if (event.GetEventType() == EMPEventType::EMPInputMouseButtonPressed &&
            m_cursorPosition.x >= m_position.x &&
            m_position.x + m_size.x >= m_cursorPosition.x &&
            m_cursorPosition.y >= abs(m_position.y - height) &&
            m_position.y >= m_cursorPosition.y &&
            m_callback != nullptr)
        {
            m_callback();
        }
    }

    void EMPButton::OnCursorChanged(EMPEvent &event)
    {
        if (event.GetEventType() == EmpanadaEngine::EMPEventType::EMPInputMouseCursorChange)
        {
            EMPCursorChangeEvent cursorPos = dynamic_cast<EMPCursorChangeEvent&>(event);
            m_cursorPosition = glm::vec3(cursorPos.GetCursorPosition().x,
                                         cursorPos.GetCursorPosition().y,
                                         0);
        }
    }
}
