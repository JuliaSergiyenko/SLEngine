#pragma once

#include "SLTexture2D_GL3.hpp"
#include "SLBuffer_GL3.hpp"
#include "SLIndexBuffer_GL3.hpp"

// SLRGL3
namespace SLR_GL3 {
	// SLMesh_GL3
	class SLMesh_GL3 : public ISLMesh
	{
	private:
		// renderer
		ISLRenderer* mRenderer = nullptr;
	public:
		// textures
		SLTexture2D_GL3* mBaseTexture   = nullptr;
		SLTexture2D_GL3* mDetailTexture = nullptr;
		SLTexture2D_GL3* mNormalTexture = nullptr;

		// buffers
		SLBuffer_GL3* mPositionBuffer = nullptr;
		SLBuffer_GL3* mColorBuffer    = nullptr;
		SLBuffer_GL3* mNormalBuffer   = nullptr;
		SLBuffer_GL3* mTangentBuffer  = nullptr;
		SLBuffer_GL3* mTexCoordBuffer = nullptr;
		SLBuffer_GL3* mWeightsBuffer  = nullptr;
		SLIndexBuffer_GL3* mIndexBuffer = nullptr;

		// properties
		float mBaseColor[4]            = { 0,0,0,0 };
		uint32_t mPrimitiveCount       = 0;
		SLPrimitiveType mPrimitiveType = SL_PRIMITIVE_TYPE_TRIANGLE;
	public:
		// OpenGL handles and settings
		GLuint mGLVertexArrayHandle = 0;
		GLuint mGLPrimitiveMode = GL_TRIANGLES;

		// OpenGL attributes locations
		GLuint mGLPositionAttrLoc = 0;
		GLuint mGLColorAttrLoc    = 1;
		GLuint mGLNormalAttrLoc   = 2;
		GLuint mGLTangentAttrLoc  = 3;
		GLuint mGLTexCoordAttrLoc = 4;
		GLuint mGLWeightsAttrLoc  = 5;
	public:
		// constructor and destructor
		SLMesh_GL3(ISLRenderer* renderer);
		~SLMesh_GL3();

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
		void Draw();
	};
}
