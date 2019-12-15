//
//  EMPSinglenton.h
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/25/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPSinglenton_h
#define EMPSinglenton_h

namespace EmpanadaEngine
{
    template <typename T>
    class EMPSinglenton
    {
    public:
        
        EMPSinglenton()
        {
            if (!m_instance)
            {
                m_instance = static_cast<T*>(this);
            }
        }
        
        virtual ~EMPSinglenton()
        {
            m_instance = nullptr;
        }

        static T & GetInstance()
        {
            return *m_instance;
        }

        static void InitInstance()
        {
            new T();
        }
        
        static void RemoveInstance()
        {
            delete m_instance;
        }

    private:
        static T * m_instance;
    };

    template <typename T> T * EMPSinglenton<T>::m_instance = nullptr;
}



#endif /* EMPSinglenton_h */
