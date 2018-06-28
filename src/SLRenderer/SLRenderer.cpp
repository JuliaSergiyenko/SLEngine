#include "SLRenderer.hpp"

// CreateRenderer
ISLRenderer* SLRendererFabric::CreateRenderer(SLRendererType rendererType)
{
	if (rendererType == SL_RENDERER_TYPE_GL2)
		return nullptr;
	else if (rendererType == SL_RENDERER_TYPE_GLES2)
		return nullptr;
	else if (rendererType == SL_RENDERER_TYPE_VULKAN)
		return nullptr;
	else if (rendererType == SL_RENDERER_TYPE_D3D9)
		return nullptr;
	return nullptr;
}