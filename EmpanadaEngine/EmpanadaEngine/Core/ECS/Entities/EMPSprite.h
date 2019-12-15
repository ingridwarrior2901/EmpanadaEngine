//
//  EMPSprite.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPSprite_hpp
#define EMPSprite_hpp

#include "EMPModel.h"
#include "../Components/EMPAnimationComponent.h"
#include "../Components/EMPCollisionComponent.h"

namespace EmpanadaEngine
{
    class EMPSprite: public EMPModel
    {
    public:
        //------------------------------------------------------------/
        EMPSprite(std::string name, IEMPShaderPTR defaultShader, const std::string& path, glm::vec2 position, glm::vec2 size);
        virtual ~EMPSprite() {}
        //------------------------------------------------------------/
        virtual void Update(float deltaTime);
        virtual void Draw();
       //------------------------------------------------------------/
        void AddAnimation(const std::string name, int horizontalFrames, int verticalFrames, int fps = 8, IEMPTexturePTR texture = nullptr);
        
        EMPAnimationComponentPTR GetAnimationComponent() const { return m_animationComponent; }
    private:
        //------------------------------------------------------------/
        std::vector<EMPVertex> SetupVertices(float u0, float v0, float u1, float v1);
        void SetupMesh(std::vector<EMPVertex> vertices);
        //------------------------------------------------------------/
        IEMPShaderPTR m_defaultShader;
        EMPMeshPTR m_defaultMesh;
        IEMPTexturePTR m_texture;
        EMPMaterialPTR m_defaultMaterial;
        EMPAnimationComponentPTR m_animationComponent;
        EMPCollisionComponentPTR m_collisionComponent;
        //------------------------------------------------------------/
        glm::vec2 m_position;
        glm::vec2 m_size;
        //------------------------------------------------------------/
        std::vector<GLuint> m_indexs;
    };

    using EMPSpritePTR = std::shared_ptr<EMPSprite>;
}


#endif /* EMPSprite_hpp */
