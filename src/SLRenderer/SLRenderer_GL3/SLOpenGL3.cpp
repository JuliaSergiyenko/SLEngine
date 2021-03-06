#include "SLOpenGL3.hpp"

// get opengl procedure address
#ifndef GetProcAddress
#if defined(_WIN32)
#define GetProcAddress(x) wglGetProcAddress(x)
#elif defined(__linux__)
#include <GL/glx.h>
#define GetProcAddress(x) glxGetProcAddress((const GLubyte *)x);
#endif
#endif

// SLR_GL3
namespace SLR_GL3
{
	/*
	// GL_VERSION_1_1
	PFNGLDRAWARRAYSPROC        glDrawArrays = nullptr;
	PFNGLDRAWELEMENTSPROC      glDrawElements = nullptr;
	PFNGLGETPOINTERVPROC       glGetPointerv = nullptr;
	PFNGLPOLYGONOFFSETPROC     glPolygonOffset = nullptr;
	PFNGLCOPYTEXIMAGE1DPROC    glCopyTexImage1D = nullptr;
	PFNGLCOPYTEXIMAGE2DPROC    glCopyTexImage2D = nullptr;
	PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = nullptr;
	PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = nullptr;
	PFNGLTEXSUBIMAGE1DPROC     glTexSubImage1D = nullptr;
	PFNGLTEXSUBIMAGE2DPROC     glTexSubImage2D = nullptr;
	PFNGLBINDTEXTUREPROC       glBindTexture = nullptr;
	PFNGLDELETETEXTURESPROC    glDeleteTextures = nullptr;
	PFNGLGENTEXTURESPROC       glGenTextures = nullptr;
	PFNGLISTEXTUREPROC         glIsTexture = nullptr;
	*/

	// GL_VERSION_1_2
	PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
	PFNGLTEXIMAGE3DPROC        glTexImage3D = nullptr;
	PFNGLTEXSUBIMAGE3DPROC     glTexSubImage3D = nullptr;
	PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;

	// GL_VERSION_1_3
	PFNGLACTIVETEXTUREPROC           glActiveTexture = nullptr;
	PFNGLSAMPLECOVERAGEPROC          glSampleCoverage = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC    glCompressedTexImage3D = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC    glCompressedTexImage2D = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE1DPROC    glCompressedTexImage1D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
	PFNGLGETCOMPRESSEDTEXIMAGEPROC   glGetCompressedTexImage = nullptr;

	// GL_VERSION_1_4
	PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
	PFNGLMULTIDRAWARRAYSPROC   glMultiDrawArrays = nullptr;
	PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
	PFNGLPOINTPARAMETERFPROC   glPointParameterf = nullptr;
	PFNGLPOINTPARAMETERFVPROC  glPointParameterfv = nullptr;
	PFNGLPOINTPARAMETERIPROC   glPointParameteri = nullptr;
	PFNGLPOINTPARAMETERIVPROC  glPointParameteriv = nullptr;
	PFNGLBLENDCOLORPROC        glBlendColor = nullptr;
	PFNGLBLENDEQUATIONPROC     glBlendEquation = nullptr;

	// GL_VERSION_1_5
	PFNGLGENQUERIESPROC           glGenQueries = nullptr;
	PFNGLDELETEQUERIESPROC        glDeleteQueries = nullptr;
	PFNGLISQUERYPROC              glIsQuery = nullptr;
	PFNGLBEGINQUERYPROC           glBeginQuery = nullptr;
	PFNGLENDQUERYPROC             glEndQuery = nullptr;
	PFNGLGETQUERYIVPROC           glGetQueryiv = nullptr;
	PFNGLGETQUERYOBJECTIVPROC     glGetQueryObjectiv = nullptr;
	PFNGLGETQUERYOBJECTUIVPROC    glGetQueryObjectuiv = nullptr;
	PFNGLBINDBUFFERPROC           glBindBuffer = nullptr;
	PFNGLDELETEBUFFERSPROC        glDeleteBuffers = nullptr;
	PFNGLGENBUFFERSPROC           glGenBuffers = nullptr;
	PFNGLISBUFFERPROC             glIsBuffer = nullptr;
	PFNGLBUFFERDATAPROC           glBufferData = nullptr;
	PFNGLBUFFERSUBDATAPROC        glBufferSubData = nullptr;
	PFNGLGETBUFFERSUBDATAPROC     glGetBufferSubData = nullptr;
	PFNGLMAPBUFFERPROC            glMapBuffer = nullptr;
	PFNGLUNMAPBUFFERPROC          glUnmapBuffer = nullptr;
	PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
	PFNGLGETBUFFERPOINTERVPROC    glGetBufferPointerv = nullptr;

