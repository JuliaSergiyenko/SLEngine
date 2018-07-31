#include "SLShaderSources_GL3.hpp"
#include <string>

// SLR_GL3
namespace SLR_GL3
{
	// vertex shader with position and color
	const char* cVSShaderSource_PositionColor = R"(

#version 330 core

// attributes
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 4) in vec2 aTexCoord;

// uniforms
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;

// outputs
out vec4 vColor;
out vec2 vTexCoord;

// main
void main()
{
	// copy in to out
	vTexCoord = aTexCoord;
	vColor = aColor;
	gl_Position = uProjMat * uViewMat * uModelMat * vec4(aPosition, 1.0);
}

)";

	// fragment shader with position and color
	const char* cFSShaderSource_PositionColor = R"(

#version 330 core

// inputs
in vec4 vColor;
in vec2 vTexCoord;

// textures
uniform sampler2D sBaseTexture;

// outputs
out vec4 fragColor;

// main
void main()
{
	fragColor = texture2D(sBaseTexture, vTexCoord.xy) * vColor;
	//fragColor = vec4(vTexCoord, 0.0, 1.0) * vColor;
	//fragColor = vColor;
}

)";
}
