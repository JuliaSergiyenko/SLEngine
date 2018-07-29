#pragma once

#include "SLTexture2D_GL4.hpp"
#include "SLBuffer_GL4.hpp"
#include "SLIndexBuffer_GL4.hpp"
#include "SLShader_GL4.hpp"

// SLR_GL4
namespace SLR_GL4 {
	// SLMesh_GL4
	class SLMesh_GL4 : public ISLMesh
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// textures
		SLTexture2D_GL4* mBaseTexture   = nullptr;
		SLTexture2D_GL4* mDetailTexture = nullptr;
		SLTexture2D_GL4* mNormalTexture = nullptr;

		// buffers
		SLBuffer_GL4* mPositionBuffer = nullptr;
		SLBuffer_GL4* mColorBuffer    = nullptr;
		SLBuffer_GL4* mNormalBuffer   = nullptr;
		SLBuffer_GL4* mTangentBuffer  = nullptr;
		SLBuffer_GL4* mTexCoordBuffer = nullptr;
		SLBuffer_GL4* mWeightsBuffer  = nullptr;
		SLIndexBuffer_GL4* mIndexBuffer = nullptr;

		// shader
		SLShader_GL4* mShader = nullptr;

		// properties
		float mBaseColor[4]            = { 0,0,0,0 };
		uint32_t mPrimitiveCount       = 0;
		SLPrimitiveType mPrimitiveType = SL_PRIMITIVE_TYPE_TRIANGLE;
	public:
		// OpenGL handles and settings
		GLuint mGLVertexArrayHandle = 0;
		GLuint mGLPrimitiveMode = GL_TRIANGLES;
		GLuint mGLElementsCount = GL_TRIANGLES;

		// OpenGL attributes locations
		GLuint mGLPositionAttrLoc = cSLVertexAttribLication_Position;
		GLuint mGLColorAttrLoc = cSLVertexAttribLication_Color;
		GLuint mGLNormalAttrLoc = cSLVertexAttribLication_Normal;
		GLuint mGLTangentAttrLoc = cSLVertexAttribLication_Tangent;
		GLuint mGLTexCoordAttrLoc = cSLVertexAttribLication_TexCoord;
		GLuint mGLWeightsAttrLoc = cSLVertexAttribLication_Weights;
	private:
		// utils
		void UpdateElementsCount();
	public:
		// constructor and destructor
		SLMesh_GL4(ISLRenderer* renderer);
		~SLMesh_GL4();

		// get device
		virtual ISLRenderer* GetRenderer() const;

		// set colors
		virtual void SetBaseColor(float r, float g, float b, float a);

		// set textures
		virtual void SetBaseTexture(ISLTexture2D* texture);
		virtual void SetDetailTexture(ISLTexture2D* texture);
		virtual void SetNormalTexture(ISLTexture2D* texture);

		// set buffers
		virtual void SetPositionBuffer(ISLBuffer* buffer);
		virtual void SetColorBuffer(ISLBuffer* buffer);
		virtual void SetNormalBuffer(ISLBuffer* buffer);
		virtual void SetTangentBuffer(ISLBuffer* buffer);
		virtual void SetTexCoordBuffer(ISLBuffer* buffer);
		virtual void SetWeightsBuffer(ISLBuffer* buffer);
		virtual void SetIndexBuffer(ISLIndexBuffer* buffer);

		// set primitive info
		virtual void SetPrimitiveCount(uint32_t count);
		virtual void SetPrimitiveType(SLPrimitiveType primitiveType);

		// get colors
		virtual void GetBaseColor(float& r, float& g, float& b, float& a) const;

		// get textures
		virtual ISLTexture2D* GetBaseTexture() const;
		virtual ISLTexture2D* GetDetailTexture() const;
		virtual ISLTexture2D* GetNormalTexture() const;

		// get buffers
		virtual ISLBuffer* GetPositionBuffer() const;
		virtual ISLBuffer* GetColorBuffer() const;
		virtual ISLBuffer* GetNormalBuffer() const;
		virtual ISLBuffer* GetTangentBuffer() const;
		virtual ISLBuffer* GetTexCoordBuffer() const;
		virtual ISLBuffer* GetWeightsBuffer() const;
		virtual ISLIndexBuffer* GetIndexBuffer() const;

		// get primitive info
		virtual uint32_t GetPrimitiveCount() const;
		virtual SLPrimitiveType GetPrimitiveType() const;

		// update mesh VAO
		void UpdateVAO();
		void Draw(ISLCamera* camera, ISLModel* model);
	};
}
