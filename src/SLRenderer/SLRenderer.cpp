#include "SLRenderer.hpp"
#include "SLRenderer_GL2/SLRenderer_GL2.hpp"
#include "SLRenderer_GLES2/SLRenderer_GLES2.hpp"

// CreateRenderer
ISLRenderer* SLRendererFabric::CreateRenderer(SLRendererType rendererType)
{
	if (rendererType == SL_RENDERER_TYPE_GL2)
		return new SLR_GL2::SLRenderer_GL2();
	else if (rendererType == SL_RENDERER_TYPE_GLES2)
		return new SLR_GLES2::SLRenderer_GLES2();
	else if (rendererType == SL_RENDERER_TYPE_VULKAN)
		return nullptr;
	else if (rendererType == SL_RENDERER_TYPE_D3D9)
		return nullptr;
	return nullptr;
}