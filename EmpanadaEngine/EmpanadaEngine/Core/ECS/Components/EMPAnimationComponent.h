//
//  EMPAnimationComponent.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/6/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPAnimationComponent_hpp
#define EMPAnimationComponent_hpp

#include "IEMPComponent.h"

#include "../../Shaders/EMPVertex.h"
#include "../../Render/IEMPTexture.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace EmpanadaEngine
{
    struct EMPAnimation
    {
        IEMPTexturePTR texture;
        int horizontalFrames;
        int verticalFrames;
        int fps;
        int totalMaxFrames;
        float animationPerFrame;
        std::vector<std::vector<EMPVertex>> uvAnimationVertex;
    };
    
    class EMPAnimationComponent: public IEMPComponent
    {
    public:
        //------------------------------------------------------------/
        EMPAnimationComponent(IEMPEntity *owner);
        //------------------------------------------------------------/
        void AddAnimation(IEMPTexturePTR texture, const std::string& name, int horizontalFrames, int verticalFrames, int fps, std::vector<std::vector<EMPVertex>> uvAnimationVertex);
        void RemoveAnimation(const std::string& name);
        //------------------------------------------------------------/
        void PlayAnimation();
        void PlayAnimation(const std::string& name);
        void StopAnimation();
        //------------------------------------------------------------/
        EMPAnimation GetAnimation(const std::string& name);
        void SetFPS(const std::string& name, int fps);
        void SetLooping(bool looping);
        //------------------------------------------------------------/
        bool IsAnimationPlaying() const { return m_isAnimationPlaying; }
        //------------------------------------------------------------/
        int GetCurrentFrame() const { return m_currentFrame; }
        int AnimationSize() const { return m_animationMap.size(); }
        //------------------------------------------------------------/
        std::vector<EMPVertex> GetCurrentUVVertexAnimation();
        IEMPTexturePTR GetCurrentTextureAnimation();
        //------------------------------------------------------------/
        virtual void Update(float deltaTime);
        //------------------------------------------------------------/
    private:
        //------------------------------------------------------------/
        std::string m_currentAnimation;
        std::map<std::string, EMPAnimation> m_animationMap;
        float m_elipseTime;
        //------------------------------------------------------------/
        int m_currentFrame;
        //------------------------------------------------------------/
        bool m_isAnimationPlaying;
        bool m_looping;
    };

    using EMPAnimationComponentPTR = std::shared_ptr<EMPAnimationComponent>;
}

#endif /* EMPAnimationComponent_hpp */
