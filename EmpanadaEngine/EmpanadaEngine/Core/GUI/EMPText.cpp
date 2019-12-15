//
//  EMPText.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/11/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPText.h"
#include "../Game/EMPGameApp.h"
#include "../../../Lib/Common/glm/glm/gtc/matrix_transform.hpp"
#include "../../../Lib/Common/glm/glm/gtc/type_ptr.hpp"

namespace EmpanadaEngine
{
    // MARK: - Constants

    namespace EMPTextConstants
    {
        const std::string textVertexFile = "Resources/text.vert";
        const std::string textFragmentFile = "Resources/text.frag";
        const std::string projection = "projection";
        const std::string textColor = "textColor";
        //TODO: Remove this constant, projection should be calculate from the windows size.
        const glm::vec2 windowSize = glm::vec2(800.0f, 600.0f);
    }
    
    // MARK: - Constructor
    EMPText::EMPText(std::string text, glm::vec2 position, float size, glm::vec3 color): m_text(text), m_position(position), m_size(size), m_color(color)
    {
        m_defaultShader = IEMPShader::Load(EMPTextConstants::textVertexFile, EMPTextConstants::textFragmentFile);
        glm::mat4 projection = glm::ortho(0.0f, EMPTextConstants::windowSize.x, 0.0f, EMPTextConstants::windowSize.y);
        m_defaultShader->UseShader();
        m_defaultShader->SetMatrix(EMPTextConstants::projection, projection);
        
        //TODO: Refactor move this code to buffer class.
        glGenVertexArrays(1, &m_VAO);
        glGenBuffers(1, &m_VBO);
        glBindVertexArray(m_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
    
    // MARK: - Public Methods
    void EMPText::SetText(std::string text)
    {
        m_text = text;
    }
    
    void EMPText::SetPosition(glm::vec2 position)
    {
        m_position = position;
    }

    void EMPText::Draw()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        m_defaultShader->UseShader();
        m_defaultShader->SetVec3(EMPTextConstants::textColor, m_color);
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(m_VAO);
        
        std::string::const_iterator charInterator;
        GLfloat x = m_position.x;
        GLfloat y = m_position.y;
        
        for (charInterator = m_text.begin(); charInterator != m_text.end(); charInterator++)
        {
            auto &application = EMPGameApp::GetInstance();
            
            if (application.GetFontManager() && application.GetFontManager()->GetCharacters().size() > 0)
            {
                EMPCharacter character = application.GetFontManager()->GetCharacters()[*charInterator];
                
                GLfloat positionX = x + character.bearing.x * m_size;
                GLfloat positionY = y - (character.size.y - character.bearing.y) * m_size;
                
                GLfloat width = character.size.x * m_size;
                GLfloat height = character.size.y * m_size;
                GLfloat vertices[6][4] =
                {
                    { positionX, positionY + height, 0.0, 0.0 },
                    { positionX, positionY, 0.0, 1.0 },
                    { positionX + width, positionY, 1.0, 1.0 },
                    
                    { positionX, positionY + height, 0.0, 0.0 },
                    { positionX + width, positionY, 1.0, 1.0 },
                    { positionX + width, positionY + height, 1.0, 0.0 }
                };
                
                //TODO: Refactor move this code to buffer class.
                glBindTexture(GL_TEXTURE_2D, character.texture->GetId());
                glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glDrawArrays(GL_TRIANGLES, 0, 6);
                
                x += (character.horizontalOffset >> 6) * m_size;
            }
        }
        glDisable(GL_BLEND);
    }

    void EMPText::Update(float deltaTime)
    {
        
    }
}
