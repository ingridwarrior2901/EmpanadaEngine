//
//  EMPModel.hpp
//  EmpanadaEngine
//
//  Created by Ingrid Guerrero on 11/30/19.
//  Copyright © 2019 Ingrid Guerrero. All rights reserved.
//

#ifndef EMPModel_hpp
#define EMPModel_hpp

#include "EMPGameObject.h"
#include "EMPMesh.h"

namespace EmpanadaEngine
{
    enum EMPDrawMode
    {
        TRIANGLE,
        RECTANGLE
    };

    class EMPModel: public EMPGameObject
    {
    public:
        //------------------------------------------------------------/
        EMPModel(const EMPMeshPTR& mesh);
        EMPModel();
        //------------------------------------------------------------/
        void SetAngle(float angle);
        //------------------------------------------------------------/
        static EMPRef<EMPModel> Load(EMPDrawMode drawMode, IEMPShaderPTR defaultShader, glm::vec3 color);
        static EMPRef<EMPModel> Load(EMPDrawMode drawMode, IEMPShaderPTR defaultShader, IEMPTexturePTR texture);
        //------------------------------------------------------------/
        virtual void Draw() override;
        virtual void Update(float deltaTime) override;
    
    protected:
        //------------------------------------------------------------/
        void SetMesh(const EMPMeshPTR &mesh);
        //------------------------------------------------------------/
        static EMPMeshPTR CreateMaterial(std::vector<EMPVertex> vertexs, std::vector<GLuint> indexs, IEMPShaderPTR defaultShader, IEMPTexturePTR texture);
        std::vector<EMPVertex> GenerateVertices(glm::vec2 position, glm::vec2 size, float u0, float v0, float u1, float v1);
        //------------------------------------------------------------/
    private:
        //------------------------------------------------------------/
        static EMPRef<EMPModel> DrawModel(EMPDrawMode drawMode, IEMPShaderPTR defaultShader, glm::vec3 color, IEMPTexturePTR texture = nullptr);
        static EMPRef<EMPModel> DrawTriangle(IEMPShaderPTR defaultShader, glm::vec3 color, IEMPTexturePTR texture);
        static EMPRef<EMPModel> DrawRectangle(IEMPShaderPTR defaultShader, glm::vec3 color, IEMPTexturePTR texture);
        //------------------------------------------------------------/
        EMPMeshPTR m_mesh;
        glm::mat4 m_model;
        float m_angle;
    };

    using EMPModelPTR = std::shared_ptr<EMPModel>;
}

#endif /* EMPModel_hpp */
