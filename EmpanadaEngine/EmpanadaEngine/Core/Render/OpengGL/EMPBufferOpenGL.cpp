//
//  EMPBufferOpenGL.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPBufferOpenGL.h"

namespace EmpanadaEngine
{
    
    // MARK: - Constructor
    
    EMPBufferOpenGL::EMPBufferOpenGL(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs)
    {
        SetVertexAndIndex(vertexs, indexs);
    }

    EMPBufferOpenGL::~EMPBufferOpenGL()
    {
        Clear();
    }

    // MARK: - Public Methods

    void EMPBufferOpenGL::SetVertex(std::vector<EMPVertex> vertexArray)
    {
        m_vertexs = vertexArray;
    }

    void EMPBufferOpenGL::SetVertexAndIndex(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs)
    {
        m_vertexs = vertexs;
        m_indexs = indexs;
        
        m_VAO = 0;
        m_VBO = 0;
        m_IBO = 0;
        
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);
        
        glGenBuffers(1, &m_IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     m_indexs.size() * sizeof(GLuint),
                     &m_indexs[0],
                     GL_STATIC_DRAW);
        
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER,
                     m_vertexs.size() * sizeof(EMPVertex),
                     &m_vertexs[0],
                     GL_STATIC_DRAW);
    }

    void EMPBufferOpenGL::Bind()
    {
        glBindVertexArray(m_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    }
    
    void EMPBufferOpenGL::UnBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void EMPBufferOpenGL::Draw() const
    {
        glDrawElements(GL_TRIANGLES,
                       (GLsizei)m_indexs.size(),
                       GL_UNSIGNED_INT,
                       0);
    }

    void EMPBufferOpenGL::Clear()
    {
        if (m_IBO != 0)
        {
            glDeleteBuffers(1, &m_IBO);
            m_IBO = 0;
        }
        
        if (m_VBO != 0)
        {
            glDeleteBuffers(1, &m_VBO);
            m_VBO = 0;
        }
        
        if (m_VAO != 0)
        {
            glDeleteVertexArrays(1, &m_VAO);
            m_VAO = 0;
        }
        
        m_indexs.clear();
        m_vertexs.clear();
    }
}
