//------------------------------------------------------------------------------
//  ogltransformdevice.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/ogltransformdevice.h"
#include "coregraphics/shaderserver.h"
#include "coregraphics/displaydevice.h"
#include "coregraphics/renderdevice.h"
#include "coregraphics/shadersemantics.h"

namespace OGL
{
    __ImplementClass(OGL::OGLTransformDevice, 'GLTD', Base::TransformDeviceBase);
    __ImplementSingleton(OGL::OGLTransformDevice);
    
using namespace Util;
using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
 */
OGLTransformDevice::OGLTransformDevice() :
    mvpSemantic(NEBULA3_SEMANTIC_MODELVIEWPROJECTION),
    modelSemantic(NEBULA3_SEMANTIC_MODEL),
    modelViewSemantic(NEBULA3_SEMANTIC_MODELVIEW),
    viewSemantic(NEBULA3_SEMANTIC_VIEW),
    invViewSemantic(NEBULA3_SEMANTIC_INVVIEW),
    invModelViewSemantic(NEBULA3_SEMANTIC_INVMODELVIEW),
    viewProjSemantic(NEBULA3_SEMANTIC_VIEWPROJECTION),
    eyePosSemantic(NEBULA3_SEMANTIC_EYEPOS),
    projectionSemantic(NEBULA3_SEMANTIC_PROJECTION),
    invProjectionSemantic(NEBULA3_SEMANTIC_INVPROJECTION)
{
    // empty
}

//------------------------------------------------------------------------------
/**
 */
OGLTransformDevice::~OGLTransformDevice()
{
    // empty
}

//------------------------------------------------------------------------------
/**
 * Called by internal view to update shader with camera transforms
 */
void
OGLTransformDevice::ApplyViewSettings()
{
    /// shared shader variables
    Ptr<CoreGraphics::ShaderVariable> shdEyePos;
    Ptr<CoreGraphics::ShaderVariable> viewMatrix;
    Ptr<CoreGraphics::ShaderVariable> invViewMatrix;
    Ptr<CoreGraphics::ShaderVariable> projectionMatrix;
    Ptr<CoreGraphics::ShaderVariable> invProjectionMatrix;
    Ptr<CoreGraphics::ShaderVariable> focalLengthShaderVar;
    
    const Ptr<ShaderInstance> shaderInst = RenderDevice::Instance()->CurrentShaderInstance();
    
    //shdEyePos = shaderInst->GetVariableBySemantic(this->eyePosSemantic);
    viewMatrix = shaderInst->GetVariableBySemantic(this->viewSemantic);
    //invViewMatrix = shaderInst->GetVariableBySemantic(this->invViewSemantic);
    projectionMatrix = shaderInst->GetVariableBySemantic(this->projectionSemantic);
    //invProjectionMatrix = shaderInst->GetVariableBySemantic(this->invProjectionSemantic);
    //focalLengthShaderVar = shaderInst->GetVariableBySemantic(NEBULA3_SEMANTIC_FOCALLENGTH);
    
    // update shared shader variable eye pos from current view matrix
    //shdEyePos->SetFloat4(this->GetInvViewTransform().getrow3());
    
    // apply view matrix to shader
    viewMatrix->SetMatrix(this->GetViewTransform());
    //invViewMatrix->SetMatrix(this->GetInvViewTransform());
    
    // apply inv projection
    //invProjectionMatrix->SetMatrix(this->GetInvProjTransform());
    
    // apply projection matrix to shader
    projectionMatrix->SetMatrix(this->GetProjTransform());
    
    // apply focal length
    //focalLengthShaderVar->SetFloat4(Math::float4(this->GetFocalLength().x(), this->GetFocalLength().y(), 0, 0));
}

//------------------------------------------------------------------------------
/**
 */
void
OGLTransformDevice::ApplyModelTransforms(const Ptr<ShaderInstance>& shdInst)
{
    // apply ModelViewProjection
    //n_assert(shdInst->HasVariableBySemantic(this->mvpSemantic));
    //const Ptr<ShaderVariable>& modelViewProjMatrix = shdInst->GetVariableBySemantic(mvpSemantic);
    //modelViewProjMatrix->SetMatrix(this->GetModelViewProjTransform());
    
    // apply optional ViewProjection
    if (shdInst->HasVariableBySemantic(this->viewProjSemantic))
    {
        const Ptr<ShaderVariable>& viewProj = shdInst->GetVariableBySemantic(this->viewProjSemantic);
        viewProj->SetMatrix(this->GetViewProjTransform());
    }
    
    // apply optional Model matrix to shader
    if (shdInst->HasVariableBySemantic(this->modelSemantic))
    {
        const Ptr<ShaderVariable>& model = shdInst->GetVariableBySemantic(this->modelSemantic);
        model->SetMatrix(this->GetModelTransform());
    }
    
    // apply optional ModelView matrix to shader
    if (shdInst->HasVariableBySemantic(this->modelViewSemantic))
    {
        const Ptr<ShaderVariable>& modelView = shdInst->GetVariableBySemantic(this->modelViewSemantic);
        modelView->SetMatrix(this->GetModelViewTransform());
    }
    
    // apply optional InvModelView matrix to shader
    if (shdInst->HasVariableBySemantic(this->invModelViewSemantic))
    {
        const Ptr<ShaderVariable>& invModelView = shdInst->GetVariableBySemantic(this->invModelViewSemantic);
        invModelView->SetMatrix(this->GetInvModelViewTransform());
    } 
    
    // apply optional inverse projection matrix to shader
    if (shdInst->HasVariableBySemantic(this->invProjectionSemantic))
    {
        const Ptr<ShaderVariable>& invProj = shdInst->GetVariableBySemantic(this->invProjectionSemantic);
        invProj->SetMatrix(this->GetInvProjTransform());
    }
}
    
} // namespace OGL
