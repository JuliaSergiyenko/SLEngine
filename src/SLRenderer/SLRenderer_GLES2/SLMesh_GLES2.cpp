#include "SLMesh_GLES2.hpp"
#include "SLCamera_GLES2.hpp"
#include "SLModel_GLES2.hpp"

// SLR_GLES2
namespace SLR_GLES2
{
	// SLMesh_GLES2
	SLMesh_GLES2::SLMesh_GLES2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLMesh_GLES2
	SLMesh_GLES2::~SLMesh_GLES2()
	{
	}

	// UpdateElementsCount
	void SLMesh_GLES2::UpdateElementsCount()
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
	ISLRenderer* SLMesh_GLES2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetBaseColor
	void SLMesh_GLES2::SetBaseColor(float r, float g, float b, float a)
	{
		mBaseColor[0] = r;
		mBaseColor[1] = g;
		mBaseColor[2] = b;
		mBaseColor[3] = a;
	}

	// SetBaseTexture
	void SLMesh_GLES2::SetBaseTexture(ISLTexture2D* texture)
	{
		mBaseTexture = (SLTexture2D_GLES2 *)texture;
	}

	// SetDetailTexture
	void SLMesh_GLES2::SetDetailTexture(ISLTexture2D* texture)
	{
		mDetailTexture = (SLTexture2D_GLES2 *)texture;
	}

	// SetNormalTexture
	void SLMesh_GLES2::SetNormalTexture(ISLTexture2D* texture)
	{
		mNormalTexture = (SLTexture2D_GLES2 *)texture;
	}

	// SetPositionBuffer
	void SLMesh_GLES2::SetPositionBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mPositionBuffer != buffer)
		{
			// store and update
			mPositionBuffer = (SLBuffer_GLES2 *)buffer;
		}
	}

	// SetColorBuffer
	void SLMesh_GLES2::SetColorBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mColorBuffer != buffer)
		{
			// store and update
			mColorBuffer = (SLBuffer_GLES2 *)buffer;
		}
	}

	// SetNormalBuffer
	void SLMesh_GLES2::SetNormalBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mNormalBuffer != buffer)
		{
			// store and update
			mNormalBuffer = (SLBuffer_GLES2 *)buffer;
		}
	}

	// SetTangentBuffer
	void SLMesh_GLES2::SetTangentBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTangentBuffer != buffer)
		{
			// store and update
			mTangentBuffer = (SLBuffer_GLES2 *)buffer;
		}
	}

	// SetTexCoordBuffer
	void SLMesh_GLES2::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTexCoordBuffer != buffer)
		{
			// store and update
			mTexCoordBuffer = (SLBuffer_GLES2 *)buffer;
		}
	}

	// SetWeightsBuffer
	void SLMesh_GLES2::SetWeightsBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mWeightsBuffer != buffer)
		{
			// store and update
			mWeightsBuffer = (SLBuffer_GLES2 *)buffer;
		}
	}

	// SetIndexBuffer
	void SLMesh_GLES2::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsIndexBufferExists(buffer)))
			return;

		// check if changed
		if (mIndexBuffer != buffer)
		{
			// store and update
			mIndexBuffer = (SLIndexBuffer_GLES2 *)buffer;
		}
	}

	// SetPrimitiveCount
	void SLMesh_GLES2::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
		UpdateElementsCount();
	}

	// SetPrimitiveType
	void SLMesh_GLES2::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
		mGLPrimitiveMode = cSLPrimitiveTypeToGLPrimitiveMode[mPrimitiveType];
		UpdateElementsCount();
	}

	// GetBaseColor
	void SLMesh_GLES2::GetBaseColor(float& r, float& g, float& b, float& a) const
	{
		r = mBaseColor[0];
		g = mBaseColor[1];
		b = mBaseColor[2];
		a = mBaseColor[3];
	}

	// GetBaseTexture
	ISLTexture2D* SLMesh_GLES2::GetBaseTexture() const
	{
		return mBaseTexture;
	}

	// GetDetailTexture
	ISLTexture2D* SLMesh_GLES2::GetDetailTexture() const
	{
		return mDetailTexture;
	}

	// GetNormalTexture
	ISLTexture2D* SLMesh_GLES2::GetNormalTexture() const
	{
		return mNormalTexture;
	}

	// GetPositionBuffer
	ISLBuffer* SLMesh_GLES2::GetPositionBuffer() const
	{
		return mPositionBuffer;
	}

	// GetColorBuffer
	ISLBuffer* SLMesh_GLES2::GetColorBuffer() const
	{
		return mColorBuffer;
	}

	// GetNormalBuffer
	ISLBuffer* SLMesh_GLES2::GetNormalBuffer() const
	{
		return mNormalBuffer;
	}

	// GetTangentBuffer
	ISLBuffer* SLMesh_GLES2::GetTangentBuffer() const
	{
		return mTangentBuffer;
	}

	// GetTexCoordBuffer
	ISLBuffer* SLMesh_GLES2::GetTexCoordBuffer() const
	{
		return mTexCoordBuffer;
	}

	// GetWeightsBuffer
	ISLBuffer* SLMesh_GLES2::GetWeightsBuffer() const
	{
		return mWeightsBuffer;
	}

	// GetIndexBuffer
	ISLIndexBuffer* SLMesh_GLES2::GetIndexBuffer() const
	{
		return mIndexBuffer;
	}

	// GetPrimitiveCount
	uint32_t SLMesh_GLES2::GetPrimitiveCount() const
	{
		return mPrimitiveCount;
	}

	// GetPrimitiveType
	SLPrimitiveType SLMesh_GLES2::GetPrimitiveType() const
	{
		return mPrimitiveType;
	}
}
