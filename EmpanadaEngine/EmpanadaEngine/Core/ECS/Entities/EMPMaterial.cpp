//
//  EMPMaterial.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/30/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPMaterial.h"
#include "../../Scenes/EMPSceneManager.h"

namespace EmpanadaEngine
{
    EMPMaterial::EMPMaterial(const IEMPShaderPTR& shader, const IEMPTexturePTR& texture)
    {
        m_shader = shader;
        m_texture = texture;
        enableTexture = m_texture != nullptr;
    }

    const IEMPShaderPTR& EMPMaterial::GetShader() const
    {
        return m_shader;
    }

    void EMPMaterial::SetShader(const IEMPShaderPTR& shader)
    {
        m_shader = shader;
    }

    const IEMPTexturePTR& EMPMaterial::GetTexture() const
    {
        return m_texture;
    }

    void EMPMaterial::SetTexture(const IEMPTexturePTR& texture)
    {
        m_texture = texture;
        enableTexture = m_texture != nullptr;
    }

    void EMPMaterial::Draw(glm::mat4 modelMatrix)
    {
        m_shader->UseShader();
        
        m_shader->SetMatrix("model", modelMatrix);
        
        if (EMPSceneManager::GetInstance().GetCurrentScene() != nullptr)
        {
            auto camera = EMPSceneManager::GetInstance().GetCurrentScene()->GetMainCamera();
            m_shader->SetMatrix("projection", camera->GetProjection() * camera->GetViewMatrix());
        }
        
        m_shader->SetInt("enableTexture", enableTexture ? 1 : 0);
        
        if (enableTexture)
        {
            m_shader->SetInt("Texture", 0);
            m_texture->Bind();
        }
    }

}
