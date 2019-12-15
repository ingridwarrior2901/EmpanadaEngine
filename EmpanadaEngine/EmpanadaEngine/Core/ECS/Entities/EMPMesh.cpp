//
//  EMPMesh.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/1/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPMesh.h"
#include "../../EmpanadaEngine.h"

namespace EmpanadaEngine
{
    EMPMesh::EMPMesh()
    {
        
    }

    EMPMesh::~EMPMesh()
    {}
    
    void EMPMesh::Add(const IEMPBufferPTR& buffer, const EMPMaterialPTR& material)
    {
        m_bufferContainerMap.push_back({buffer, material});
    }
    
    size_t EMPMesh::GetNumBuffers() const
    {
        return m_bufferContainerMap.size();
    }
    
    IEMPBufferPTR EMPMesh::GetBuffer(size_t index) const
    {
        if (m_bufferContainerMap.size() > 0)
        {
            return m_bufferContainerMap.at(index).buffer;;
        }
        return nullptr;
    }
    
    EMPMaterialPTR EMPMesh::GetMaterial(size_t index) const
    {
        if (m_bufferContainerMap.size() > 0)
        {
            return m_bufferContainerMap.at(index).material;
        }
        return nullptr;
    }
    
    void EMPMesh::Draw(glm::mat4 modelMatrix)
    {
        for (EMPBufferContainer container : m_bufferContainerMap)
        {
            IEMPShaderPTR shader = container.material->GetShader();
            EMPMaterialPTR material = container.material;

            material->Draw(modelMatrix);

            container.buffer->Bind();
            shader->SetupAttributes();
            container.buffer->Draw();
            container.buffer->UnBind();
        }
    }
}
