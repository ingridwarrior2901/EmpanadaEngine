//
//  EMPGameApp.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPGameApp.h"
#include "../EmpanadaEngine.h"
#include "../Events/EMPEventManager.h"
#include "EMPTimerManager.h"

namespace EmpanadaEngine
{
    EMPGameApp *EMPGameApp::instance = nullptr;
    
    // MARK: - Constructor
    
    EMPGameApp::EMPGameApp(EMPGameConfiguration& gameConfiguration, const EMPWindowConfiguration& windowConfiguration)
    {
        instance = this;
        m_running = true;
        
        m_windowManager = NewUnique<EMPWindowManager>(windowConfiguration);
        if (m_windowManager && m_windowManager->GetWindowInterface())
        {
            m_inputManager = NewUnique<EMPInputManager>(gameConfiguration.interfaceType, m_windowManager->GetWindowInterface()->GetWindow());
        }
        
        m_timer = EMPTimerManager::LoadTimer(gameConfiguration.interfaceType);
        m_timer->SetMaxFps(60.0f);
        m_audioManager = NewUnique<EMPAudioManager>();
        m_fontManager = NewUnique<EMPFontManager>();
        EMPEventManager::InitInstance();
        EMPSceneManager::InitInstance();
    }
    
    EMPGameApp::~EMPGameApp() {}

    // MARK: - Lifecycle
    
    void EMPGameApp::Start()
    {
        EMPEventManager::GetInstance().Register(EMPEventType::EMPWindowClose, this);
        EMPSceneManager::GetInstance().Start();
        
        
        if (m_windowManager && m_windowManager->GetWindowInterface())
        {
            while (m_running)
            {
                m_timer->CalculateTime();
                if( m_timer->GetDeltaTime() >= m_timer->GetFrameRate() )
                {
                    m_timer->CalculateLastTime();
                    m_windowManager->GetWindowInterface()->StartFrame();
                    
                    EMPSceneManager::GetInstance().Update(m_timer->GetDeltaTime());
                    EMPSceneManager::GetInstance().DrawEntities();
                    EMPSceneManager::GetInstance().CheckCollision();
                    
                    m_windowManager->GetWindowInterface()->Update();
                    m_windowManager->GetWindowInterface()->EndFrame();
                }
              
            }
        }
    }
    
    void EMPGameApp::OnWindowClose(EMPEvent& event)
    {
        m_running = false;
        if (m_windowManager && m_windowManager->GetWindowInterface())
        {
            m_windowManager->GetWindowInterface()->Terminate();
        }
    }

    // MARK: - Public Methods
    
    void EMPGameApp::PushScene(EMPScenePTR scene)
    {
        EMPSceneManager::GetInstance().PushScene(scene);
    }

    void EMPGameApp::PopScene(EMPScenePTR scene)
    {
        EMPSceneManager::GetInstance().PopScene(scene);
    }
}
