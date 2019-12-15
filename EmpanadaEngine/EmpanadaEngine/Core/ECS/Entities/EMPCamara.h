//
//  EMPCamara.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/1/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPCamara_hpp
#define EMPCamara_hpp

#include "EMPModel.h"

namespace EmpanadaEngine
{
    class EMPCamara: public EMPModel
    {
    public:
        //------------------------------------------------------------/
        EMPCamara();
        //------------------------------------------------------------/
        const glm::vec4& GetClearColor() const { return m_clearColor; }
        const glm::vec4& GetViewport() const { return m_viewPort; };
        //------------------------------------------------------------/
        glm::mat4 GetViewMatrix() const;
        glm::mat4 GetProjection() const;
        //------------------------------------------------------------/
        void SetViewport(const glm::vec4& viewport);
        void SetClearColor(const glm::vec4& color);
       //------------------------------------------------------------/
        virtual void Draw() override;
        virtual void Update(float deltaTime) override;
    private:
        
        glm::vec4 m_clearColor;
        glm::vec4 m_viewPort;
    };

    using EMPCamaraPTR = std::shared_ptr<EMPCamara>;
}

#endif /* EMPCamara_hpp */
