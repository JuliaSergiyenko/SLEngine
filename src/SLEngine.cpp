#include "SLEngine.hpp"

// SLEngine
SLEngine::SLEngine()
{
	// create main objects
	mRenderer = CreateSLRenderer();
	mProgressor = CreateSLProgressor();
};

// ~SLEngine
SLEngine::~SLEngine()
{
	// destroy main objects
	DestroySLRenderer(mRenderer);
	DestroySLProgressor(mProgressor);
};
