//
//  EMPFontManager.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPFontManager.h"
#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>
#ifdef _WIN32 || _WIN64
#include "../../../Lib/Window/glfw/glfw3.h"
#elif __APPLE__
#include <GLFW/glfw3.h>
#endif

namespace EmpanadaEngine
{
    // MARK: - Constructor
    EMPFontManager::~EMPFontManager() {}

    // MARK: - Public Methods
    void EMPFontManager::LoadFont(std::string fontPath)
    {
        m_characters.clear();
        FT_Library ft;
        
        if (FT_Init_FreeType(&ft))
        {
            std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        }

        FT_Face face;
        if (FT_New_Face(ft, fontPath.c_str(), 0, &face))
        {
            std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
            return;
        }

        FT_Set_Pixel_Sizes(face, 0, 48);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        
        for (GLubyte charIndex = 0; charIndex < 128; charIndex++)
        {
            if (FT_Load_Char(face, charIndex, FT_LOAD_RENDER))
            {
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                continue;
            }
            
            IEMPTexturePTR texture = IEMPTexture::Load(face->glyph->bitmap.width, face->glyph->bitmap.rows, face->glyph->bitmap.buffer);
            
            EMPCharacter character =
            {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<unsigned int>(face->glyph->advance.x)
            };
            m_characters.insert(std::pair<GLchar, EMPCharacter>(charIndex, character));
        }
        
        FT_Done_Face(face);
        FT_Done_FreeType(ft);
    }
}
