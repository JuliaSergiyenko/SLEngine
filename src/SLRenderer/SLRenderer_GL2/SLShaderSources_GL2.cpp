#include "SLShaderSources_GL2.hpp"
#include <string>

// SLR_GLES2
namespace SLR_GL2
{
	// vertex shader with position and color
	const char* cVSShaderSource_PositionColor = R"(

// attributes
attribute vec3 aPosition;
attribute vec4 aColor;
attribute vec2 aTexCoord;

// uniforms
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;

// outputs
varying vec4 vColor;
varying vec2 vTexCoord;

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

// inputs
varying vec4 vColor;
varying vec2 vTexCoord;

// textures
uniform sampler2D sBaseTexture;

// main
void main()
{
	gl_FragColor = texture2D(sBaseTexture, vTexCoord.xy) * vColor;
	//fragColor = vec4(vTexCoord, 0.0, 1.0) * vColor;
	//fragColor = vColor;
}

)";
}
