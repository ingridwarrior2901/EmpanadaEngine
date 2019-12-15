//
//  EMPTextureOpenGL.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/29/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPTextureOpenGL_hpp
#define EMPTextureOpenGL_hpp

#include "../IEMPTexture.h"
#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif

namespace EmpanadaEngine
{
    class EMPTextureOpenGL: public IEMPTexture
    {
    public:
        EMPTextureOpenGL(const std::string& path);
        EMPTextureOpenGL(unsigned int width, unsigned int rows, unsigned char*  buffer);
        ~EMPTextureOpenGL();
        //------------------------------------------------------------/
        virtual uint32_t GetId() const;
        virtual glm::vec2 GetSize() const;
        //------------------------------------------------------------/
        virtual void Bind() const;
    private:
         GLuint m_textureID;
    };
}

#endif /* EMPTextureOpenGL_hpp */
