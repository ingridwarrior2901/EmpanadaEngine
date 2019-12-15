//
//  EMPButton.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/12/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPButton_hpp
#define EMPButton_hpp

#include "../ECS/Entities/EMPModel.h"
#include "../Events/EMPEventDelegate.h"
#include <functional>
#include <iostream>
#include <string>

namespace EmpanadaEngine
{
    class EMPButton: public EMPModel, public EMPEventDelegate
    {
        using ButtonCallback = std::function<void()>;
        
    public:
        //------------------------------------------------------------/
        EMPButton(IEMPShaderPTR defaultShader, std::string buttonImage, glm::vec2 position, glm::vec2 size, const ButtonCallback& callback);
        ~EMPButton();
        //------------------------------------------------------------/
        virtual void Draw() override;
        virtual void Update(float deltaTime) override;
        virtual void OnMousePressed(EMPEvent &event) override;
        virtual void OnCursorChanged(EMPEvent &event) override;
        //------------------------------------------------------------/
    private:
        glm::vec2 m_position;
        glm::vec2 m_size;
        IEMPShaderPTR m_defaultShader;
        IEMPTexturePTR m_buttonTexture;
        ButtonCallback m_callback;
        glm::vec3 m_cursorPosition;
    };

    using EMPButtonPTR = std::shared_ptr<EMPButton>;
}

#endif /* EMPButton_hpp */
