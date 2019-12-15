//
//  EMPTexture.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/29/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "IEMPTexture.h"
#include "OpengGL/EMPTextureOpenGL.h"

namespace EmpanadaEngine
{
    EMPRef<IEMPTexture> IEMPTexture::Load(const std::string& path, API::EMPRenderType renderType)
    {
        switch (renderType)
        {
            case API::EMPRenderType::OpenGL:
                return IEMPTexturePTR(new EMPTextureOpenGL(path));;
            default:
                return nullptr;
                
        }
        return nullptr;
    }

    EMPRef<IEMPTexture> IEMPTexture::Load(unsigned int width, unsigned int rows, unsigned char* buffer, API::EMPRenderType renderType)
    {
        switch (renderType)
        {
            case API::EMPRenderType::OpenGL:
                return IEMPTexturePTR(new EMPTextureOpenGL(width, rows, buffer));;
            default:
                return nullptr;
                
        }
        return nullptr;
    }
}
