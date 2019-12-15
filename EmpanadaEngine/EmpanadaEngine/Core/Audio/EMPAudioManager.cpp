//
//  EMPAudioManager.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPAudioManager.h"

namespace EmpanadaEngine
{
    // MARK: - Constructor
    EMPAudioManager::EMPAudioManager(EMPAudioAPI type)
    {
        switch (type)
        {
            case EMPAudioAPI::OpenAL:
                SetupAL();
                break;
        }
    }

    EMPAudioManager::~EMPAudioManager()
    {
        m_audioMap.clear();
        StopAL();
    }

    // MARK: - Public Methods
    void EMPAudioManager::PlayAudio(std::string filePath)
    {
        if (m_audioMap.find(filePath) == m_audioMap.end())
        {
            IEMPAudioPTR audio = IEMPAudio::Load(filePath);
            m_audioMap[filePath] = audio;
            m_audioMap[filePath]->PlaySound();
        }
    }

    void EMPAudioManager::StopAudio(std::string filePath)
    {
        if (m_audioMap.find(filePath) != m_audioMap.end())
        {
            m_audioMap[filePath]->StopSound();
        }
    }

    void EMPAudioManager::SetupAL()
    {
        m_device = alcOpenDevice(NULL);
        
        if (m_device)
        {
            m_context = alcCreateContext(m_device, NULL);
            alcMakeContextCurrent(m_context);
        }
    }

    void EMPAudioManager::StopAL()
    {
        if (m_device && m_context)
        {
            alcMakeContextCurrent(NULL);
            alcDestroyContext(m_context);
            alcCloseDevice(m_device);
        }
    }
}
