//
//  EMPAudioOpenAL.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/10/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPAudioOpenAL_hpp
#define EMPAudioOpenAL_hpp

#include "../IEMPAudio.h"
#ifdef _WIN32 || _WIN64
#include "../../../Lib/Window/openal/AL/al.h"
#include "../../../Lib/Window/openal/AL/alc.h"
#elif __APPLE__
#include <OpenAL/OpenAL.h>
#endif

namespace EmpanadaEngine
{
    class EMPAudioOpenAL: public IEMPAudio
    {
    public:
        //------------------------------------------------------------/
        EMPAudioOpenAL(std::string filePath);
        virtual ~EMPAudioOpenAL() {}
        //------------------------------------------------------------/
        virtual void PlaySound() override;
        virtual void StopSound() override;
        virtual void Pause() override;
        virtual void SetPitch(float pitch) override;
        virtual void SetGain(float gain) override;
        virtual void SetLooping(bool loop) override;
        //------------------------------------------------------------/
        unsigned int GetSource() const override { return m_source; }
        //------------------------------------------------------------/
    private:
        ALuint m_source;
    };

    using EMPAudioOpenALPTR = std::shared_ptr<EMPAudioOpenAL>;
}

#endif /* EMPAudioOpenAL_hpp */
