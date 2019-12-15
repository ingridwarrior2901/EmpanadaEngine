//
//  IEMPScene.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/26/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef IEMPScene_h
#define IEMPScene_h

#include "../ECS/Entities/EMPCamara.h"
#include "../Shaders/IEMPShader.h"
#include <iostream>
#include <string>
#include <vector>

namespace EmpanadaEngine
{
    class IEMPScene
    {
    public:
        //------------------------------------------------------------/
        IEMPScene(const std::string& name);
        virtual ~IEMPScene() {}
        //------------------------------------------------------------/
        virtual void Attach() {}
        virtual void Update(float deltaTime);
        virtual void Start() {}
        virtual void Destroy() {}
        virtual void Collide(IEMPEntityPTR firstEntityObject, IEMPEntityPTR secondEntityObject) {}
        //------------------------------------------------------------/
        virtual std::string GetSceneName() { return m_sceneName; }
        //------------------------------------------------------------/
        void DrawEntities();
        void AddEntity(const IEMPEntityPTR& entity);
        void RemoveEntity(const IEMPEntityPTR& entity);
        void CheckCollision();
        
        EMPCamaraPTR GetMainCamera() const { return m_mainCamera; }
        IEMPShaderPTR GetDefaultShader() const { return m_defaultShader; }
    protected:
        
        bool m_enableCollision;
    
    private:
        std::string m_sceneName;
        std::vector<IEMPEntityPTR> m_entityList;
        EMPCamaraPTR m_mainCamera;
        IEMPShaderPTR m_defaultShader;
    };

    using EMPScenePTR = std::shared_ptr<IEMPScene>;
}

#endif /* IEMPScene_h */
