//
//  EMPGameObject.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPGameObject_hpp
#define EMPGameObject_hpp

#include "IEMPEntity.h"
#include "../Components/EMPTransformComponent.h"

namespace EmpanadaEngine
{
    class EMPGameObject: public IEMPEntity
    {
    public:
        //------------------------------------------------------------/
        EMPGameObject();
        virtual ~EMPGameObject() {}
        //------------------------------------------------------------/
        virtual void Update(float deltaTime);
        virtual void Draw() {}
       //------------------------------------------------------------/
        EMPTransformComponentPTR GetTransformComponent() const { return m_transformComponent; }
       //------------------------------------------------------------/
        const glm::vec3& GetPosition() const { return m_transformComponent->GetPosition(); }
        const glm::vec3& GetRotation() const { return m_transformComponent->GetRotation(); }
        const glm::quat& GetRotationQuat() const { return m_transformComponent->GetRotationQuat(); }
        const glm::vec3& GetScale() const { return m_transformComponent->GetScale(); }
    private:
        EMPTransformComponentPTR m_transformComponent;
    };

    using EMPGameObjectPTR = std::shared_ptr<EMPGameObject>;
}

#endif /* EMPGameObject_hpp */
