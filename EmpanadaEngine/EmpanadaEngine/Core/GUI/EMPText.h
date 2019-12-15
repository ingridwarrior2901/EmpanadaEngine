//
//  EMPText.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPText_hpp
#define EMPText_hpp

#include "../ECS/Entities/EMPModel.h"
#include <iostream>
#include <string>

namespace EmpanadaEngine
{
    class EMPText: public EMPModel
    {
    public:
        //------------------------------------------------------------/
        EMPText(std::string text, glm::vec2 position, float size, glm::vec3 color);
        ~EMPText() {}
        //------------------------------------------------------------/
        void SetText(std::string text);
        void SetPosition(glm::vec2 position);
        //------------------------------------------------------------/
        virtual void Draw() override;
        virtual void Update(float deltaTime) override;
        
    private:
        //------------------------------------------------------------/
        IEMPShaderPTR m_defaultShader;
        std::string m_text;
        glm::vec2 m_position;
        glm::vec3 m_color;
        float m_size;
        //------------------------------------------------------------/
        GLuint m_VAO, m_VBO;
    };

    using EMPTextPTR = std::shared_ptr<EMPText>;
}

#endif /* EMPText_hpp */
