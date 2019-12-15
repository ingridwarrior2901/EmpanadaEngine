//
//  EMPWindow.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/20/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPWindow_hpp
#define EMPWindow_hpp

#include "EMPWindowFactory.h"

namespace EmpanadaEngine
{
    using IEMPWindowPTR = std::shared_ptr<IEMPWindow>;
    
    class EMPWindowManager
    {
    public:
        //------------------------------------------------------------/
        EMPWindowManager(const EMPWindowConfiguration& windowsInfo);
        ~EMPWindowManager() {}
        //------------------------------------------------------------/
        EMPWindowConfiguration const &GetWindowInfo()  { return m_windowInfo; }
        IEMPWindowPTR GetWindowInterface() { return m_interface; }
        //------------------------------------------------------------/
        
    private:
        IEMPWindowPTR m_interface;
        EMPWindowConfiguration m_windowInfo;
    };
    
}

#endif /* EMPWindow_hpp */
