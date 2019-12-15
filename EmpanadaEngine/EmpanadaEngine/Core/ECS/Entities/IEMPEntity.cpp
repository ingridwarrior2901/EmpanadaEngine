//
//  EMPEntity.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/30/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "IEMPEntity.h"

namespace EmpanadaEngine
{    
    void IEMPEntity::SetName(std::string name)
    {
        m_name = name;
    }

    void IEMPEntity::AddComponent(IEMPComponentPTR component)
    {
        m_components.insert(component);
    }

    void IEMPEntity::RemoveComponent(IEMPComponentPTR component)
    {
        m_components.erase(component);
    }

    void IEMPEntity::Update(float deltaTime)
    {
        for (IEMPComponentPTR component : m_components)
        {
            component->Update(deltaTime);
        }
    }
}
