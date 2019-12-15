//
//  EMPEventManager.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPEventManager.h"

namespace EmpanadaEngine
{
    // MARK: - Public Methods
    void EMPEventManager::Register(EMPEventType eventType, EMPEventDelegate* observer)
    {
        m_observers[eventType].push_back(observer);
    }

    void EMPEventManager::UnRegister(EMPEventType eventType, EMPEventDelegate* observer)
    {
        auto receiversEntry = m_observers.find(eventType);
        if (receiversEntry != end(m_observers))
        {
            size_t size = receiversEntry->second.size();
            
            for (int i = 0; i < size; i++)
            {
                if (receiversEntry->second[i] == observer)
                {
                    m_observers[eventType].erase( m_observers[eventType].begin() + i);
                }
            }
        }
    }

    void EMPEventManager::Notify(EMPEventType eventType, EMPEvent& event)
    {
        auto receiverEventType = m_observers.find(eventType);
        if (receiverEventType != end(m_observers))
        {
            auto const& observers = receiverEventType->second;
            
            switch (receiverEventType->first)
            {
                case EMPEventType::EMPWindowResize:
                    for (auto const& observer : observers)
                    {
                        observer->OnWindowSizeChange(event);
                    }
                    break;
                case EMPEventType::EMPWindowClose:
                    for (auto const& observer : observers)
                    {
                        observer->OnWindowClose(event);
                    }
                    break;
                case EMPEventType::EMPInputMouseCursorChange:
                    for (auto const& observer : observers)
                    {
                        observer->OnCursorChanged(event);
                    }
                    break;
                    
                case EMPEventType::EMPInputMouseButtonPressed:
                case EMPEventType::EMPInputMouseButtonReleased:
                    for (auto const& observer : observers)
                    {
                        observer->OnMousePressed(event);
                    }
                    break;
                case EMPEventType::EMPInputKeyPressed:
                case EMPEventType::EMPInputKeyRepeat:
                case EMPEventType::EMPInputKeyReleased:
                    for (auto const& observer : observers)
                    {
                        observer->OnKeyChanged(event);
                    }
                    break;
            }
        }
    }
}
