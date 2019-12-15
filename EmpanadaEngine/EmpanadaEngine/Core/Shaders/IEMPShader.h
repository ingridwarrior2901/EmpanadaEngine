//
//  IEMPShader.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef IEMPShader_hpp
#define IEMPShader_hpp

#include "EMPVertex.h"
#include "../Game/EMPGameConfiguration.h"
#include "../EmpanadaEngine.h"
#include <iostream>
#include <string>

namespace EmpanadaEngine
{
    class IEMPShader
    {
    public:
        IEMPShader() {}
        //------------------------------------------------------------/
        virtual ~IEMPShader() {}
        //------------------------------------------------------------/
        virtual void UseShader() const = 0;
        virtual void ResetShader() const = 0;
        virtual void ClearShader() const = 0;
        virtual void SetupAttributes() const = 0;
       //------------------------------------------------------------/
        virtual void SetInt(const std::string& name, int val) = 0;
        virtual void SetFloat(const std::string& name, float val) = 0;
        virtual void SetVec3(const std::string& name, const glm::vec3& vec) = 0;
        virtual void SetVec4(const std::string& name, const glm::vec4& vec) = 0;
        virtual void SetMatrix(const std::string& name, const glm::mat4& matrix) = 0;
        //------------------------------------------------------------/
        virtual int GetLocation(const char* name) const = 0;
        virtual int GetAttribute(const char* name) const = 0;
        //------------------------------------------------------------/
        static EMPRef<IEMPShader> Load(const std::string& vertexFilename, const std::string& fragmentFilename,API::EMPRenderType renderType = API::EMPRenderType::OpenGL);
    };

    using IEMPShaderPTR = std::shared_ptr<IEMPShader>;
}


#endif /* IEMPShader_hpp */
