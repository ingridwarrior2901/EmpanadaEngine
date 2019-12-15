//
//  IEMPEntity.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/30/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPEntity_hpp
#define EMPEntity_hpp

#include "../../../Lib/Common/glm/glm/glm.hpp"
#include "../Components/IEMPComponent.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>

namespace EmpanadaEngine
{
    class IEMPEntity
    {
    public:
        //------------------------------------------------------------/
        IEMPEntity() {}
        virtual ~IEMPEntity() {}
        //------------------------------------------------------------/
        virtual void Update(float deltaTime);
        virtual void Draw() = 0;
        //------------------------------------------------------------/
        void SetName(std::string name);
        std::string GetName() const { return m_name; }
        //------------------------------------------------------------/
        void AddComponent(IEMPComponentPTR component);
        void RemoveComponent(IEMPComponentPTR component);
        //------------------------------------------------------------/
        template <class T>
        std::shared_ptr<T> GetComponent()
        {
            auto it = std::find_if(m_components.begin(), m_components.end(),
                                   [] (const IEMPComponentPTR component)
                                   {
                                       return std::dynamic_pointer_cast<T>(component) != nullptr;
                                   });
            return it != m_components.end() ? std::dynamic_pointer_cast<T>(*it) : nullptr;
        }
    protected:
        glm::vec2 m_size;
    private:
        std::set<IEMPComponentPTR> m_components;
        std::string m_name;
    };

    using IEMPEntityUnique = std::unique_ptr<IEMPEntity>;
    using IEMPEntityPTR = std::shared_ptr<IEMPEntity>;
}

#endif /* EMPEntity_hpp */
