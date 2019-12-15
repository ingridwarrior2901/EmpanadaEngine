//
//  EMPSceneManager.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/26/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPSceneManager_hpp
#define EMPSceneManager_hpp

#include "IEMPScene.h"
#include "../Game/EMPSinglenton.h"
#include <iostream>
#include <vector>

namespace EmpanadaEngine
{
    class EMPSceneManager: public EMPSinglenton<EMPSceneManager>
    {
     public:
        //------------------------------------------------------------/
        EMPSceneManager();
        ~EMPSceneManager();
        //------------------------------------------------------------/
        void PushScene(EMPScenePTR scene);
        void SetCurrentScene(EMPScenePTR scene);
        void PopScene(EMPScenePTR scene);
        void Update(float deltaTime);
        void Start();
        void DrawEntities();
        void CheckCollision();
        //------------------------------------------------------------/
        std::vector<EMPScenePTR>::iterator Begin() { return m_scenes.begin(); }
        std::vector<EMPScenePTR>::iterator End() { return m_scenes.end(); }
        //------------------------------------------------------------/
        EMPScenePTR GetCurrentScene() const { return m_currentScene; }
       private:
           std::vector<EMPScenePTR> m_scenes;
           std::vector<EMPScenePTR>::iterator m_sceneIterator;
           EMPScenePTR m_currentScene;
    };
}

#endif /* EMPSceneManager_hpp */
