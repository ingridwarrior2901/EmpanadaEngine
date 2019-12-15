//
//  EMPWindowInterface.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/19/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPWindowInterface_hpp
#define EMPWindowInterface_hpp

#include "EMPWindowConfiguration.h"
#include <iostream>

namespace EmpanadaEngine
{
	class IEMPWindow
	{
	public:
		//------------------------------------------------------------/
		virtual ~IEMPWindow() {}
		//------------------------------------------------------------/
		virtual bool Initialize() = 0;
        virtual void ResizeViewport(glm::vec2 windowSize) = 0;
        virtual void SetBackgroundColor(glm::vec4 color) = 0;
        virtual void SetViewPort(glm::vec4 viewPort) = 0;
		virtual void Terminate() = 0;
		virtual void StartFrame() = 0;
		virtual void EndFrame() = 0;
		virtual void Update() = 0;
		virtual void Close() = 0;
		//------------------------------------------------------------/
		virtual glm::vec2 GetWindowSize() const = 0;
        virtual glm::vec4 GetViewPort() const = 0;
		virtual void* GetWindow() const = 0;
	};
}

#endif /* EMPWindowInterface_hpp */
