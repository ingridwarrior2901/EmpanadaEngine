//
//  EMPComponent.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/4/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPComponent_hpp
#define EMPComponent_hpp

#include <iostream>

namespace EmpanadaEngine
{
    class IEMPEntity;
    
    class IEMPComponent
    {
    public:
        //------------------------------------------------------------/
        IEMPComponent(IEMPEntity *owner): m_owner(owner) {}
        virtual ~IEMPComponent() {}
        //------------------------------------------------------------/
        virtual void Update(float deltaTime) = 0;
        //------------------------------------------------------------/
        IEMPEntity *GetOwner() const { return m_owner; }

    private:
        IEMPEntity *m_owner;
    };

    using IEMPComponentPTR = std::shared_ptr<IEMPComponent>;
}


#endif /* EMPComponent_hpp */
