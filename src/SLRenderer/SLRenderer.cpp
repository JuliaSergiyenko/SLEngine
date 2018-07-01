#include "SLRenderer.hpp"

#if defined(SL_RENDERER_GL2)
#include "SLRenderer_GL2/SLRenderer_GL2.hpp"
#endif
#if defined(SL_RENDERER_GL3)
#include "SLRenderer_GL3/SLRenderer_GL3.hpp"
#endif
#if defined(SL_RENDERER_GLES2)
#include "SLRenderer_GLES2/SLRenderer_GLES2.hpp"
#endif
#if !defined(SL_RENDERER_GL2) && !defined(SL_RENDERER_GL3) && !defined(SL_RENDERER_GLES2)
#error "Plese, define rendering type (SL_RENDERER_GL2, or SL_RENDERER_GL3, or SL_RENDERER_GLES2)"
#endif

// CreateRenderer
ISLRenderer* SLRendererFabric::CreateRenderer(SLRendererType rendererType)
{
#ifdef SL_RENDERER_GL2
	if (rendererType == SL_RENDERER_TYPE_GL2)
		return new SLR_GL2::SLRenderer_GL2();
#endif
#ifdef SL_RENDERER_GL3
	if (rendererType == SL_RENDERER_TYPE_GL3)
		return new SLR_GL3::SLRenderer_GL3();
#endif
#if defined(SL_RENDERER_GLES2)
	if (rendererType == SL_RENDERER_TYPE_GLES2)
		return new SLR_GLES2::SLRenderer_GLES2();
#endif
	return nullptr;
}