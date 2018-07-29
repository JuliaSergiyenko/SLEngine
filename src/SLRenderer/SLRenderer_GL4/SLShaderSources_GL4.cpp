#include "SLShaderSources_GL4.hpp"
#include <string>

// SLR_GL4
namespace SLR_GL4
{
	// vertex shader with position and color
	const char* cVSShaderSource_PositionColor = R"(

#version 330 core

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

#version 330 core

// inputs
in vec4 vColor;

// main
void main()
{
    gl_FragColor = vColor;
}

)";
}
