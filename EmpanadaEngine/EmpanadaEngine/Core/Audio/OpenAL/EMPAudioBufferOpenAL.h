//
//  EMPAudioBufferOpenAL.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPAudioBufferOpenAL_hpp
#define EMPAudioBufferOpenAL_hpp

#include "../IEMPAudioBuffer.h"
#ifdef _WIN32 || _WIN64
#include "../../../Lib/Window/openal/AL/al.h"
#include "../../../Lib/Window/openal/AL/alc.h"
#elif __APPLE__
#include <OpenAL/OpenAL.h>
#endif

#include <iostream>
#include <vector>

namespace EmpanadaEngine
{
    class EMPAudioBufferOpenAL: public IEMPAudioBuffer
    {
    public:
        //------------------------------------------------------------/
        EMPAudioBufferOpenAL(std::string filePath);
        virtual ~EMPAudioBufferOpenAL() {}
        //------------------------------------------------------------/
        virtual uint32_t GetBuffer() const override { return m_buffer; }
    private:
        //------------------------------------------------------------/
        int GetStringIndexOf(std::vector<uint8_t>& fileData, std::string);
        int BytesToInt (std::vector<uint8_t>& source, int startIndex);
        int TwoBytesToInt (std::vector<uint8_t>& source, int startIndex);
        //------------------------------------------------------------/
        std::string m_filePath;
        ALuint m_buffer;
    };

    using EMPAudioBufferOpenALPTR = std::shared_ptr<EMPAudioBufferOpenAL>;
}

#endif /* EMPAudioBufferOpenAL_hpp */
