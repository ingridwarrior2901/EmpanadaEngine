//
//  EMPAudioManager.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPAudioManager_hpp
#define EMPAudioManager_hpp

#include "IEMPAudio.h"
#include "../EmpanadaEngine.h"

#include <iostream>
#include <map>
#include <string>

#ifdef _WIN32 || _WIN64
#include "../../Lib/Window/openal/AL/al.h"
#include "../../Lib/Window/openal/AL/alc.h"
#elif __APPLE__
#include <OpenAL/OpenAL.h>
#endif


namespace EmpanadaEngine
{
    enum class EMPAudioAPI
    {
        OpenAL
    };

    class EMPAudioManager
    {
    public:
        //------------------------------------------------------------/
        EMPAudioManager(EMPAudioAPI type = EMPAudioAPI::OpenAL);
        ~EMPAudioManager();
        //------------------------------------------------------------/
        void PlayAudio(std::string filePath);
        void StopAudio(std::string filePath);
        //------------------------------------------------------------/
    private:
        //------------------------------------------------------------/
        void SetupAL();
        void StopAL();
        //------------------------------------------------------------/
        std::map<std::string, IEMPAudioPTR> m_audioMap;
        ALCcontext *m_context;
        ALCdevice *m_device;
    };
}

#endif /* EMPAudioManager_hpp */
