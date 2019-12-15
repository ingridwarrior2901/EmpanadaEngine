//
//  EMPBuffer2.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "IEMPBuffer.h"
#include "OpengGL/EMPBufferOpenGL.h"

namespace EmpanadaEngine
{
    EMPRef<IEMPBuffer> IEMPBuffer::Load(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs, API::EMPRenderType renderType)
    {
        switch (renderType)
        {
            case API::EMPRenderType::OpenGL:
                return IEMPBufferPTR(new EMPBufferOpenGL(vertexs, indexs));
            default:
                return nullptr;
                
        }
        return nullptr;
    }
}

