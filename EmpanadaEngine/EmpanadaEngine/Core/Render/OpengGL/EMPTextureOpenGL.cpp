//
//  EMPTextureOpenGL.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/29/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPTextureOpenGL.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../../Lib/Common/stb/stb_image.h"

namespace EmpanadaEngine
{
    EMPTextureOpenGL::EMPTextureOpenGL(const std::string& path)
    {
        unsigned char *imageBuffer = stbi_load(path.c_str(), &m_width, &m_height, nullptr, 4);
        if (!imageBuffer)
        {
            return;
        }
        glGenTextures(1, &m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageBuffer);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        stbi_image_free(imageBuffer);
    }

    EMPTextureOpenGL::EMPTextureOpenGL(unsigned int width, unsigned int rows, unsigned char*  buffer)
    {
        glGenTextures(1, &m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, rows, 0, GL_RED, GL_UNSIGNED_BYTE, buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    EMPTextureOpenGL::~EMPTextureOpenGL()
    {
        glDeleteTextures(1, &m_textureID);
    }
    
    uint32_t EMPTextureOpenGL::GetId() const
    {
        return m_textureID;
    }
    
    glm::vec2 EMPTextureOpenGL::GetSize() const
    {
        return glm::vec2(m_width, m_height);
    }

    void EMPTextureOpenGL::Bind() const
    {
        glActiveTexture(GL_TEXTURE + m_textureID );
        glBindTexture(GL_TEXTURE_2D, m_textureID);
    }
}
