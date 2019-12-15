//
//  EMPMesh.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 12/1/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPMesh_hpp
#define EMPMesh_hpp

#include "EMPMaterial.h"
#include "../../Render/IEMPBuffer.h"

namespace EmpanadaEngine
{
    struct EMPBufferContainer
    {
        IEMPBufferPTR buffer;
        EMPMaterialPTR material;
    };

    class EMPMesh
    {
    public:
        //------------------------------------------------------------/
        EMPMesh();
        ~EMPMesh();
        //------------------------------------------------------------/
        void Add(const IEMPBufferPTR& buffer, const EMPMaterialPTR& material);
        size_t GetNumBuffers() const;
        IEMPBufferPTR GetBuffer(size_t index) const;
        EMPMaterialPTR GetMaterial(size_t index) const;
        //------------------------------------------------------------/
        void Draw(glm::mat4 modelMatrix);
        
    private:
        std::vector <EMPBufferContainer> m_bufferContainerMap;
    };

    using EMPMeshPTR = std::shared_ptr<EMPMesh>;
}


#endif /* EMPMesh_hpp */
