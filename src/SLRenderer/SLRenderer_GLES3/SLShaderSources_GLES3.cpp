#include "SLShaderSources_GLES3.hpp"
#include <string>

// SLR_GLES3
namespace SLR_GLES3
{
	// vertex shader with position and color
	const char* cVSShaderSource_PositionColor = R"(

#version 300 es
precision mediump float;

// attributes
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;

// uniforms
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;

// outputs
out vec4 vColor;

// main
void main()
{
	gl_Position = uProjMat * uViewMat * uModelMat * vec4(aPosition, 1.0);
	vColor = aColor;
}

)";

	// fragment shader with position and color
	const char* cFSShaderSource_PositionColor = R"(

#version 300 es
precision mediump float;

// inputs
in vec4 vColor;

// outputs
out vec4 FragColor;

// main
void main()
{
    FragColor = vColor;
}

)";
}
