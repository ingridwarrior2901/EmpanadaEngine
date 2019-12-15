//
//  EMPGameObject.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPGameObject.h"

namespace EmpanadaEngine
{
    EMPGameObject::EMPGameObject()
    {
        m_transformComponent = std::make_shared<EMPTransformComponent>(this);
        AddComponent(m_transformComponent);
    }

    void EMPGameObject::Update(float deltaTime)
    {
        IEMPEntity::Update(deltaTime); 
    }
}
