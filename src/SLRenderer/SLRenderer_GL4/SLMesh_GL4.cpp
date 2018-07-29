#include "SLMesh_GL4.hpp"
#include "SLCamera_GL4.hpp"
#include "SLModel_GL4.hpp"

// SLR_GL4
namespace SLR_GL4
{
	// SLMesh_GL4
	SLMesh_GL4::SLMesh_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
		// create vertex array handle
		GL_CHECK(glGenVertexArrays(1, &mGLVertexArrayHandle));
	}

	// ~SLMesh_GL4
	SLMesh_GL4::~SLMesh_GL4()
	{
		GL_CHECK(glDeleteVertexArrays(1, &mGLVertexArrayHandle));
	}

	// UpdateElementsCount
	void SLMesh_GL4::UpdateElementsCount()
	{
		switch (mPrimitiveType)
		{
		case SL_PRIMITIVE_TYPE_POINT:
			mGLElementsCount = mPrimitiveCount;
			break;
		case SL_PRIMITIVE_TYPE_LINE:
			mGLElementsCount = mPrimitiveCount * 2;
			break;
		case SL_PRIMITIVE_TYPE_LINE_STRIP:
			mGLElementsCount = mPrimitiveCount + 1;
			break;
		case SL_PRIMITIVE_TYPE_TRIANGLE:
			mGLElementsCount = mPrimitiveCount * 3;
			break;
		case SL_PRIMITIVE_TYPE_TRIANGLE_STRIP:
			mGLElementsCount = mPrimitiveCount + 2;
			break;
		default:
			break;
		}
	}

	// GetRenderer
	ISLRenderer* SLMesh_GL4::GetRenderer() const
	{
		return mRenderer;
	}

	// SetBaseColor
	void SLMesh_GL4::SetBaseColor(float r, float g, float b, float a)
	{
		mBaseColor[0] = r;
		mBaseColor[1] = g;
		mBaseColor[2] = b;
		mBaseColor[3] = a;
	}

	// SetBaseTexture
	void SLMesh_GL4::SetBaseTexture(ISLTexture2D* texture)
	{
		mBaseTexture = (SLTexture2D_GL4 *)texture;
	}

	// SetDetailTexture
	void SLMesh_GL4::SetDetailTexture(ISLTexture2D* texture)
	{
		mDetailTexture = (SLTexture2D_GL4 *)texture;
	}

	// SetNormalTexture
	void SLMesh_GL4::SetNormalTexture(ISLTexture2D* texture)
	{
		mNormalTexture = (SLTexture2D_GL4 *)texture;
	}

	// SetPositionBuffer
	void SLMesh_GL4::SetPositionBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mPositionBuffer != buffer)
		{
			// store and update
			mPositionBuffer = (SLBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetColorBuffer
	void SLMesh_GL4::SetColorBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mColorBuffer != buffer)
		{
			// store and update
			mColorBuffer = (SLBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetNormalBuffer
	void SLMesh_GL4::SetNormalBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mNormalBuffer != buffer)
		{
			// store and update
			mNormalBuffer = (SLBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetTangentBuffer
	void SLMesh_GL4::SetTangentBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTangentBuffer != buffer)
		{
			// store and update
			mTangentBuffer = (SLBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetTexCoordBuffer
	void SLMesh_GL4::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTexCoordBuffer != buffer)
		{
			// store and update
			mTexCoordBuffer = (SLBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetWeightsBuffer
	void SLMesh_GL4::SetWeightsBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mWeightsBuffer != buffer)
		{
			// store and update
			mWeightsBuffer = (SLBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetIndexBuffer
	void SLMesh_GL4::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsIndexBufferExists(buffer)))
			return;

		// check if changed
		if (mIndexBuffer != buffer)
		{
			// store and update
			mIndexBuffer = (SLIndexBuffer_GL4 *)buffer;
			UpdateVAO();
		}
	}

	// SetPrimitiveCount
	void SLMesh_GL4::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
		UpdateElementsCount();
	}

	// SetPrimitiveType
	void SLMesh_GL4::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
		mGLPrimitiveMode = cSLPrimitiveTypeToGLPrimitiveMode[mPrimitiveType];
		UpdateElementsCount();
	}

	// GetBaseColor
	void SLMesh_GL4::GetBaseColor(float& r, float& g, float& b, float& a) const
	{
		r = mBaseColor[0];
		g = mBaseColor[1];
		b = mBaseColor[2];
		a = mBaseColor[3];
	}

	// GetBaseTexture
	ISLTexture2D* SLMesh_GL4::GetBaseTexture() const
	{
		return mBaseTexture;
	}

	// GetDetailTexture
	ISLTexture2D* SLMesh_GL4::GetDetailTexture() const
	{
		return mDetailTexture;
	}

	// GetNormalTexture
	ISLTexture2D* SLMesh_GL4::GetNormalTexture() const
	{
		return mNormalTexture;
	}

	// GetPositionBuffer
	ISLBuffer* SLMesh_GL4::GetPositionBuffer() const
	{
		return mPositionBuffer;
	}

	// GetColorBuffer
	ISLBuffer* SLMesh_GL4::GetColorBuffer() const
	{
		return mColorBuffer;
	}

	// GetNormalBuffer
	ISLBuffer* SLMesh_GL4::GetNormalBuffer() const
	{
		return mNormalBuffer;
	}

	// GetTangentBuffer
	ISLBuffer* SLMesh_GL4::GetTangentBuffer() const
	{
		return mTangentBuffer;
	}

	// GetTexCoordBuffer
	ISLBuffer* SLMesh_GL4::GetTexCoordBuffer() const
	{
		return mTexCoordBuffer;
	}

	// GetWeightsBuffer
	ISLBuffer* SLMesh_GL4::GetWeightsBuffer() const
	{
		return mWeightsBuffer;
	}

	// GetIndexBuffer
	ISLIndexBuffer* SLMesh_GL4::GetIndexBuffer() const
	{
		return mIndexBuffer;
	}

	// GetPrimitiveCount
	uint32_t SLMesh_GL4::GetPrimitiveCount() const
	{
		return mPrimitiveCount;
	}

	// GetPrimitiveType
	SLPrimitiveType SLMesh_GL4::GetPrimitiveType() const
	{
		return mPrimitiveType;
	}

	// update mesh VAO
	void SLMesh_GL4::UpdateVAO()
	{
		// bind VAO
		GL_CHECK(glBindVertexArray(mGLVertexArrayHandle));

		// set position buffer
		if (mPositionBuffer != nullptr)
		{ 
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mPositionBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLPositionAttrLoc, 3, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLPositionAttrLoc));
		}

		// set color buffer
		if (mColorBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mColorBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLColorAttrLoc, 4, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLColorAttrLoc));
		}

		// set normal buffer
		if (mNormalBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mNormalBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLNormalAttrLoc, 3, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLNormalAttrLoc));
		}

		// set tangent buffer
		if (mTangentBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mTangentBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLTangentAttrLoc, 3, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLTangentAttrLoc));
		}

		// set tex coord buffer
		if (mTexCoordBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mTexCoordBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLTexCoordAttrLoc, 2, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLTexCoordAttrLoc));
		}

		// set weights buffer
		if (mWeightsBuffer != nullptr)
		{
			GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, mWeightsBuffer->mGLBufferHandle));
			GL_CHECK(glVertexAttribPointer(mGLWeightsAttrLoc, 4, GL_FLOAT, GL_FALSE, 0, 0));
			GL_CHECK(glEnableVertexAttribArray(mGLWeightsAttrLoc));
		}

		// set index buffer
		if (mIndexBuffer != nullptr)
			GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer->mGLBufferHandle));

		// unbind VAO
		GL_CHECK(glBindVertexArray(0));
	}
}
