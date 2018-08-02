#include "SLShaderSources_GL4.hpp"
#include <string>

// SLR_GL4
namespace SLR_GL4
{
	// vertex // shader with position, color and tex coords
	const char* cVSShaderSource_PositionColorTexCoords = R"(

#version 430 core

// attributes
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 4) in vec2 aTexCoord;

// uniforms
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;

// outputs
layout (location = 1) out vec4 vColor;
layout (location = 4) out vec2 vTexCoord;

// main
void main()
{
	// copy in to out
	vTexCoord = aTexCoord;
	vColor = aColor;

	// find position
	gl_Position = uProjMat * uViewMat * uModelMat * vec4(aPosition, 1.0);
}

)";

	// fragment // shader with position, color and tex coords
	const char* cFSShaderSource_PositionColorTexCoords = R"(

#version 430 core

// inputs
layout (location = 1) in vec4 vColor;
layout (location = 4) in vec2 vTexCoord;

// textures
layout (binding = 0) uniform sampler2D sBaseTexture;

// outputs
layout (location = 0) out vec4 fragColor;

// main
void main()
{
	fragColor = texture2D(sBaseTexture, vTexCoord.xy) * vColor;
}

)";
}
