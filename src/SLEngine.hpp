#pragma once

#include "SLStaticMeshes.hpp"
#include "SLRenderer/SLRenderer.hpp"
#include "SLProgressor/SLProgressor.hpp"

// SLEngine - where is all begining
class SLEngine
{
private:
	// main systems
	ISLRenderer* mRenderer = nullptr;
	ISLProgressor* mProgressor = nullptr;
public:
	// constructor and destructor
	SLEngine();
	~SLEngine();

	// engine getters
	ISLRenderer* GetRenderer();
	ISLProgressor* GetProgressor();
};