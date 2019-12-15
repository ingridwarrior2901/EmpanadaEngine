//
//  EMPMaterial.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/30/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPMaterial_hpp
#define EMPMaterial_hpp

#include "../../Render/IEMPTexture.h"
#include "../../Shaders/IEMPShader.h"

namespace EmpanadaEngine
{
    class EMPMaterial
    {
    public:
        //------------------------------------------------------------/
        EMPMaterial(const IEMPShaderPTR& shader, const IEMPTexturePTR& texture = nullptr);
        //------------------------------------------------------------/
        const IEMPShaderPTR& GetShader() const;
        const IEMPTexturePTR& GetTexture() const;
        //------------------------------------------------------------/
        void SetShader(const IEMPShaderPTR& shader);
        void SetTexture(const IEMPTexturePTR& texture);
        void Draw(glm::mat4 modelMatrix);
    private:
        //------------------------------------------------------------/
        IEMPShaderPTR m_shader;
        IEMPTexturePTR m_texture;
        bool enableTexture;
    };
    
    using EMPMaterialPTR = std::shared_ptr<EMPMaterial>;
}


#endif /* EMPMaterial_hpp */
