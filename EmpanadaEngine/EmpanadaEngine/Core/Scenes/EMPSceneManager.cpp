//
//  EMPSceneManager.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/26/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPSceneManager.h"

namespace EmpanadaEngine
{
    // MARK: - Constructor
    
    EMPSceneManager::EMPSceneManager()
    {
        m_sceneIterator = m_scenes.begin();
    }
    
    EMPSceneManager::~EMPSceneManager()
    {
        m_scenes.clear();   
    }
    
    // MARK: - Public Methods
    
    void EMPSceneManager::PushScene(EMPScenePTR scene)
    {
        SetCurrentScene(scene);
        m_sceneIterator = m_scenes.emplace(m_sceneIterator, scene);
        scene->Attach();
    }
    
    void EMPSceneManager::PopScene(EMPScenePTR scene)
    {
        auto it = std::find(m_scenes.begin(), m_scenes.end(), scene);
        if (it != m_scenes.end())
        {
            (*it)->Destroy();
            m_scenes.erase(it);
            m_sceneIterator--;
        }
    }
    
    void EMPSceneManager::SetCurrentScene(EMPScenePTR scene)
    {
        m_currentScene = scene;
    }
    
    void EMPSceneManager::Start()
    {
        for (EMPScenePTR scene : m_scenes)
        {
            scene->Start();
        }
    }

    void EMPSceneManager::DrawEntities()
    {
        for (EMPScenePTR scene : m_scenes)
        {
            scene->DrawEntities();
        }
    }

    void EMPSceneManager::CheckCollision()
    {
        for (EMPScenePTR scene : m_scenes)
        {
            scene->CheckCollision();
        }
    }
    
    void EMPSceneManager::Update(float deltaTime)
    {
        for (EMPScenePTR scene : m_scenes)
        {
            scene->Update(deltaTime);
        }
    }
}
