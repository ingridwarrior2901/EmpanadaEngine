//
//  EMPRenderManager.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/28/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPRenderManager_hpp
#define EMPRenderManager_hpp

#include "../Game/EMPSinglenton.h"

namespace EmpanadaEngine
{
    class EMPRenderManager: public EMPSinglenton<EMPRenderManager>
    {
    public:
        //------------------------------------------------------------/
        EMPRenderManager() {}
        ~EMPRenderManager() {}
        //------------------------------------------------------------/
        void Draw() {}
        //------------------------------------------------------------/
    };
}

#endif /* EMPRenderManager_hpp */
