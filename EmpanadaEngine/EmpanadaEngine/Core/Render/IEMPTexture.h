//
//  IEMPTexture.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/29/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef IEMPTexture_h
#define IEMPTexture_h

#include <iostream>
#include <string>

#include "../EmpanadaEngine.h"
#include "../Game/EMPGameConfiguration.h"
#include "../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    class IEMPTexture
    {
    public:
        IEMPTexture() {}
        //------------------------------------------------------------/
        static EMPRef<IEMPTexture> Load(const std::string& path, API::EMPRenderType renderType = API::EMPRenderType::OpenGL);
        static EMPRef<IEMPTexture> Load(unsigned int width, unsigned int rows, unsigned char*  buffer, API::EMPRenderType renderType = API::EMPRenderType::OpenGL);
        //------------------------------------------------------------/
        virtual uint32_t GetId() const = 0;
        virtual glm::vec2 GetSize() const = 0;
        //------------------------------------------------------------/
        virtual void Bind() const = 0;
    protected:
        int m_width, m_height;
    };
    using IEMPTexturePTR = std::shared_ptr<IEMPTexture>;
}

#endif /* IEMPTexture_h */
