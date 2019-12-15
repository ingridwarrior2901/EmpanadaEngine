//
//  EMPAudioBuffer.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPAudioBuffer_hpp
#define EMPAudioBuffer_hpp

#include <iostream>
#include <string>

namespace EmpanadaEngine
{
    class IEMPAudioBuffer
    {
    public:
        //------------------------------------------------------------/
        IEMPAudioBuffer(std::string filePath): m_filePath(filePath) { }
        virtual ~IEMPAudioBuffer() {}
        //------------------------------------------------------------/
        virtual uint32_t GetBuffer() const = 0;
    private:
        std::string m_filePath;
    };
}

#endif /* EMPAudioBuffer_hpp */
