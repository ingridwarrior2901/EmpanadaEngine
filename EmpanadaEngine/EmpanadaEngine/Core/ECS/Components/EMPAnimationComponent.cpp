//
//  EMPAnimationComponent.cpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/6/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#include "EMPAnimationComponent.h"
#include "../Entities/IEMPEntity.h"

namespace EmpanadaEngine
{
    EMPAnimationComponent::EMPAnimationComponent(IEMPEntity *owner): IEMPComponent(owner)
    {
        m_currentFrame = 0;
        m_elipseTime = 0;
        m_isAnimationPlaying = false;
        m_looping = false;
    }

    void EMPAnimationComponent::Update(float deltaTime)
    {
        if (m_isAnimationPlaying)
        {
            EMPAnimation animation = m_animationMap[m_currentAnimation];
            m_elipseTime += deltaTime;
            
            if (animation.fps > 0)
            {
                if (m_elipseTime >= animation.animationPerFrame)
                {
                    m_elipseTime = 0;
                    m_currentFrame++;
                    
                    if(m_currentFrame >= animation.totalMaxFrames)
                    {
                        m_currentFrame = 0;
                        m_isAnimationPlaying = m_looping;
                    }
                }
            }
        }
    }

    void EMPAnimationComponent::AddAnimation(IEMPTexturePTR texture, const std::string& name, int horizontalFrames, int verticalFrames, int fps, std::vector<std::vector<EMPVertex>> uvAnimationVertex)
    {
        m_currentAnimation = name;
        m_animationMap[name].texture = texture;
        m_animationMap[name].horizontalFrames = horizontalFrames;
        m_animationMap[name].verticalFrames = verticalFrames;
        m_animationMap[name].fps = fps;
        m_animationMap[name].uvAnimationVertex = uvAnimationVertex;
        m_animationMap[name].totalMaxFrames = horizontalFrames * verticalFrames;
        m_animationMap[name].animationPerFrame =  1.0f / fps;
    }

    void EMPAnimationComponent::RemoveAnimation(const std::string& name)
    {
        
    }

    void EMPAnimationComponent::PlayAnimation()
    {
        m_isAnimationPlaying = true;
    }

    void EMPAnimationComponent::PlayAnimation(const std::string& name)
    {
        m_isAnimationPlaying = true;
        m_currentAnimation = name;
    }

    void EMPAnimationComponent::StopAnimation()
    {
        m_isAnimationPlaying = false;
        m_currentFrame = 0;
        m_elipseTime = 0;
    }

    EMPAnimation EMPAnimationComponent::GetAnimation(const std::string& name)
    {
        return m_animationMap[name];
    }
    
    void EMPAnimationComponent::SetFPS(const std::string& name, int fps)
    {
        m_animationMap[name].fps = fps;
    }
    
    void EMPAnimationComponent::SetLooping(bool looping)
    {
        m_looping = looping;
    }

    std::vector<EMPVertex> EMPAnimationComponent::GetCurrentUVVertexAnimation()
    {
        return GetAnimation(m_currentAnimation).uvAnimationVertex.at(m_currentFrame);
    }

    IEMPTexturePTR EMPAnimationComponent::GetCurrentTextureAnimation()
    {
        return GetAnimation(m_currentAnimation).texture;
    }
}
