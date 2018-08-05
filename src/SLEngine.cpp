#include "SLEngine.hpp"

// SLEngine
SLEngine::SLEngine()
{
	// create main objects
	mRenderer = CreateSLRenderer();
	mProgressor = CreateSLProgressor();
	SLStaticMeshesInit();
};

// ~SLEngine
SLEngine::~SLEngine()
{
	// destroy main objects
	SLStaticMeshesShutDown();
	DestroySLRenderer(mRenderer);
	DestroySLProgressor(mProgressor);
};

// engine getters
ISLRenderer* SLEngine::GetRenderer()
{
	return mRenderer;
}

// GetProgressor
ISLProgressor* SLEngine::GetProgressor()
{
	return mProgressor;
}
