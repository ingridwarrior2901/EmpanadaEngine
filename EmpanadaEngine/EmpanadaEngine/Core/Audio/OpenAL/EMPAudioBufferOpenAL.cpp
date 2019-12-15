//
//  EMPAudioBufferOpenAL.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPAudioBufferOpenAL.h"
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <vector>


namespace EmpanadaEngine
{
    // MARK: - Constants
    namespace EMPAudioBufferConstants
    {
        const std::string chunkIDHeader = "RIFF";
        const std::string waveHeader = "WAVE";
    }

    // MARK: - Constructor
    EMPAudioBufferOpenAL::EMPAudioBufferOpenAL(std::string filePath): IEMPAudioBuffer(filePath)
    {
        std::ifstream fileIn (filePath.c_str(), std::ios::binary);
        
        if (!fileIn.good()) { return; }
        
        fileIn.unsetf (std::ios::skipws);
        
        std::istream_iterator<uint8_t> begin (fileIn), end;
        std::vector<uint8_t> fileData (begin, end);
        
        std::string chunkID (fileData.begin(), fileData.begin() + 4);
        std::string wave (fileData.begin() + 8, fileData.begin() + 12);
        
        if (chunkID != EMPAudioBufferConstants::chunkIDHeader && wave != EMPAudioBufferConstants::waveHeader) { return; }
        
        int chunkData = GetStringIndexOf(fileData, "data");
        int chunkFormat = GetStringIndexOf(fileData, "fmt");
        
        std::string channelData (fileData.begin() + chunkFormat + 12, fileData.begin() + chunkFormat + 14);
            
        uint16_t channel = TwoBytesToInt(fileData, chunkFormat + 10);
        uint32_t sampleRate = BytesToInt (fileData, chunkFormat + 12);
        
        int16_t bitsPerSample = TwoBytesToInt (fileData, chunkFormat + 22);
        
        int32_t dataSize = BytesToInt(fileData, chunkData + 4);
        std::vector<uint8_t> wavData (fileData.begin() + chunkData + 8, fileData.begin() + dataSize + chunkData + 8);

        ALuint buffer;
        alGenBuffers(1, &buffer);
        
        ALenum format;
        
        if (channel == 1)
        {
            format = bitsPerSample == 8 ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
        }
        else
        {
            format = bitsPerSample == 8 ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;
        }
        
        alBufferData(buffer, format, wavData.data(), dataSize, sampleRate);
        
        m_buffer = buffer;
    }

    // MARK: - Private Methods
    int EMPAudioBufferOpenAL::BytesToInt(std::vector<uint8_t>& source, int startIndex)
    {
        return (source[startIndex + 3] << 32) | (source[startIndex + 2] << 16) | (source[startIndex + 1] << 8) | source[startIndex] << 0;
    }

    int EMPAudioBufferOpenAL::TwoBytesToInt (std::vector<uint8_t>& source, int startIndex)
    {
        return (source[startIndex+1] <<8) + source[startIndex];
    }

    int EMPAudioBufferOpenAL::GetStringIndexOf(std::vector<uint8_t> &fileData, std::string string)
    {
        int indexOf = -1;
        
        int length = (int)string.length();
        
        for (int i = 0; i < fileData.size() - length; i++)
        {
            std::string section (fileData.begin() + i, fileData.begin() + i + length);
            
            if (section == string)
            {
                indexOf = i;
                break;
            }
        }
        
        return indexOf;
    }
}