	// GL_VERSION_2_0
	PFNGLBLENDEQUATIONSEPARATEPROC    glBlendEquationSeparate = nullptr;
	PFNGLDRAWBUFFERSPROC              glDrawBuffers = nullptr;
	PFNGLSTENCILOPSEPARATEPROC        glStencilOpSeparate = nullptr;
	PFNGLSTENCILFUNCSEPARATEPROC      glStencilFuncSeparate = nullptr;
	PFNGLSTENCILMASKSEPARATEPROC      glStencilMaskSeparate = nullptr;
	PFNGLATTACHSHADERPROC             glAttachShader = nullptr;
	PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation = nullptr;
	PFNGLCOMPILESHADERPROC            glCompileShader = nullptr;
	PFNGLCREATEPROGRAMPROC            glCreateProgram = nullptr;
	PFNGLCREATESHADERPROC             glCreateShader = nullptr;
	PFNGLDELETEPROGRAMPROC            glDeleteProgram = nullptr;
	PFNGLDELETESHADERPROC             glDeleteShader = nullptr;
	PFNGLDETACHSHADERPROC             glDetachShader = nullptr;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
	PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray = nullptr;
	PFNGLGETACTIVEATTRIBPROC          glGetActiveAttrib = nullptr;
	PFNGLGETACTIVEUNIFORMPROC         glGetActiveUniform = nullptr;
	PFNGLGETATTACHEDSHADERSPROC       glGetAttachedShaders = nullptr;
	PFNGLGETATTRIBLOCATIONPROC        glGetAttribLocation = nullptr;
	PFNGLGETPROGRAMIVPROC             glGetProgramiv = nullptr;
	PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog = nullptr;
	PFNGLGETSHADERIVPROC              glGetShaderiv = nullptr;
	PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog = nullptr;
	PFNGLGETSHADERSOURCEPROC          glGetShaderSource = nullptr;
	PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation = nullptr;
	PFNGLGETUNIFORMFVPROC             glGetUniformfv = nullptr;
	PFNGLGETUNIFORMIVPROC             glGetUniformiv = nullptr;
	PFNGLGETVERTEXATTRIBDVPROC        glGetVertexAttribdv = nullptr;
	PFNGLGETVERTEXATTRIBFVPROC        glGetVertexAttribfv = nullptr;
	PFNGLGETVERTEXATTRIBIVPROC        glGetVertexAttribiv = nullptr;
	PFNGLGETVERTEXATTRIBPOINTERVPROC  glGetVertexAttribPointerv = nullptr;
	PFNGLISPROGRAMPROC                glIsProgram = nullptr;
	PFNGLISSHADERPROC                 glIsShader = nullptr;
	PFNGLLINKPROGRAMPROC              glLinkProgram = nullptr;
	PFNGLSHADERSOURCEPROC             glShaderSource = nullptr;
	PFNGLUSEPROGRAMPROC               glUseProgram = nullptr;
	PFNGLUNIFORM1FPROC                glUniform1f = nullptr;
	PFNGLUNIFORM2FPROC                glUniform2f = nullptr;
	PFNGLUNIFORM3FPROC                glUniform3f = nullptr;
	PFNGLUNIFORM4FPROC                glUniform4f = nullptr;
	PFNGLUNIFORM1IPROC                glUniform1i = nullptr;
	PFNGLUNIFORM2IPROC                glUniform2i = nullptr;
	PFNGLUNIFORM3IPROC                glUniform3i = nullptr;
	PFNGLUNIFORM4IPROC                glUniform4i = nullptr;
	PFNGLUNIFORM1FVPROC               glUniform1fv = nullptr;
	PFNGLUNIFORM2FVPROC               glUniform2fv = nullptr;
	PFNGLUNIFORM3FVPROC               glUniform3fv = nullptr;
	PFNGLUNIFORM4FVPROC               glUniform4fv = nullptr;
	PFNGLUNIFORM1IVPROC               glUniform1iv = nullptr;
	PFNGLUNIFORM2IVPROC               glUniform2iv = nullptr;
	PFNGLUNIFORM3IVPROC               glUniform3iv = nullptr;
	PFNGLUNIFORM4IVPROC               glUniform4iv = nullptr;
	PFNGLUNIFORMMATRIX2FVPROC         glUniformMatrix2fv = nullptr;
	PFNGLUNIFORMMATRIX3FVPROC         glUniformMatrix3fv = nullptr;
	PFNGLUNIFORMMATRIX4FVPROC         glUniformMatrix4fv = nullptr;
	PFNGLVALIDATEPROGRAMPROC          glValidateProgram = nullptr;
	PFNGLVERTEXATTRIB1DPROC           glVertexAttrib1d = nullptr;
	PFNGLVERTEXATTRIB1DVPROC          glVertexAttrib1dv = nullptr;
	PFNGLVERTEXATTRIB1FPROC           glVertexAttrib1f = nullptr;
	PFNGLVERTEXATTRIB1FVPROC          glVertexAttrib1fv = nullptr;
	PFNGLVERTEXATTRIB1SPROC           glVertexAttrib1s = nullptr;
	PFNGLVERTEXATTRIB1SVPROC          glVertexAttrib1sv = nullptr;
	PFNGLVERTEXATTRIB2DPROC           glVertexAttrib2d = nullptr;
	PFNGLVERTEXATTRIB2DVPROC          glVertexAttrib2dv = nullptr;
	PFNGLVERTEXATTRIB2FPROC           glVertexAttrib2f = nullptr;
	PFNGLVERTEXATTRIB2FVPROC          glVertexAttrib2fv = nullptr;
	PFNGLVERTEXATTRIB2SPROC           glVertexAttrib2s = nullptr;
	PFNGLVERTEXATTRIB2SVPROC          glVertexAttrib2sv = nullptr;
	PFNGLVERTEXATTRIB3DPROC           glVertexAttrib3d = nullptr;
	PFNGLVERTEXATTRIB3DVPROC          glVertexAttrib3dv = nullptr;
	PFNGLVERTEXATTRIB3FPROC           glVertexAttrib3f = nullptr;
	PFNGLVERTEXATTRIB3FVPROC          glVertexAttrib3fv = nullptr;
	PFNGLVERTEXATTRIB3SPROC           glVertexAttrib3s = nullptr;
	PFNGLVERTEXATTRIB3SVPROC          glVertexAttrib3sv = nullptr;
	PFNGLVERTEXATTRIB4NBVPROC         glVertexAttrib4Nbv = nullptr;
	PFNGLVERTEXATTRIB4NIVPROC         glVertexAttrib4Niv = nullptr;
	PFNGLVERTEXATTRIB4NSVPROC         glVertexAttrib4Nsv = nullptr;
	PFNGLVERTEXATTRIB4NUBPROC         glVertexAttrib4Nub = nullptr;
	PFNGLVERTEXATTRIB4NUBVPROC        glVertexAttrib4Nubv = nullptr;
	PFNGLVERTEXATTRIB4NUIVPROC        glVertexAttrib4Nuiv = nullptr;
	PFNGLVERTEXATTRIB4NUSVPROC        glVertexAttrib4Nusv = nullptr;
	PFNGLVERTEXATTRIB4BVPROC          glVertexAttrib4bv = nullptr;
	PFNGLVERTEXATTRIB4DPROC           glVertexAttrib4d = nullptr;
	PFNGLVERTEXATTRIB4DVPROC          glVertexAttrib4dv = nullptr;
	PFNGLVERTEXATTRIB4FPROC           glVertexAttrib4f = nullptr;
	PFNGLVERTEXATTRIB4FVPROC          glVertexAttrib4fv = nullptr;
	PFNGLVERTEXATTRIB4IVPROC          glVertexAttrib4iv = nullptr;
	PFNGLVERTEXATTRIB4SPROC           glVertexAttrib4s = nullptr;
	PFNGLVERTEXATTRIB4SVPROC          glVertexAttrib4sv = nullptr;
	PFNGLVERTEXATTRIB4UBVPROC         glVertexAttrib4ubv = nullptr;
	PFNGLVERTEXATTRIB4UIVPROC         glVertexAttrib4uiv = nullptr;
	PFNGLVERTEXATTRIB4USVPROC         glVertexAttrib4usv = nullptr;
	PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer = nullptr;

