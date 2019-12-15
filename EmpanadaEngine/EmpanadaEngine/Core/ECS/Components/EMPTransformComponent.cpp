//
//  EMPTransformComponent.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPTransformComponent.h"
#include "../Entities/IEMPEntity.h"
#include "../../../Lib/Common/glm/glm/gtc/matrix_transform.hpp"
#include "../../../Lib/Common/glm/glm/gtc/type_ptr.hpp"

namespace EmpanadaEngine
{
    EMPTransformComponent::EMPTransformComponent(IEMPEntity *owner): m_position(glm::vec3(0.0f, 0.0f, 0.0f)), m_rotation(glm::vec3(0.0f, 1.0f, 0.0f)), m_scale(glm::vec3(1.0f, 1.0f, 0.0f)), m_size(1.0f), IEMPComponent(owner)
    {
        
    }

    const glm::vec3& EMPTransformComponent::GetPosition() const
    {
        return m_position;
    }

    void EMPTransformComponent::SetPosition(const glm::vec3& position)
    {
        m_position = position;
    }

    const glm::vec3& EMPTransformComponent::GetRotation() const
    {
        return m_rotation;
    }

    const void EMPTransformComponent::SetRotation(const glm::vec3& rotation)
    {
        m_rotation = rotation;
    }

    const glm::quat& EMPTransformComponent::GetRotationQuat() const
    {
        return glm::quat(m_rotation);
    }

    const void EMPTransformComponent::SetRotation(const glm::quat& quat)
    {
        m_rotation = glm::eulerAngles(quat);
    }

    const glm::vec3& EMPTransformComponent::GetScale() const
    {
        return m_scale;
    }

    void EMPTransformComponent::SetScale(const glm::vec3& scale)
    {
        m_scale = scale;
    }

    void EMPTransformComponent::SetSize(const glm::vec2& size)
    {
        m_size = size;
    }
    
    glm::vec2 EMPTransformComponent::GetSize() const
    {
        return m_size;
    }

    void EMPTransformComponent::Update(float deltaTime)
    {
        
    }
}
