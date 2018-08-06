#include "SLShaderSources_GLES3.hpp"
#include <string>

// SLR_GLES3
namespace SLR_GLES3
{
	// vertex // shader with position, color and tex coords
	const char* cVSShaderSource_PositionColorNormalTexCoords = R"(

#version 300 es
precision mediump float;

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
out vec4 vColor;
out vec3 vNormal;
out vec2 vTexCoord;

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

	// fragment // shader with position, color and tex coords
	const char* cFSShaderSource_PositionColorNormalTexCoords = R"(
#version 300 es
precision mediump float;

// inputs
in vec4 vColor;
in vec3 vNormal;
in vec2 vTexCoord;

// textures
uniform sampler2D sBaseTexture;

// outputs
out vec4 fragColor;

// main
void main()
{
	//fragColor = texture(sBaseTexture, vTexCoord.xy) * vColor;
	//fragColor = vec4(vTexCoord.xy, 1.0, 1.0);
	fragColor = vec4(vNormal, 1.0);
}

)";
}
