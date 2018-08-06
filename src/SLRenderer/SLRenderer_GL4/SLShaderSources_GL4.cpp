#include "SLShaderSources_GL4.hpp"
#include <string>

// SLR_GL4
namespace SLR_GL4
{
	// vertex // shader with position, normal, color and texCoords
	const char* cVSShaderSource_PositionColorNormalTexCoords = R"(

#version 430 core

// attributes
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec3 aNormal;
layout (location = 4) in vec2 aTexCoord;

// uniforms
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;

// outputs
layout (location = 1) out vec4 vColor;
layout (location = 2) out vec3 vNormal;
layout (location = 4) out vec2 vTexCoord;

// main
void main()
{
	// copy in to out
	vColor = aColor;
	vNormal = aNormal;
	vTexCoord = aTexCoord;

	// find position
	gl_Position = uProjMat * uViewMat * uModelMat * vec4(aPosition, 1.0);
}

)";

	// fragment // shader with position, normal, color and texCoords
	const char* cFSShaderSource_PositionColorNormalTexCoords = R"(

#version 430 core

// inputs
layout (location = 1) in vec4 vColor;
layout (location = 2) in vec3 vNormal;
layout (location = 4) in vec2 vTexCoord;

// textures
layout (binding = 0) uniform sampler2D sBaseTexture;

// outputs
layout (location = 0) out vec4 fragColor;

// main
void main()
{
	//fragColor = texture2D(sBaseTexture, vTexCoord.xy) * vColor;
	//fragColor = vec4(vTexCoord.xy, 1.0, 1.0);
	fragColor = vec4(vNormal, 1.0);
}

)";
}
