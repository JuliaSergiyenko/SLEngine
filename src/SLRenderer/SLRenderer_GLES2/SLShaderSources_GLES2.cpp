#include "SLShaderSources_GLES2.hpp"
#include <string>

// SLR_GLES2
namespace SLR_GLES2
{
	// vertex // shader with position, color and tex coords
	const char* cVSShaderSource_PositionColorTexCoords = R"(

precision mediump float;

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

	// find position
	gl_Position = uProjMat * uViewMat * uModelMat * vec4(aPosition, 1.0);
}

)";

	// fragment // shader with position, color and tex coords
	const char* cFSShaderSource_PositionColorTexCoords = R"(

precision mediump float;

// inputs
varying vec4 vColor;
varying vec2 vTexCoord;

// textures
uniform sampler2D sBaseTexture;

// main
void main()
{
	gl_FragColor = texture2D(sBaseTexture, vTexCoord.xy) * vColor;
}

)";
}
