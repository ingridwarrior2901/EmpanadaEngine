//
//  EMPTransformComponent.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPTransformComponent_hpp
#define EMPTransformComponent_hpp

#include "IEMPComponent.h"
#include "../../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    class EMPTransformComponent: public IEMPComponent
    {
    public:
        //------------------------------------------------------------/
        EMPTransformComponent(IEMPEntity *owner);
        ~EMPTransformComponent() {}
        //------------------------------------------------------------/
        const glm::vec3& GetPosition() const;
        void SetPosition(const glm::vec3& position);
        //------------------------------------------------------------/
        const glm::vec3& GetRotation() const;
        const void SetRotation(const glm::vec3& rotation);
        //------------------------------------------------------------/
        const glm::quat& GetRotationQuat() const;
        const void SetRotation(const glm::quat& quat);
        //------------------------------------------------------------/
        const glm::vec3& GetScale() const;
        void SetScale(const glm::vec3& scale);
        //------------------------------------------------------------/
        void SetSize(const glm::vec2& size);
        glm::vec2 GetSize() const;
        //------------------------------------------------------------/
        virtual void Update(float deltaTime);
        
    private:
        glm::vec3 m_position;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;
        glm::vec2 m_size;
        float angle;
    };

    using EMPTransformComponentPTR = std::shared_ptr<EMPTransformComponent>;
}

#endif /* EMPTransformComponent_hpp */
