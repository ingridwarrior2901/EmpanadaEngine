//
//  EMPBufferOpenGL.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPBufferOpenGL_hpp
#define EMPBufferOpenGL_hpp

#include "../IEMPBuffer.h"

namespace EmpanadaEngine
{
    class EMPBufferOpenGL: public IEMPBuffer
    {
    public:
        //------------------------------------------------------------/
        EMPBufferOpenGL(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs);
        ~EMPBufferOpenGL();
        //------------------------------------------------------------/
        virtual void Bind() override;
        virtual void UnBind() override;
        //------------------------------------------------------------/
        virtual void Clear() override;
        virtual void Draw() const override;
        //------------------------------------------------------------/
        void SetVertexAndIndex(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs) override;
        void SetVertex(std::vector<EMPVertex> vertexArray) override;
    
    private:
        GLuint m_VAO, m_VBO, m_IBO, m_uniformModel;
        std::vector<EMPVertex> m_vertexs;
        std::vector<GLuint> m_indexs;
    };
}

#endif /* EMPBufferOpenGL_hpp */
