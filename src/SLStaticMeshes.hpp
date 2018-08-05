#pragma once

// simple quad positions
static const float SLQuadBuffer_Position[] =
{
	-1.0f, -1.0f, +0.0f,
	+1.0f, -1.0f, +0.0f,
	-1.0f, +1.0f, +0.0f,
	+1.0f, +1.0f, +0.0f,
};

// simple quad colors
static const float SLQuadBuffer_Colors[] =
{
	+1.0f, +1.0f, +1.0f, +1.0f,
	+1.0f, +1.0f, +1.0f, +1.0f,
	+1.0f, +1.0f, +1.0f, +1.0f,
	+1.0f, +1.0f, +1.0f, +1.0f,
};

// simple quad tex coords
static const float SLQuadBuffer_TexCoords[] =
{
	+0.0f, +0.0f,
	+1.0f, +0.0f,
	+0.0f, +1.0f,
	+1.0f, +1.0f,
};

// static meshes functions
void SLStaticMeshesInit();
void SLStaticMeshesShutDown();