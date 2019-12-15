//
//  EMPShaderOpenGL.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPShaderOpenGL_hpp
#define EMPShaderOpenGL_hpp

#include "IEMPShader.h"
#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif
#include <vector>

namespace EmpanadaEngine
{
    class EMPShaderOpenGL: public IEMPShader
    {
    public:
        EMPShaderOpenGL(const std::string& vertexFilename, const std::string& fragmentFilename);
        //------------------------------------------------------------/
        virtual ~EMPShaderOpenGL();
        
        //------------------------------------------------------------/
        virtual void UseShader() const override;
        virtual void ResetShader() const override;
        virtual void ClearShader() const override;
        virtual void SetupAttributes() const override;
       //------------------------------------------------------------/
        virtual void SetInt(const std::string& name, int value) override;
        virtual void SetFloat(const std::string& name, float value) override;
        virtual void SetVec3(const std::string& name, const glm::vec3& value) override;
        virtual void SetVec4(const std::string& name, const glm::vec4& value) override;
        virtual void SetMatrix(const std::string& name, const glm::mat4& matrix) override;
        //------------------------------------------------------------/
        virtual int GetLocation(const char* name) const override;
        virtual int GetAttribute(const char* name) const override;
    private:
        std::string ReadString(const std::string& filename);
        //------------------------------------------------------------/
        void CompileShader(const std::string& vertexCode, const std::string& fragmentCode);
        void AddShader(GLuint program, const std::string& shaderCode, GLenum shaderType);
        //------------------------------------------------------------/
        GLuint m_shaderID;
        std::string m_shaderCode;
        std::vector<EMPVertex> m_vertexs;
        std::vector<GLuint> m_indexs;
        char* m_ELog;
        glm::mat4 m_projection;
    };
}

#endif /* EMPShaderOpenGL_hpp */
