//
//  IEMPAudio.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/10/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "IEMPAudio.h"
#include "OpenAL/EMPAudioOpenAL.h"

namespace EmpanadaEngine
{
    EMPRef<IEMPAudio> IEMPAudio::Load(std::string filePath)
    {
        return IEMPAudioPTR(new EMPAudioOpenAL(filePath));
    }
}