	// GL_VERSION_2_1
	PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
	PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
	PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
	PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
	PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
	PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;

	// GL_VERSION_3_0
	PFNGLCOLORMASKIPROC                          glColorMaski = nullptr;
	PFNGLGETBOOLEANI_VPROC                       glGetBooleani_v = nullptr;
	PFNGLGETINTEGERI_VPROC                       glGetIntegeri_v = nullptr;
	PFNGLENABLEIPROC                             glEnablei = nullptr;
	PFNGLDISABLEIPROC                            glDisablei = nullptr;
	PFNGLISENABLEDIPROC                          glIsEnabledi = nullptr;
	PFNGLBEGINTRANSFORMFEEDBACKPROC              glBeginTransformFeedback = nullptr;
	PFNGLENDTRANSFORMFEEDBACKPROC                glEndTransformFeedback = nullptr;
	PFNGLBINDBUFFERRANGEPROC                     glBindBufferRange = nullptr;
	PFNGLBINDBUFFERBASEPROC                      glBindBufferBase = nullptr;
	PFNGLTRANSFORMFEEDBACKVARYINGSPROC           glTransformFeedbackVaryings = nullptr;
	PFNGLGETTRANSFORMFEEDBACKVARYINGPROC         glGetTransformFeedbackVarying = nullptr;
	PFNGLCLAMPCOLORPROC                          glClampColor = nullptr;
	PFNGLBEGINCONDITIONALRENDERPROC              glBeginConditionalRender = nullptr;
	PFNGLENDCONDITIONALRENDERPROC                glEndConditionalRender = nullptr;
	PFNGLVERTEXATTRIBIPOINTERPROC                glVertexAttribIPointer = nullptr;
	PFNGLGETVERTEXATTRIBIIVPROC                  glGetVertexAttribIiv = nullptr;
	PFNGLGETVERTEXATTRIBIUIVPROC                 glGetVertexAttribIuiv = nullptr;
	PFNGLVERTEXATTRIBI1IPROC                     glVertexAttribI1i = nullptr;
	PFNGLVERTEXATTRIBI2IPROC                     glVertexAttribI2i = nullptr;
	PFNGLVERTEXATTRIBI3IPROC                     glVertexAttribI3i = nullptr;
	PFNGLVERTEXATTRIBI4IPROC                     glVertexAttribI4i = nullptr;
	PFNGLVERTEXATTRIBI1UIPROC                    glVertexAttribI1ui = nullptr;
	PFNGLVERTEXATTRIBI2UIPROC                    glVertexAttribI2ui = nullptr;
	PFNGLVERTEXATTRIBI3UIPROC                    glVertexAttribI3ui = nullptr;
	PFNGLVERTEXATTRIBI4UIPROC                    glVertexAttribI4ui = nullptr;
	PFNGLVERTEXATTRIBI1IVPROC                    glVertexAttribI1iv = nullptr;
	PFNGLVERTEXATTRIBI2IVPROC                    glVertexAttribI2iv = nullptr;
	PFNGLVERTEXATTRIBI3IVPROC                    glVertexAttribI3iv = nullptr;
	PFNGLVERTEXATTRIBI4IVPROC                    glVertexAttribI4iv = nullptr;
	PFNGLVERTEXATTRIBI1UIVPROC                   glVertexAttribI1uiv = nullptr;
	PFNGLVERTEXATTRIBI2UIVPROC                   glVertexAttribI2uiv = nullptr;
	PFNGLVERTEXATTRIBI3UIVPROC                   glVertexAttribI3uiv = nullptr;
	PFNGLVERTEXATTRIBI4UIVPROC                   glVertexAttribI4uiv = nullptr;
	PFNGLVERTEXATTRIBI4BVPROC                    glVertexAttribI4bv = nullptr;
	PFNGLVERTEXATTRIBI4SVPROC                    glVertexAttribI4sv = nullptr;
	PFNGLVERTEXATTRIBI4UBVPROC                   glVertexAttribI4ubv = nullptr;
	PFNGLVERTEXATTRIBI4USVPROC                   glVertexAttribI4usv = nullptr;
	PFNGLGETUNIFORMUIVPROC                       glGetUniformuiv = nullptr;
	PFNGLBINDFRAGDATALOCATIONPROC                glBindFragDataLocation = nullptr;
	PFNGLGETFRAGDATALOCATIONPROC                 glGetFragDataLocation = nullptr;
	PFNGLUNIFORM1UIPROC                          glUniform1ui = nullptr;
	PFNGLUNIFORM2UIPROC                          glUniform2ui = nullptr;
	PFNGLUNIFORM3UIPROC                          glUniform3ui = nullptr;
	PFNGLUNIFORM4UIPROC                          glUniform4ui = nullptr;
	PFNGLUNIFORM1UIVPROC                         glUniform1uiv = nullptr;
	PFNGLUNIFORM2UIVPROC                         glUniform2uiv = nullptr;
	PFNGLUNIFORM3UIVPROC                         glUniform3uiv = nullptr;
	PFNGLUNIFORM4UIVPROC                         glUniform4uiv = nullptr;
	PFNGLTEXPARAMETERIIVPROC                     glTexParameterIiv = nullptr;
	PFNGLTEXPARAMETERIUIVPROC                    glTexParameterIuiv = nullptr;
	PFNGLGETTEXPARAMETERIIVPROC                  glGetTexParameterIiv = nullptr;
	PFNGLGETTEXPARAMETERIUIVPROC                 glGetTexParameterIuiv = nullptr;
	PFNGLCLEARBUFFERIVPROC                       glClearBufferiv = nullptr;
	PFNGLCLEARBUFFERUIVPROC                      glClearBufferuiv = nullptr;
	PFNGLCLEARBUFFERFVPROC                       glClearBufferfv = nullptr;
	PFNGLCLEARBUFFERFIPROC                       glClearBufferfi = nullptr;
	PFNGLGETSTRINGIPROC                          glGetStringi = nullptr;
	PFNGLISRENDERBUFFERPROC                      glIsRenderbuffer = nullptr;
	PFNGLBINDRENDERBUFFERPROC                    glBindRenderbuffer = nullptr;
	PFNGLDELETERENDERBUFFERSPROC                 glDeleteRenderbuffers = nullptr;
	PFNGLGENRENDERBUFFERSPROC                    glGenRenderbuffers = nullptr;
	PFNGLRENDERBUFFERSTORAGEPROC                 glRenderbufferStorage = nullptr;
	PFNGLGETRENDERBUFFERPARAMETERIVPROC          glGetRenderbufferParameteriv = nullptr;
	PFNGLISFRAMEBUFFERPROC                       glIsFramebuffer = nullptr;
	PFNGLBINDFRAMEBUFFERPROC                     glBindFramebuffer = nullptr;
	PFNGLDELETEFRAMEBUFFERSPROC                  glDeleteFramebuffers = nullptr;
	PFNGLGENFRAMEBUFFERSPROC                     glGenFramebuffers = nullptr;
	PFNGLCHECKFRAMEBUFFERSTATUSPROC              glCheckFramebufferStatus = nullptr;
	PFNGLFRAMEBUFFERTEXTURE1DPROC                glFramebufferTexture1D = nullptr;
	PFNGLFRAMEBUFFERTEXTURE2DPROC                glFramebufferTexture2D = nullptr;
	PFNGLFRAMEBUFFERTEXTURE3DPROC                glFramebufferTexture3D = nullptr;
	PFNGLFRAMEBUFFERRENDERBUFFERPROC             glFramebufferRenderbuffer = nullptr;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = nullptr;
	PFNGLGENERATEMIPMAPPROC                      glGenerateMipmap = nullptr;
	PFNGLBLITFRAMEBUFFERPROC                     glBlitFramebuffer = nullptr;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC      glRenderbufferStorageMultisample = nullptr;
	PFNGLFRAMEBUFFERTEXTURELAYERPROC             glFramebufferTextureLayer = nullptr;
	PFNGLMAPBUFFERRANGEPROC                      glMapBufferRange = nullptr;
	PFNGLFLUSHMAPPEDBUFFERRANGEPROC              glFlushMappedBufferRange = nullptr;
	PFNGLBINDVERTEXARRAYPROC                     glBindVertexArray = nullptr;
	PFNGLDELETEVERTEXARRAYSPROC                  glDeleteVertexArrays = nullptr;
	PFNGLGENVERTEXARRAYSPROC                     glGenVertexArrays = nullptr;
	PFNGLISVERTEXARRAYPROC                       glIsVertexArray = nullptr;

