//
//  EmpanadaEngine.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/22/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EmpanadaEngine_h
#define EmpanadaEngine_h

#include <iostream>
#include <vector>
#include "../Lib/Common/glm/glm/glm.hpp"

namespace EmpanadaEngine
{
    #define EMPBindFunction(fn) std::bind(&fn, this)

    template<typename T>
    using EMPUnique = std::unique_ptr<T>;
    
    template<typename T, typename ... Args>
    constexpr EMPUnique<T> NewUnique(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using EMPRef = std::shared_ptr<T>;
    
    template<typename T, typename ... Args>
    constexpr EMPRef<T> NewRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template< typename T>
    static bool ValidIndex(size_t index, std::vector <T> vector)
    {
        return index > 0 && index < vector.size();
    }

    static glm::vec3 pixelToNDC(glm::vec3 pixel, glm::vec4 viewPort)
    {
        glm::vec3 ndc;
        ndc.x = (((2.0 * pixel.x) - (2.0 * 0)) / viewPort.z) - 1.0;
        ndc.y = (((2.0 * pixel.y) - (2.0 * 0)) / viewPort.w) - 1.0;
        ndc.z = 0.0f;
        return ndc;
    }
}

#endif /* EmpanadaEngine_h */
