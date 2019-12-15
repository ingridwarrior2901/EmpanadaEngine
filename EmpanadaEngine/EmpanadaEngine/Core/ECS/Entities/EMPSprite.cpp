//
//  EMPSprite.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPSprite.h"
#include "../../Game/EMPGameApp.h"
#include "../../Windows/IEMPWindow.h"

namespace EmpanadaEngine
{
    EMPSprite::EMPSprite(std::string name, IEMPShaderPTR defaultShader, const std::string& path, glm::vec2 position, glm::vec2 size)
    {
        m_animationComponent = std::make_shared<EMPAnimationComponent>(this);
        m_collisionComponent = std::make_shared<EMPCollisionComponent>(this);
        
        AddComponent(m_animationComponent);
        AddComponent(m_collisionComponent);
        
        GetTransformComponent()->SetPosition(glm::vec3(position.x, position.y, 0.0f));

        m_texture = IEMPTexture::Load(path);
        m_defaultShader = defaultShader;
        m_indexs = { 0, 1, 2, 3, 4, 5 };
        
        m_position = position;
        SetName(name);
        
        m_collisionComponent->SetSize(size);
        GetTransformComponent()->SetSize(size);
        m_size = size;
        
        SetupMesh(SetupVertices(0.0f, 0.0f, 1.0f, 1.0f));
    }

    void EMPSprite::AddAnimation(const std::string name, int horizontalFrames, int verticalFrames, int fps, IEMPTexturePTR texture)
    {
        int totalMaxFrames = horizontalFrames * verticalFrames;
        std::vector<std::vector<EMPVertex>> uvAnimationVertex;
        
        for (int i = 0; i < totalMaxFrames; i ++)
        {
            float horizontalPosition = (float) i / horizontalFrames;
            float u0 = horizontalPosition;
            float u1 = u0 + (1.0f / horizontalFrames);
            
            uvAnimationVertex.push_back(SetupVertices(u0, 0.0f, u1, 1.0f));
        }
        
        m_animationComponent->AddAnimation(texture ? texture : m_texture,
                                           name,
                                           horizontalFrames,
                                           verticalFrames,
                                           fps,
                                           uvAnimationVertex);
    }

    void EMPSprite::Update(float deltaTime)
    {
        EMPModel::Update(deltaTime);
    }
    
    void EMPSprite::Draw()
    {
        if (m_animationComponent->AnimationSize() > 0)
        {
            m_defaultMaterial->SetTexture(m_animationComponent->GetCurrentTextureAnimation());
            m_defaultMesh->GetBuffer(0)->SetVertexAndIndex(m_animationComponent->GetCurrentUVVertexAnimation(), m_indexs);
        }
        EMPModel::Draw();
    }

    std::vector<EMPVertex> EMPSprite::SetupVertices(float u0, float v0, float u1, float v1)
    {
        std::vector<EMPVertex> vertices;
        //First Triangle
        vertices.push_back({
            glm::vec3(m_position.x + m_size.x, m_position.y + m_size.y, 0.0f), //position
            glm::vec3(1.0f),//color
            glm::vec2(u1, v1)}); //uv
        vertices.push_back({
            glm::vec3(m_position.x, m_position.y + m_size.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u0, v1)});
        vertices.push_back({
            glm::vec3(m_position.x, m_position.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u0, v0)});
        
        //Second Triangle
        vertices.push_back({
            glm::vec3(m_position.x, m_position.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u0, v0)});
        vertices.push_back({
            glm::vec3(m_position.x + m_size.x, m_position.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u1, v0)});
        vertices.push_back({
            glm::vec3(m_position.x + m_size.x, m_position.y + m_size.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u1, v1)});
        return vertices;
    }

    void EMPSprite::SetupMesh(std::vector<EMPVertex> vertices)
    {
        IEMPBufferPTR defaultBuffer = EmpanadaEngine::IEMPBuffer::Load(vertices, m_indexs);
        m_defaultMesh = NewRef<EMPMesh>();
        m_defaultMaterial = NewRef<EMPMaterial>(m_defaultShader, m_texture);
        
        m_defaultMesh->Add(defaultBuffer, m_defaultMaterial);
        SetMesh(m_defaultMesh);
    }
}
