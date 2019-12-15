//
//  EMPShaderOpenGL.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPShaderOpenGL.h"
#include "../Game/EMPMacros.h"
#include "../../Lib/Common/glm/glm/gtc/matrix_transform.hpp"
#include "../../Lib/Common/glm/glm/gtc/type_ptr.hpp"
#include <fstream>
#include <sstream>

namespace EmpanadaEngine
{
    // MARK: - Constants
    namespace EMPShaderOpenGLConstants
    {
        const char * const shaderVetexPosition = "position";
        const char * const shaderVetexColor = "color";
        const char * const shaderVetexTexture = "texCoord";
    }

    // MARK: - Constructor
    EMPShaderOpenGL::EMPShaderOpenGL(const std::string& vertexFilename, const std::string& fragmentFilename)
    {
        const std::string vertexCode = ReadString(vertexFilename);
        const std::string fragmentCode = ReadString(fragmentFilename);
        CompileShader(vertexCode, fragmentCode);
    }
    
    EMPShaderOpenGL::~EMPShaderOpenGL()
    {
        ClearShader();
    }
    
    // MARK: - Lifecycle
    
    void EMPShaderOpenGL::UseShader() const
    {
        glUseProgram(m_shaderID);
    }

    void EMPShaderOpenGL::ResetShader() const
    {
        glUseProgram(0);
    }

    void EMPShaderOpenGL::ClearShader() const
    {
        if (m_shaderID != 0)
        {
            glDeleteProgram(m_shaderID);
        }
    }

    void EMPShaderOpenGL::SetupAttributes() const
    {
        GLuint position = GetAttribute(EMPShaderOpenGLConstants::shaderVetexPosition);
        if (position != EMP_NOT_FOUND)
        {
            glEnableVertexAttribArray(position);
            glVertexAttribPointer(position, 3, GL_FLOAT, false, sizeof(EMPVertex), reinterpret_cast<const void*>(offsetof(EMPVertex, position)));
        }
        
        GLuint color = GetAttribute(EMPShaderOpenGLConstants::shaderVetexColor);
        if (color != EMP_NOT_FOUND)
        {
            glEnableVertexAttribArray(color);
            glVertexAttribPointer(color, 3, GL_FLOAT, false, sizeof(EMPVertex), reinterpret_cast<const void*>(offsetof(EMPVertex, color)));
        }
        
        GLuint textureLocation = GetAttribute(EMPShaderOpenGLConstants::shaderVetexTexture);
        if (textureLocation != EMP_NOT_FOUND)
        {
            glEnableVertexAttribArray (textureLocation);
            glVertexAttribPointer (textureLocation, 2, GL_FLOAT, false, sizeof (EMPVertex), reinterpret_cast<const void*>(offsetof (EMPVertex, textureCoord)));
        }
    }

    // MARK: - Public Methods
    
    void EMPShaderOpenGL::SetInt(const std::string& name, int value)
    {
        glUniform1i(GetLocation(name.c_str()), value);
    }
    
    void EMPShaderOpenGL::SetFloat(const std::string& name, float value)
    {
        glUniform1f(GetLocation(name.c_str()), value);
    }
    
    void EMPShaderOpenGL::SetVec3(const std::string& name, const glm::vec3& value)
    {
        glUniform3f(GetLocation(name.c_str()), value.x, value.y, value.z);
    }
    
    void EMPShaderOpenGL::SetVec4(const std::string& name, const glm::vec4& value)
    {
        glUniform4f(GetLocation(name.c_str()), value.r, value.g, value.b, value.a);
    }
    
    void EMPShaderOpenGL::SetMatrix(const std::string& name, const glm::mat4& matrix)
    {
        glUniformMatrix4fv(GetLocation(name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    int EMPShaderOpenGL::GetAttribute(const char* name) const
    {
        return glGetAttribLocation(m_shaderID, name);
    }
    
    int EMPShaderOpenGL::GetLocation(const char* name) const
    {
        return glGetUniformLocation(m_shaderID, name);
    }

    // MARK: - Private Methods

    std::string EMPShaderOpenGL::ReadString(const std::string& filename)
    {
        std::ifstream istream(filename.c_str(), std::ios_base::binary);
        std::stringstream sstream;
        sstream << istream.rdbuf();
        return sstream.str();
    }
        
    void EMPShaderOpenGL::CompileShader(const std::string& vertexCode, const std::string& fragmentCode)
    {
        m_shaderID = glCreateProgram();
        
        if (!m_shaderID)
        {
            printf("Error creating shader program!\n");
            return;
        }
        
        AddShader(m_shaderID, vertexCode, GL_VERTEX_SHADER);
        AddShader(m_shaderID, fragmentCode, GL_FRAGMENT_SHADER);
        
        GLint result = 0;
        GLchar eLog[1024] = { 0 };
        
        glLinkProgram(m_shaderID);
        glGetProgramiv(m_shaderID, GL_LINK_STATUS, &result);
        
        if (!result)
        {
            glGetProgramInfoLog(m_shaderID, sizeof(eLog), NULL, eLog);
            printf("Error linking program: '%s'\n", eLog);
            return;
        }
        
        glValidateProgram(m_shaderID);
        glGetProgramiv(m_shaderID, GL_VALIDATE_STATUS, &result);
        
        if (!result)
        {
            glGetProgramInfoLog(m_shaderID, sizeof(eLog), NULL, eLog);
            printf("Error validating program: '%s'\n", eLog);
            return;
        }
    }

    void EMPShaderOpenGL::AddShader(GLuint program, const std::string& shaderCode, GLenum shaderType)
    {
        GLuint shader = glCreateShader(shaderType);
        const char *finalCode = shaderCode.c_str();
        
        const GLchar* code[1];
        code[0] = finalCode;
        
        GLint codeLength[1];
        codeLength[0] = strlen(finalCode);
        
        glShaderSource(shader, 1, code, codeLength);
        glCompileShader(shader);
        
        GLint result = 0;
        GLchar eLog[1024] = { 0 };
        glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
        
        if (!result)
        {
            glGetShaderInfoLog(shader, sizeof(eLog), NULL, eLog);
            printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
            return;
        }
        
        glAttachShader(program, shader);
        glDeleteShader(shader);
    }
}
      
