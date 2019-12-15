//
//  EMPModel.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/30/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPModel.h"
#include "../../../Lib/Common/glm/glm/gtc/matrix_transform.hpp"
#include "../../../Lib/Common/glm/glm/gtc/type_ptr.hpp"

namespace EmpanadaEngine
{
    EMPModel::EMPModel(const EMPMeshPTR& mesh) : m_mesh(mesh)
    {
        m_model = glm::mat4(1.0f);
        m_angle = 0.0f;
    }

    EMPModel::EMPModel()
    {
        m_model = glm::mat4(1.0f);
        m_angle = 0.0f;
    }

    void EMPModel::SetAngle(float angle)
    {
        m_angle = angle;
    }

    void EMPModel::Draw()
    {
        EMPGameObject::Draw();
        glm::mat4 model = m_model;
        model = glm::translate(model, GetPosition());
        model = glm::scale(model, GetScale());
        model = glm::rotate(model, glm::radians(m_angle), GetRotation());
        if (m_mesh)
        {
            m_mesh->Draw(model);
        }
    }

    void EMPModel::Update(float deltaTime)
    {
        EMPGameObject::Update(deltaTime);
    }

    void EMPModel::SetMesh(const EMPMeshPTR &mesh)
    {
        m_mesh = mesh;
    }

    EMPRef<EMPModel> EMPModel::Load(EMPDrawMode drawMode, IEMPShaderPTR defaultShader, glm::vec3 color)
    {
        return DrawModel(drawMode, defaultShader, color);
    }

    EMPRef<EMPModel> EMPModel::Load(EMPDrawMode drawMode, IEMPShaderPTR defaultShader, IEMPTexturePTR texture)
    {
        return DrawModel(drawMode, defaultShader, glm::vec3(0.0), texture);
    }

    EMPRef<EMPModel> EMPModel::DrawModel(EMPDrawMode drawMode, IEMPShaderPTR defaultShader, glm::vec3 color, IEMPTexturePTR texture)
    {
        switch (drawMode)
        {
            case TRIANGLE:
                return DrawTriangle(defaultShader, color, texture);
            case RECTANGLE:
                return DrawRectangle(defaultShader, color, texture);
        }
    }

    EMPRef<EMPModel> EMPModel::DrawTriangle(IEMPShaderPTR defaultShader, glm::vec3 color, IEMPTexturePTR texture)
    {
        std::vector<EMPVertex> vertexs;
        std::vector<GLuint> indexs = { 0, 1, 2 };
        
        vertexs.push_back({glm::vec3(-1.0f, -1.0f, 0.0f), color, glm::vec2(0.0f)});
        vertexs.push_back({glm::vec3(1.0f, -1.0f, 0.0f), color, glm::vec2(1.0f, 0.0f)});
        vertexs.push_back({glm::vec3(0.0f,  1.0f, 0.0f), color, glm::vec2(0.5f, 1.0f)});

        return NewRef<EMPModel>(CreateMaterial(vertexs, indexs, defaultShader, texture));
    }

    EMPRef<EMPModel> EMPModel::DrawRectangle(IEMPShaderPTR defaultShader, glm::vec3 color, IEMPTexturePTR texture)
    {
        std::vector<EMPVertex> vertexs;
        std::vector<GLuint> indexs = { 0, 1, 3, 1, 2, 3 };
        
        vertexs.push_back({glm::vec3(0.5f, 0.5f, 0.0f), color, glm::vec2(1.0f, 1.0f)});
        vertexs.push_back({glm::vec3(0.5f, -0.5f, 0.0f), color, glm::vec2(1.0f, 0.0f)});
        vertexs.push_back({glm::vec3(-0.5f, -0.5f, 0.0f), color, glm::vec2(0.0f, 0.0f)});
        vertexs.push_back({glm::vec3(-0.5f, 0.5f, 0.0f), color, glm::vec2(0.0f, 1.0f)});

        return NewRef<EMPModel>(CreateMaterial(vertexs, indexs, defaultShader, texture));
    }

    EMPMeshPTR EMPModel::CreateMaterial(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs, IEMPShaderPTR defaultShader, IEMPTexturePTR texture)
    {
        IEMPBufferPTR defaultBuffer = EmpanadaEngine::IEMPBuffer::Load(vertexs, indexs);
        EMPMeshPTR defaultMesh = NewRef<EMPMesh>();
        
        EMPMaterialPTR defaultMaterial = NewRef<EMPMaterial>(defaultShader, texture);
        defaultMesh->Add(defaultBuffer, defaultMaterial);
        
        return defaultMesh;
    }
    std::vector<EMPVertex> EMPModel::GenerateVertices(glm::vec2 position, glm::vec2 size, float u0, float v0, float u1, float v1)
    {
        std::vector<EMPVertex> vertices;
        //First Triangle
        vertices.push_back({
            glm::vec3(position.x + size.x, position.y + size.y, 0.0f), //position
            glm::vec3(1.0f),//color
            glm::vec2(u1, v1)}); //uv
        vertices.push_back({
            glm::vec3(position.x, position.y + size.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u0, v1)});
        vertices.push_back({
            glm::vec3(position.x, position.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u0, v0)});
        
        //Second Triangle
        vertices.push_back({
            glm::vec3(position.x, position.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u0, v0)});
        vertices.push_back({
            glm::vec3(position.x + size.x, position.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u1, v0)});
        vertices.push_back({
            glm::vec3(position.x + size.x, position.y + size.y, 0.0f),
            glm::vec3(1.0f),
            glm::vec2(u1, v1)});
        return vertices;
    }
}

