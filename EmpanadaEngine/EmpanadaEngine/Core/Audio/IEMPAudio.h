//
//  IEMPAudio.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/10/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef IEMPAudio_hpp
#define IEMPAudio_hpp

#include <iostream>
#include <string>
#include "../EmpanadaEngine.h"

namespace EmpanadaEngine
{
    class IEMPAudio
    {
    public:
        //------------------------------------------------------------/
        IEMPAudio(std::string filePath): m_filePath(filePath) {}
        virtual ~IEMPAudio() {}
        //------------------------------------------------------------/
        virtual void PlaySound() = 0;
        virtual void StopSound() = 0;
        virtual void Pause() = 0;
        virtual void SetPitch(float pitch) = 0;
        virtual void SetGain(float gain) = 0;
        virtual void SetLooping(bool loop) = 0;
        //------------------------------------------------------------/
        virtual unsigned int GetSource() const = 0;
        static EMPRef<IEMPAudio> Load(std::string filePath);
        //------------------------------------------------------------/
    protected:
        bool m_isPlaying;
    private:
        std::string m_filePath;
    };

    using IEMPAudioPTR = std::shared_ptr<IEMPAudio>;
}

#endif /* IEMPAudio_hpp */