	// GL_VERSION_3_1
	PFNGLDRAWARRAYSINSTANCEDPROC       glDrawArraysInstanced = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDPROC     glDrawElementsInstanced = nullptr;
	PFNGLTEXBUFFERPROC                 glTexBuffer = nullptr;
	PFNGLPRIMITIVERESTARTINDEXPROC     glPrimitiveRestartIndex = nullptr;
	PFNGLCOPYBUFFERSUBDATAPROC         glCopyBufferSubData = nullptr;
	PFNGLGETUNIFORMINDICESPROC         glGetUniformIndices = nullptr;
	PFNGLGETACTIVEUNIFORMSIVPROC       glGetActiveUniformsiv = nullptr;
	PFNGLGETACTIVEUNIFORMNAMEPROC      glGetActiveUniformName = nullptr;
	PFNGLGETUNIFORMBLOCKINDEXPROC      glGetUniformBlockIndex = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC   glGetActiveUniformBlockiv = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = nullptr;
	PFNGLUNIFORMBLOCKBINDINGPROC       glUniformBlockBinding = nullptr;

	// GL_VERSION_3_2
	PFNGLDRAWELEMENTSBASEVERTEXPROC          glDrawElementsBaseVertex = nullptr;
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC     glDrawRangeElementsBaseVertex = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC     glMultiDrawElementsBaseVertex = nullptr;
	PFNGLPROVOKINGVERTEXPROC                 glProvokingVertex = nullptr;
	PFNGLFENCESYNCPROC                       glFenceSync = nullptr;
	PFNGLISSYNCPROC                          glIsSync = nullptr;
	PFNGLDELETESYNCPROC                      glDeleteSync = nullptr;
	PFNGLCLIENTWAITSYNCPROC                  glClientWaitSync = nullptr;
	PFNGLWAITSYNCPROC                        glWaitSync = nullptr;
	PFNGLGETINTEGER64VPROC                   glGetInteger64v = nullptr;
	PFNGLGETSYNCIVPROC                       glGetSynciv = nullptr;
	PFNGLGETINTEGER64I_VPROC                 glGetInteger64i_v = nullptr;
	PFNGLGETBUFFERPARAMETERI64VPROC          glGetBufferParameteri64v = nullptr;
	PFNGLFRAMEBUFFERTEXTUREPROC              glFramebufferTexture = nullptr;
	PFNGLTEXIMAGE2DMULTISAMPLEPROC           glTexImage2DMultisample = nullptr;
	PFNGLTEXIMAGE3DMULTISAMPLEPROC           glTexImage3DMultisample = nullptr;
	PFNGLGETMULTISAMPLEFVPROC                glGetMultisamplefv = nullptr;
	PFNGLSAMPLEMASKIPROC                     glSampleMaski = nullptr;

