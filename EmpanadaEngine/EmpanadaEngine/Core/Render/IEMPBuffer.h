//
//  IEMPBuffer.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef IEMPBuffer_h
#define IEMPBuffer_h

#include "../Shaders/IEMPShader.h"
#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif
#include <vector>

namespace EmpanadaEngine
{
    class IEMPBuffer
    {
    public:
        virtual ~IEMPBuffer() {}
        //------------------------------------------------------------/
        virtual void Bind() = 0;
        virtual void UnBind() = 0;
        virtual void Clear() = 0;
        virtual void Draw() const = 0;
        virtual void SetVertexAndIndex(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs) = 0;
        virtual void SetVertex(std::vector<EMPVertex> vertexArray) = 0;
        //------------------------------------------------------------/
        static EMPRef<IEMPBuffer> Load(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs, API::EMPRenderType renderType = API::EMPRenderType::OpenGL);
    };

    using IEMPBufferPTR = std::shared_ptr<IEMPBuffer>;
}

#endif /* IEMPBuffer_h */
