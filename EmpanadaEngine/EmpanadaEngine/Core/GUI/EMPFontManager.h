//
//  EMPFontManager.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPFontManager_hpp
#define EMPFontManager_hpp

#include "EMPCharacter.h"
#include <iostream>
#include <map>
#include <string>

namespace EmpanadaEngine
{
    class EMPFontManager
    {
    public:
        //------------------------------------------------------------/
        EMPFontManager() {}
        ~EMPFontManager();
        //------------------------------------------------------------/
        void LoadFont(std::string fontPath);
        //------------------------------------------------------------/
        std::map<char, EMPCharacter> GetCharacters() const { return m_characters; }
    private:
        //------------------------------------------------------------/
        std::map<char, EMPCharacter> m_characters;
    };
}

#endif /* EMPFontManager_hpp */
