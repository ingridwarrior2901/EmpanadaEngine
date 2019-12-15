//
//  EMPCollisionComponent.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/10/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPCollisionComponent.h"
#include "EMPTransformComponent.h"

namespace EmpanadaEngine
{
    EMPCollisionComponent::EMPCollisionComponent(IEMPEntity *owner, glm::vec2 size): IEMPComponent(owner)
    {
        if (size.x == 0.0f && size.y == 0.0f)
        {
            if (EMPTransformComponentPTR transformComponent = owner->GetComponent<EMPTransformComponent>())
            {
                m_size = transformComponent->GetSize();
            }
        }
    }

    void EMPCollisionComponent::SetSize(const glm::vec2& size)
    {
        m_size = size;
    }
}