	// GL_VERSION_3_3
	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = nullptr;
	PFNGLGETFRAGDATAINDEXPROC            glGetFragDataIndex = nullptr;
	PFNGLGENSAMPLERSPROC                 glGenSamplers = nullptr;
	PFNGLDELETESAMPLERSPROC              glDeleteSamplers = nullptr;
	PFNGLISSAMPLERPROC                   glIsSampler = nullptr;
	PFNGLBINDSAMPLERPROC                 glBindSampler = nullptr;
	PFNGLSAMPLERPARAMETERIPROC           glSamplerParameteri = nullptr;
	PFNGLSAMPLERPARAMETERIVPROC          glSamplerParameteriv = nullptr;
	PFNGLSAMPLERPARAMETERFPROC           glSamplerParameterf = nullptr;
	PFNGLSAMPLERPARAMETERFVPROC          glSamplerParameterfv = nullptr;
	PFNGLSAMPLERPARAMETERIIVPROC         glSamplerParameterIiv = nullptr;
	PFNGLSAMPLERPARAMETERIUIVPROC        glSamplerParameterIuiv = nullptr;
	PFNGLGETSAMPLERPARAMETERIVPROC       glGetSamplerParameteriv = nullptr;
	PFNGLGETSAMPLERPARAMETERIIVPROC      glGetSamplerParameterIiv = nullptr;
	PFNGLGETSAMPLERPARAMETERFVPROC       glGetSamplerParameterfv = nullptr;
	PFNGLGETSAMPLERPARAMETERIUIVPROC     glGetSamplerParameterIuiv = nullptr;
	PFNGLQUERYCOUNTERPROC                glQueryCounter = nullptr;
	PFNGLGETQUERYOBJECTI64VPROC          glGetQueryObjecti64v = nullptr;
	PFNGLGETQUERYOBJECTUI64VPROC         glGetQueryObjectui64v = nullptr;
	PFNGLVERTEXATTRIBDIVISORPROC         glVertexAttribDivisor = nullptr;
	PFNGLVERTEXATTRIBP1UIPROC            glVertexAttribP1ui = nullptr;
	PFNGLVERTEXATTRIBP1UIVPROC           glVertexAttribP1uiv = nullptr;
	PFNGLVERTEXATTRIBP2UIPROC            glVertexAttribP2ui = nullptr;
	PFNGLVERTEXATTRIBP2UIVPROC           glVertexAttribP2uiv = nullptr;
	PFNGLVERTEXATTRIBP3UIPROC            glVertexAttribP3ui = nullptr;
	PFNGLVERTEXATTRIBP3UIVPROC           glVertexAttribP3uiv = nullptr;
	PFNGLVERTEXATTRIBP4UIPROC            glVertexAttribP4ui = nullptr;
	PFNGLVERTEXATTRIBP4UIVPROC           glVertexAttribP4uiv = nullptr;

