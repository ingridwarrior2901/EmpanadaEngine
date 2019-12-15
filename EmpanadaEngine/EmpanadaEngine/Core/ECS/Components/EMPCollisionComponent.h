//
//  EMPCollisionComponent.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/10/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPCollisionComponent_hpp
#define EMPCollisionComponent_hpp

#include "IEMPComponent.h"
#include "../Entities/EMPModel.h"
#include "../../../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    class EMPCollisionComponent: public IEMPComponent
    {
    public:
        //------------------------------------------------------------/
        EMPCollisionComponent(IEMPEntity *owner, glm::vec2 size = glm::vec2(0.0f));
        ~EMPCollisionComponent() {}
        //------------------------------------------------------------/
        void SetSize(const glm::vec2& size);
        glm::vec2 GetSize() const { return m_size; }
           //------------------------------------------------------------/
        virtual void Update(float deltaTime) {}
        //------------------------------------------------------------/
    private:
        glm::vec2 m_size;
    };

    using EMPCollisionComponentPTR = std::shared_ptr<EMPCollisionComponent>;
}
#endif /* EMPCollisionComponent_hpp */
