//
//  EMPGameApp.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPGameApp_hpp
#define EMPGameApp_hpp

#include "IEMPTimer.h"
#include "EMPGameConfiguration.h"
#include "../Audio/EMPAudioManager.h"
#include "../Events/EMPEventDelegate.h"
#include "../GUI/EMPFontManager.h"
#include "../Inputs/EMPInputManager.h"
#include "../Scenes/EMPSceneManager.h"
#include "../Windows/EMPWindowManager.h"


namespace EmpanadaEngine
{
    using EMPWindowManagerPTR = std::unique_ptr<EMPWindowManager>;
    using EMPInputManagerPTR = std::unique_ptr<EMPInputManager>;
    using EMPAudioManagerPTR = std::unique_ptr<EMPAudioManager>;
    using EMPFontManagerPTR = std::unique_ptr<EMPFontManager>;
    
    using EMPTimerPTR = std::unique_ptr<IEMPTimer>;
    
    class EMPGameApp: public EMPEventDelegate
    {
    public:
        //------------------------------------------------------------/
        EMPGameApp(EMPGameConfiguration& gameConfiguration, const EMPWindowConfiguration& windowConfiguration);
        virtual ~EMPGameApp();
        //------------------------------------------------------------/
        void Start();
        //------------------------------------------------------------/
        inline static EMPGameApp& GetInstance() { return *instance; }
        //------------------------------------------------------------/
        EMPWindowManagerPTR& GetWindowManager() { return m_windowManager; }
        EMPInputManagerPTR& GetInputManager() { return m_inputManager; }
        EMPAudioManagerPTR& GetAudioManager() { return m_audioManager; }
        EMPFontManagerPTR& GetFontManager() { return m_fontManager; }
        //------------------------------------------------------------/
        virtual void OnWindowClose(EMPEvent& event) override;
        //------------------------------------------------------------/
        void PushScene(EMPScenePTR scene);
        void PopScene(EMPScenePTR scene);
    
    private:
        static EMPGameApp *instance;
        EMPWindowManagerPTR m_windowManager;
        EMPInputManagerPTR m_inputManager;
        EMPAudioManagerPTR m_audioManager;
        EMPFontManagerPTR m_fontManager;
        EMPTimerPTR m_timer;
        
        bool m_running;
    };
}

#endif /* EMPGameApp_hpp */
