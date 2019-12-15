//
//  IEMPScene.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/1/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "IEMPScene.h"
#include "../EmpanadaEngine.h"
#include "../ECS/Components/EMPCollisionComponent.h"
#include "../Utils/EMPCollision.h"
#include <algorithm>

namespace EmpanadaEngine
{
    namespace IEMPSceneConstants
    {
        const std::string textVertexFile = "Resources/shader.vert";
        const std::string textFragmentFile = "Resources/shader.frag";
    }

    IEMPScene::IEMPScene(const std::string& name) : m_sceneName(name)
    {
        m_mainCamera = NewRef<EMPCamara>();
        m_mainCamera->GetTransformComponent()->SetPosition(glm::vec3(0.0f, 0.0f, 0.1f));
        m_defaultShader = IEMPShader::Load(IEMPSceneConstants::textVertexFile, IEMPSceneConstants::textFragmentFile);
    }

    void IEMPScene::DrawEntities()
    {
        m_mainCamera->Draw();
        for (IEMPEntityPTR entity: m_entityList)
        {
            entity->Draw();
        }
    }

    void IEMPScene::Update(float deltaTime)
    {
        m_mainCamera->Update(deltaTime);
        for (IEMPEntityPTR entity: m_entityList)
        {
            entity->Update(deltaTime);
        }
    }

    void IEMPScene::AddEntity(const IEMPEntityPTR& entity)
    {
        m_entityList.push_back(entity);
    }

    void IEMPScene::RemoveEntity(const IEMPEntityPTR& entity)
    {
        std::vector<IEMPEntityPTR>::iterator entityInterator = std::find(m_entityList.begin(),
                                                                         m_entityList.end(),
                                                                         entity);
        
        if (entityInterator != m_entityList.end())
        {
            m_entityList.erase(entityInterator);
        }
    }

    void IEMPScene::CheckCollision()
    {
        if (!m_enableCollision) { return; }
        
        for (unsigned int i = 0; i < m_entityList.size(); i++)
        {
            for (unsigned j = i + 1; j < m_entityList.size(); j++)
            {
                IEMPEntityPTR entityObject = m_entityList[i];
                IEMPEntityPTR entity = m_entityList[j];
                
                if (entityObject != entity && entity->GetComponent<EMPCollisionComponent>() && entityObject->GetComponent<EMPCollisionComponent>())
                {
                    EMPTransformComponentPTR entityTransform = entity->GetComponent<EMPTransformComponent>();
                    EMPCollisionComponentPTR entityCollision = entity->GetComponent<EMPCollisionComponent>();
                    
                    EMPTransformComponentPTR entityObjectTransform = entityObject->GetComponent<EMPTransformComponent>();
                    EMPCollisionComponentPTR entityObjectCollision = entityObject->GetComponent<EMPCollisionComponent>();
                    
                    bool hasCollision = EMPCollision::isOverlappingRect({entityTransform->GetPosition(), entityCollision->GetSize()},
                                                                        {entityObjectTransform->GetPosition(), entityObjectCollision->GetSize()});
                    if (hasCollision)
                    {
                        Collide(entity, entityObject);
                    }
                }
            }
        }
    }
}
