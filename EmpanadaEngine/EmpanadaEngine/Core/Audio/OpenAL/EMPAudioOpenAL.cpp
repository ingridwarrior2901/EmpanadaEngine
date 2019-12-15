//
//  EMPAudioOpenAL.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/10/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPAudioOpenAL.h"
#include "EMPAudioBufferOpenAL.h"
#include "../../EmpanadaEngine.h"

namespace EmpanadaEngine
{
    EMPAudioOpenAL::EMPAudioOpenAL(std::string filePath) : IEMPAudio(filePath)
    {
        EMPAudioBufferOpenALPTR audioBuffer = NewRef<EMPAudioBufferOpenAL>(filePath);
        
        alGenSources((ALuint)1, &m_source);
        alSourcef(m_source, AL_PITCH, 1);
        alSourcef(m_source, AL_GAIN, 1);
        alSource3f(m_source, AL_POSITION, 0, 0, 0);
        alSource3f(m_source, AL_VELOCITY, 0, 0, 0);
        alSourcei(m_source, AL_LOOPING, AL_FALSE);
        
        if (audioBuffer && audioBuffer->GetBuffer())
        {
            alSourcei(m_source, AL_BUFFER, audioBuffer->GetBuffer());
        }
    }

    void EMPAudioOpenAL::PlaySound()
    {
        m_isPlaying = true;
        alSourcePlay(m_source);
    }
    
    void EMPAudioOpenAL::StopSound()
    {
        m_isPlaying = false;
        alSourceStop(m_source);
    }

    void EMPAudioOpenAL::Pause()
    {
        if (m_isPlaying)
        {
            alSourcePause(m_source);
        }
    }

    void EMPAudioOpenAL::SetPitch(float pitch)
    {
        alSourcef(m_source, AL_PITCH, pitch);
    }

    void EMPAudioOpenAL::SetGain(float gain)
    {
        alSourcef(m_source, AL_GAIN, gain);
    }

    void EMPAudioOpenAL::SetLooping(bool loop)
    {
        int loopValue = loop ? AL_TRUE : AL_FALSE;
        alSourcei(m_source, AL_LOOPING, loopValue);
    }
}
