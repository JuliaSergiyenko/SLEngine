#include "SLShaderSources_GL2.hpp"
#include <string>

// SLR_GL2
namespace SLR_GL2
{
	// vertex shader with position and color
	const char* cVSShaderSource_PositionColor = R"(

// attributes
attribute vec3 aPosition;
attribute vec4 aColor;

// uniforms
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;

// outputs
varying vec4 vColor;

// main
void main()
{
	gl_Position = uProjMat * uViewMat * uModelMat * vec4(aPosition, 1.0);
	vColor = aColor;
}

)";

	// fragment shader with position and color
	const char* cFSShaderSource_PositionColor = R"(

// inputs
varying vec4 vColor;

// main
void main()
{
    gl_FragColor = vColor;
}

)";
}
