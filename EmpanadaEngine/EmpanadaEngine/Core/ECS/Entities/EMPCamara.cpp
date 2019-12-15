//
//  EMPCamara.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/1/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPCamara.h"
#include "../../../Lib/Common/glm/glm/gtc/matrix_transform.hpp"
#include "../../../Lib/Common/glm/glm/gtc/type_ptr.hpp"
#include "../../Game/EMPGameApp.h"
#include "../../Windows/IEMPWindow.h"

namespace EmpanadaEngine
{
    // MARK: - Constants
    namespace EMPCamaraConstants
    {
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
        float projectionSize = 90.0f;
        float near = 0.1f;
        float far = 100.0f;
    }

    EMPCamara::EMPCamara()
    {
        auto &application = EMPGameApp::GetInstance();
        if (application.GetWindowManager())
        {
            glm::vec2 windowSize = application.GetWindowManager()->GetWindowInterface()->GetWindowSize();
            glm::vec4 windowColor = application.GetWindowManager()->GetWindowInfo().backgroundColor.color;
            m_viewPort = glm::vec4(0, 0, windowSize.x, windowSize.y);
            m_clearColor = windowColor;
        }
    }

    void EMPCamara::SetViewport(const glm::vec4& viewport)
    {
        m_viewPort = viewport;
    }

    void EMPCamara::SetClearColor(const glm::vec4& color)
    {
        m_clearColor = color;
    }

    glm::mat4 EMPCamara::GetViewMatrix() const
    {
        glm::vec3 position = GetTransformComponent()->GetPosition();
        return glm::lookAt(position, position + EMPCamaraConstants::front, EMPCamaraConstants::up);
    }

    glm::mat4 EMPCamara::GetProjection() const
    {
        glm::mat4 projection;
        auto &application = EMPGameApp::GetInstance();
        if (application.GetWindowManager())
        {
            glm::vec4 viewPort = application.GetWindowManager()->GetWindowInterface()->GetViewPort();
            projection = glm::ortho(viewPort.x, viewPort.z, viewPort.w, 0.0f, 0.0f, 1000.0f);
        }
        
        return projection;
    }

    void EMPCamara::Draw()
    {
        auto &application = EMPGameApp::GetInstance();
        if (application.GetWindowManager())
        {
            application.GetWindowManager()->GetWindowInterface()->SetViewPort(m_viewPort);
            application.GetWindowManager()->GetWindowInterface()->SetBackgroundColor(m_clearColor);
        }
        
        EMPModel::Draw();
    }

    void EMPCamara::Update(float deltaTime)
    {
        EMPModel::Update(deltaTime);
    }
}