	// InitOpenGL3
	void InitOpenGL3()
	{
		/*
		// GL_VERSION_1_1
		glDrawArrays = (PFNGLDRAWARRAYSPROC)GetProcAddress("glDrawArrays");
		glDrawElements = (PFNGLDRAWELEMENTSPROC)GetProcAddress("glDrawElements");
		glGetPointerv = (PFNGLGETPOINTERVPROC)GetProcAddress("glGetPointerv");
		glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)GetProcAddress("glPolygonOffset");
		glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)GetProcAddress("glCopyTexImage1D");
		glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)GetProcAddress("glCopyTexImage2D");
		glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)GetProcAddress("glCopyTexSubImage1D");
		glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)GetProcAddress("glCopyTexSubImage2D");
		glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)GetProcAddress("glTexSubImage1D");
		glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)GetProcAddress("glTexSubImage2D");
		glBindTexture = (PFNGLBINDTEXTUREPROC)GetProcAddress("glBindTexture");
		glDeleteTextures = (PFNGLDELETETEXTURESPROC)GetProcAddress("glDeleteTextures");
		glGenTextures = (PFNGLGENTEXTURESPROC)GetProcAddress("glGenTextures");
		glIsTexture = (PFNGLISTEXTUREPROC)GetProcAddress("glIsTexture");
		*/

		// GL_VERSION_1_2
		glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)GetProcAddress("glDrawRangeElements");
		glTexImage3D = (PFNGLTEXIMAGE3DPROC)GetProcAddress("glTexImage3D");
		glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)GetProcAddress("glTexSubImage3D");
		glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)GetProcAddress("glCopyTexSubImage3D");

		// GL_VERSION_1_3
		glActiveTexture = (PFNGLACTIVETEXTUREPROC)GetProcAddress("glActiveTexture");
		glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)GetProcAddress("glSampleCoverage");
		glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)GetProcAddress("glCompressedTexImage3D");
		glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)GetProcAddress("glCompressedTexImage2D");
		glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)GetProcAddress("glCompressedTexImage1D");
		glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)GetProcAddress("glCompressedTexSubImage3D");
		glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)GetProcAddress("glCompressedTexSubImage2D");
		glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)GetProcAddress("glCompressedTexSubImage1D");
		glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)GetProcAddress("glGetCompressedTexImage");

		// GL_VERSION_1_4
		glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)GetProcAddress("glBlendFuncSeparate");
		glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)GetProcAddress("glMultiDrawArrays");
		glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)GetProcAddress("glMultiDrawElements");
		glPointParameterf = (PFNGLPOINTPARAMETERFPROC)GetProcAddress("glPointParameterf");
		glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)GetProcAddress("glPointParameterfv");
		glPointParameteri = (PFNGLPOINTPARAMETERIPROC)GetProcAddress("glPointParameteri");
		glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)GetProcAddress("glPointParameteriv");
		glBlendColor = (PFNGLBLENDCOLORPROC)GetProcAddress("glBlendColor");
		glBlendEquation = (PFNGLBLENDEQUATIONPROC)GetProcAddress("glBlendEquation");

		// GL_VERSION_1_5
		glGenQueries = (PFNGLGENQUERIESPROC)GetProcAddress("glGenQueries");
		glDeleteQueries = (PFNGLDELETEQUERIESPROC)GetProcAddress("glDeleteQueries");
		glIsQuery = (PFNGLISQUERYPROC)GetProcAddress("glIsQuery");
		glBeginQuery = (PFNGLBEGINQUERYPROC)GetProcAddress("glBeginQuery");
		glEndQuery = (PFNGLENDQUERYPROC)GetProcAddress("glEndQuery");
		glGetQueryiv = (PFNGLGETQUERYIVPROC)GetProcAddress("glGetQueryiv");
		glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)GetProcAddress("glGetQueryObjectiv");
		glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)GetProcAddress("glGetQueryObjectuiv");
		glBindBuffer = (PFNGLBINDBUFFERPROC)GetProcAddress("glBindBuffer");
		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)GetProcAddress("glDeleteBuffers");
		glGenBuffers = (PFNGLGENBUFFERSPROC)GetProcAddress("glGenBuffers");
		glIsBuffer = (PFNGLISBUFFERPROC)GetProcAddress("glIsBuffer");
		glBufferData = (PFNGLBUFFERDATAPROC)GetProcAddress("glBufferData");
		glBufferSubData = (PFNGLBUFFERSUBDATAPROC)GetProcAddress("glBufferSubData");
		glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)GetProcAddress("glGetBufferSubData");
		glMapBuffer = (PFNGLMAPBUFFERPROC)GetProcAddress("glMapBuffer");
		glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)GetProcAddress("glUnmapBuffer");
		glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)GetProcAddress("glGetBufferParameteriv");
		glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)GetProcAddress("glGetBufferPointerv");

		// GL_VERSION_2_0
		glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)GetProcAddress("glBlendEquationSeparate");
		glDrawBuffers = (PFNGLDRAWBUFFERSPROC)GetProcAddress("glDrawBuffers");
		glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)GetProcAddress("glStencilOpSeparate");
		glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)GetProcAddress("glStencilFuncSeparate");
		glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)GetProcAddress("glStencilMaskSeparate");
		glAttachShader = (PFNGLATTACHSHADERPROC)GetProcAddress("glAttachShader");
		glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)GetProcAddress("glBindAttribLocation");
		glCompileShader = (PFNGLCOMPILESHADERPROC)GetProcAddress("glCompileShader");
		glCreateProgram = (PFNGLCREATEPROGRAMPROC)GetProcAddress("glCreateProgram");
		glCreateShader = (PFNGLCREATESHADERPROC)GetProcAddress("glCreateShader");
		glDeleteProgram = (PFNGLDELETEPROGRAMPROC)GetProcAddress("glDeleteProgram");
		glDeleteShader = (PFNGLDELETESHADERPROC)GetProcAddress("glDeleteShader");
		glDetachShader = (PFNGLDETACHSHADERPROC)GetProcAddress("glDetachShader");
		glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)GetProcAddress("glDisableVertexAttribArray");
		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)GetProcAddress("glEnableVertexAttribArray");
		glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)GetProcAddress("glGetActiveAttrib");
		glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)GetProcAddress("glGetActiveUniform");
		glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)GetProcAddress("glGetAttachedShaders");
		glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)GetProcAddress("glGetAttribLocation");
		glGetProgramiv = (PFNGLGETPROGRAMIVPROC)GetProcAddress("glGetProgramiv");
		glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)GetProcAddress("glGetProgramInfoLog");
		glGetShaderiv = (PFNGLGETSHADERIVPROC)GetProcAddress("glGetShaderiv");
		glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)GetProcAddress("glGetShaderInfoLog");
		glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)GetProcAddress("glGetShaderSource");
		glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)GetProcAddress("glGetUniformLocation");
		glGetUniformfv = (PFNGLGETUNIFORMFVPROC)GetProcAddress("glGetUniformfv");
		glGetUniformiv = (PFNGLGETUNIFORMIVPROC)GetProcAddress("glGetUniformiv");
		glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)GetProcAddress("glGetVertexAttribdv");
		glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)GetProcAddress("glGetVertexAttribfv");
		glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)GetProcAddress("glGetVertexAttribiv");
		glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)GetProcAddress("glGetVertexAttribPointerv");
		glIsProgram = (PFNGLISPROGRAMPROC)GetProcAddress("glIsProgram");
		glIsShader = (PFNGLISSHADERPROC)GetProcAddress("glIsShader");
		glLinkProgram = (PFNGLLINKPROGRAMPROC)GetProcAddress("glLinkProgram");
		glShaderSource = (PFNGLSHADERSOURCEPROC)GetProcAddress("glShaderSource");
		glUseProgram = (PFNGLUSEPROGRAMPROC)GetProcAddress("glUseProgram");
		glUniform1f = (PFNGLUNIFORM1FPROC)GetProcAddress("glUniform1f");
		glUniform2f = (PFNGLUNIFORM2FPROC)GetProcAddress("glUniform2f");
		glUniform3f = (PFNGLUNIFORM3FPROC)GetProcAddress("glUniform3f");
		glUniform4f = (PFNGLUNIFORM4FPROC)GetProcAddress("glUniform4f");
		glUniform1i = (PFNGLUNIFORM1IPROC)GetProcAddress("glUniform1i");
		glUniform2i = (PFNGLUNIFORM2IPROC)GetProcAddress("glUniform2i");
		glUniform3i = (PFNGLUNIFORM3IPROC)GetProcAddress("glUniform3i");
		glUniform4i = (PFNGLUNIFORM4IPROC)GetProcAddress("glUniform4i");
		glUniform1fv = (PFNGLUNIFORM1FVPROC)GetProcAddress("glUniform1fv");
		glUniform2fv = (PFNGLUNIFORM2FVPROC)GetProcAddress("glUniform2fv");
		glUniform3fv = (PFNGLUNIFORM3FVPROC)GetProcAddress("glUniform3fv");
		glUniform4fv = (PFNGLUNIFORM4FVPROC)GetProcAddress("glUniform4fv");
		glUniform1iv = (PFNGLUNIFORM1IVPROC)GetProcAddress("glUniform1iv");
		glUniform2iv = (PFNGLUNIFORM2IVPROC)GetProcAddress("glUniform2iv");
		glUniform3iv = (PFNGLUNIFORM3IVPROC)GetProcAddress("glUniform3iv");
		glUniform4iv = (PFNGLUNIFORM4IVPROC)GetProcAddress("glUniform4iv");
		glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)GetProcAddress("glUniformMatrix2fv");
		glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)GetProcAddress("glUniformMatrix3fv");
		glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)GetProcAddress("glUniformMatrix4fv");
		glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)GetProcAddress("glValidateProgram");
		glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)GetProcAddress("glVertexAttrib1d");
		glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)GetProcAddress("glVertexAttrib1dv");
		glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)GetProcAddress("glVertexAttrib1f");
		glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)GetProcAddress("glVertexAttrib1fv");
		glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)GetProcAddress("glVertexAttrib1s");
		glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)GetProcAddress("glVertexAttrib1sv");
		glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)GetProcAddress("glVertexAttrib2d");
		glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)GetProcAddress("glVertexAttrib2dv");
		glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)GetProcAddress("glVertexAttrib2f");
		glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)GetProcAddress("glVertexAttrib2fv");
		glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)GetProcAddress("glVertexAttrib2s");
		glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)GetProcAddress("glVertexAttrib2sv");
		glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)GetProcAddress("glVertexAttrib3d");
		glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)GetProcAddress("glVertexAttrib3dv");
		glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)GetProcAddress("glVertexAttrib3f");
		glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)GetProcAddress("glVertexAttrib3fv");
		glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)GetProcAddress("glVertexAttrib3s");
		glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)GetProcAddress("glVertexAttrib3sv");
		glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)GetProcAddress("glVertexAttrib4Nbv");
		glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)GetProcAddress("glVertexAttrib4Niv");
		glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)GetProcAddress("glVertexAttrib4Nsv");
		glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)GetProcAddress("glVertexAttrib4Nub");
		glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)GetProcAddress("glVertexAttrib4Nubv");
		glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)GetProcAddress("glVertexAttrib4Nuiv");
		glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)GetProcAddress("glVertexAttrib4Nusv");
		glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)GetProcAddress("glVertexAttrib4bv");
		glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)GetProcAddress("glVertexAttrib4d");
		glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)GetProcAddress("glVertexAttrib4dv");
		glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)GetProcAddress("glVertexAttrib4f");
		glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)GetProcAddress("glVertexAttrib4fv");
		glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)GetProcAddress("glVertexAttrib4iv");
		glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)GetProcAddress("glVertexAttrib4s");
		glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)GetProcAddress("glVertexAttrib4sv");
		glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)GetProcAddress("glVertexAttrib4ubv");
		glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)GetProcAddress("glVertexAttrib4uiv");
		glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)GetProcAddress("glVertexAttrib4usv");
		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)GetProcAddress("glVertexAttribPointer");

		// GL_VERSION_2_1
		glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)GetProcAddress("glUniformMatrix2x3fv");
		glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)GetProcAddress("glUniformMatrix3x2fv");
		glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)GetProcAddress("glUniformMatrix2x4fv");
		glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)GetProcAddress("glUniformMatrix4x2fv");
		glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)GetProcAddress("glUniformMatrix3x4fv");
		glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)GetProcAddress("glUniformMatrix4x3fv");

		// GL_VERSION_3_0
		glColorMaski = (PFNGLCOLORMASKIPROC)GetProcAddress("glColorMaski");
		glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)GetProcAddress("glGetBooleani_v");
		glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)GetProcAddress("glGetIntegeri_v");
		glEnablei = (PFNGLENABLEIPROC)GetProcAddress("glEnablei");
		glDisablei = (PFNGLDISABLEIPROC)GetProcAddress("glDisablei");
		glIsEnabledi = (PFNGLISENABLEDIPROC)GetProcAddress("glIsEnabledi");
		glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)GetProcAddress("glBeginTransformFeedback");
		glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)GetProcAddress("glEndTransformFeedback");
		glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)GetProcAddress("glBindBufferRange");
		glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)GetProcAddress("glBindBufferBase");
		glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)GetProcAddress("glTransformFeedbackVaryings");
		glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)GetProcAddress("glGetTransformFeedbackVarying");
		glClampColor = (PFNGLCLAMPCOLORPROC)GetProcAddress("glClampColor");
		glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)GetProcAddress("glBeginConditionalRender");
		glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)GetProcAddress("glEndConditionalRender");
		glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)GetProcAddress("glVertexAttribIPointer");
		glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)GetProcAddress("glGetVertexAttribIiv");
		glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)GetProcAddress("glGetVertexAttribIuiv");
		glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)GetProcAddress("glVertexAttribI1i");
		glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)GetProcAddress("glVertexAttribI2i");
		glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)GetProcAddress("glVertexAttribI3i");
		glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)GetProcAddress("glVertexAttribI4i");
		glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)GetProcAddress("glVertexAttribI1ui");
		glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)GetProcAddress("glVertexAttribI2ui");
		glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)GetProcAddress("glVertexAttribI3ui");
		glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)GetProcAddress("glVertexAttribI4ui");
		glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)GetProcAddress("glVertexAttribI1iv");
		glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)GetProcAddress("glVertexAttribI2iv");
		glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)GetProcAddress("glVertexAttribI3iv");
		glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)GetProcAddress("glVertexAttribI4iv");
		glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)GetProcAddress("glVertexAttribI1uiv");
		glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)GetProcAddress("glVertexAttribI2uiv");
		glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)GetProcAddress("glVertexAttribI3uiv");
		glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)GetProcAddress("glVertexAttribI4uiv");
		glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)GetProcAddress("glVertexAttribI4bv");
		glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)GetProcAddress("glVertexAttribI4sv");
		glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)GetProcAddress("glVertexAttribI4ubv");
		glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)GetProcAddress("glVertexAttribI4usv");
		glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)GetProcAddress("glGetUniformuiv");
		glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)GetProcAddress("glBindFragDataLocation");
		glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)GetProcAddress("glGetFragDataLocation");
		glUniform1ui = (PFNGLUNIFORM1UIPROC)GetProcAddress("glUniform1ui");
		glUniform2ui = (PFNGLUNIFORM2UIPROC)GetProcAddress("glUniform2ui");
		glUniform3ui = (PFNGLUNIFORM3UIPROC)GetProcAddress("glUniform3ui");
		glUniform4ui = (PFNGLUNIFORM4UIPROC)GetProcAddress("glUniform4ui");
		glUniform1uiv = (PFNGLUNIFORM1UIVPROC)GetProcAddress("glUniform1uiv");
		glUniform2uiv = (PFNGLUNIFORM2UIVPROC)GetProcAddress("glUniform2uiv");
		glUniform3uiv = (PFNGLUNIFORM3UIVPROC)GetProcAddress("glUniform3uiv");
		glUniform4uiv = (PFNGLUNIFORM4UIVPROC)GetProcAddress("glUniform4uiv");
		glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)GetProcAddress("glTexParameterIiv");
		glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)GetProcAddress("glTexParameterIuiv");
		glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)GetProcAddress("glGetTexParameterIiv");
		glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)GetProcAddress("glGetTexParameterIuiv");
		glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)GetProcAddress("glClearBufferiv");
		glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)GetProcAddress("glClearBufferuiv");
		glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)GetProcAddress("glClearBufferfv");
		glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)GetProcAddress("glClearBufferfi");
		glGetStringi = (PFNGLGETSTRINGIPROC)GetProcAddress("glGetStringi");
		glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)GetProcAddress("glIsRenderbuffer");
		glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)GetProcAddress("glBindRenderbuffer");
		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)GetProcAddress("glDeleteRenderbuffers");
		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)GetProcAddress("glGenRenderbuffers");
		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)GetProcAddress("glRenderbufferStorage");
		glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)GetProcAddress("glGetRenderbufferParameteriv");
		glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)GetProcAddress("glIsFramebuffer");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)GetProcAddress("glBindFramebuffer");
		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)GetProcAddress("glDeleteFramebuffers");
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)GetProcAddress("glGenFramebuffers");
		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)GetProcAddress("glCheckFramebufferStatus");
		glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)GetProcAddress("glFramebufferTexture1D");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)GetProcAddress("glFramebufferTexture2D");
		glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)GetProcAddress("glFramebufferTexture3D");
		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)GetProcAddress("glFramebufferRenderbuffer");
		glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)GetProcAddress("glGetFramebufferAttachmentParameteriv");
		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)GetProcAddress("glGenerateMipmap");
		glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)GetProcAddress("glBlitFramebuffer");
		glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)GetProcAddress("glRenderbufferStorageMultisample");
		glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)GetProcAddress("glFramebufferTextureLayer");
		glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)GetProcAddress("glMapBufferRange");
		glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)GetProcAddress("glFlushMappedBufferRange");
		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)GetProcAddress("glBindVertexArray");
		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)GetProcAddress("glDeleteVertexArrays");
		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)GetProcAddress("glGenVertexArrays");
		glIsVertexArray = (PFNGLISVERTEXARRAYPROC)GetProcAddress("glIsVertexArray");

		// GL_VERSION_3_1
		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)GetProcAddress("glDrawArraysInstanced");
		glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)GetProcAddress("glDrawElementsInstanced");
		glTexBuffer = (PFNGLTEXBUFFERPROC)GetProcAddress("glTexBuffer");
		glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)GetProcAddress("glPrimitiveRestartIndex");
		glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)GetProcAddress("glCopyBufferSubData");
		glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)GetProcAddress("glGetUniformIndices");
		glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)GetProcAddress("glGetActiveUniformsiv");
		glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)GetProcAddress("glGetActiveUniformName");
		glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)GetProcAddress("glGetUniformBlockIndex");
		glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)GetProcAddress("glGetActiveUniformBlockiv");
		glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)GetProcAddress("glGetActiveUniformBlockName");
		glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)GetProcAddress("glUniformBlockBinding");

		// GL_VERSION_3_2
		glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)GetProcAddress("glDrawElementsBaseVertex");
		glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)GetProcAddress("glDrawRangeElementsBaseVertex");
		glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)GetProcAddress("glDrawElementsInstancedBaseVertex");
		glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)GetProcAddress("glMultiDrawElementsBaseVertex");
		glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)GetProcAddress("glProvokingVertex");
		glFenceSync = (PFNGLFENCESYNCPROC)GetProcAddress("glFenceSync");
		glIsSync = (PFNGLISSYNCPROC)GetProcAddress("glIsSync");
		glDeleteSync = (PFNGLDELETESYNCPROC)GetProcAddress("glDeleteSync");
		glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)GetProcAddress("glClientWaitSync");
		glWaitSync = (PFNGLWAITSYNCPROC)GetProcAddress("glWaitSync");
		glGetInteger64v = (PFNGLGETINTEGER64VPROC)GetProcAddress("glGetInteger64v");
		glGetSynciv = (PFNGLGETSYNCIVPROC)GetProcAddress("glGetSynciv");
		glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)GetProcAddress("glGetInteger64i_v");
		glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)GetProcAddress("glGetBufferParameteri64v");
		glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)GetProcAddress("glFramebufferTexture");
		glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)GetProcAddress("glTexImage2DMultisample");
		glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)GetProcAddress("glTexImage3DMultisample");
		glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)GetProcAddress("glGetMultisamplefv");
		glSampleMaski = (PFNGLSAMPLEMASKIPROC)GetProcAddress("glSampleMaski");

		// GL_VERSION_3_3
		glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)GetProcAddress("glBindFragDataLocationIndexed");
		glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)GetProcAddress("glGetFragDataIndex");
		glGenSamplers = (PFNGLGENSAMPLERSPROC)GetProcAddress("glGenSamplers");
		glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)GetProcAddress("glDeleteSamplers");
		glIsSampler = (PFNGLISSAMPLERPROC)GetProcAddress("glIsSampler");
		glBindSampler = (PFNGLBINDSAMPLERPROC)GetProcAddress("glBindSampler");
		glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)GetProcAddress("glSamplerParameteri");
		glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)GetProcAddress("glSamplerParameteriv");
		glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)GetProcAddress("glSamplerParameterf");
		glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)GetProcAddress("glSamplerParameterfv");
		glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)GetProcAddress("glSamplerParameterIiv");
		glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)GetProcAddress("glSamplerParameterIuiv");
		glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)GetProcAddress("glGetSamplerParameteriv");
		glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)GetProcAddress("glGetSamplerParameterIiv");
		glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)GetProcAddress("glGetSamplerParameterfv");
		glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)GetProcAddress("glGetSamplerParameterIuiv");
		glQueryCounter = (PFNGLQUERYCOUNTERPROC)GetProcAddress("glQueryCounter");
		glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)GetProcAddress("glGetQueryObjecti64v");
		glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)GetProcAddress("glGetQueryObjectui64v");
		glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)GetProcAddress("glVertexAttribDivisor");
		glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)GetProcAddress("glVertexAttribP1ui");
		glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)GetProcAddress("glVertexAttribP1uiv");
		glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)GetProcAddress("glVertexAttribP2ui");
		glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)GetProcAddress("glVertexAttribP2uiv");
		glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)GetProcAddress("glVertexAttribP3ui");
		glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)GetProcAddress("glVertexAttribP3uiv");
		glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)GetProcAddress("glVertexAttribP4ui");
		glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)GetProcAddress("glVertexAttribP4uiv");
	}
}
