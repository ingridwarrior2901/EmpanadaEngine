//
//  IEMPShader.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "IEMPShader.h"
#include "EMPShaderOpenGL.h"

namespace EmpanadaEngine
{
    EMPRef<IEMPShader> IEMPShader::Load(const std::string& vertexFilename, const std::string& fragmentFilename, API::EMPRenderType renderType)
    {
        switch (renderType)
        {
            case API::EMPRenderType::OpenGL:
                return IEMPShaderPTR(new EMPShaderOpenGL(vertexFilename, fragmentFilename));;
            default:
                return nullptr;
                
        }
        return nullptr;
    }
}

