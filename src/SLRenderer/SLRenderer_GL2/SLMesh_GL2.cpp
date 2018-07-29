#include "SLMesh_GL2.hpp"
#include "SLCamera_GL2.hpp"
#include "SLModel_GL2.hpp"

// SLR_GL2
namespace SLR_GL2
{
	// SLMesh_GL2
	SLMesh_GL2::SLMesh_GL2(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLMesh_GL2
	SLMesh_GL2::~SLMesh_GL2()
	{	
	}

	// UpdateElementsCount
	void SLMesh_GL2::UpdateElementsCount()
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
	ISLRenderer* SLMesh_GL2::GetRenderer() const
	{
		return mRenderer;
	}

	// SetBaseColor
	void SLMesh_GL2::SetBaseColor(float r, float g, float b, float a)
	{
		mBaseColor[0] = r;
		mBaseColor[1] = g;
		mBaseColor[2] = b;
		mBaseColor[3] = a;
	}

	// SetBaseTexture
	void SLMesh_GL2::SetBaseTexture(ISLTexture2D* texture)
	{
		mBaseTexture = (SLTexture2D_GL2 *)texture;
	}

	// SetDetailTexture
	void SLMesh_GL2::SetDetailTexture(ISLTexture2D* texture)
	{
		mDetailTexture = (SLTexture2D_GL2 *)texture;
	}

	// SetNormalTexture
	void SLMesh_GL2::SetNormalTexture(ISLTexture2D* texture)
	{
		mNormalTexture = (SLTexture2D_GL2 *)texture;
	}

	// SetPositionBuffer
	void SLMesh_GL2::SetPositionBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mPositionBuffer != buffer)
		{
			// store and update
			mPositionBuffer = (SLBuffer_GL2 *)buffer;
		}
	}

	// SetColorBuffer
	void SLMesh_GL2::SetColorBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mColorBuffer != buffer)
		{
			// store and update
			mColorBuffer = (SLBuffer_GL2 *)buffer;
		}
	}

	// SetNormalBuffer
	void SLMesh_GL2::SetNormalBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mNormalBuffer != buffer)
		{
			// store and update
			mNormalBuffer = (SLBuffer_GL2 *)buffer;
		}
	}

	// SetTangentBuffer
	void SLMesh_GL2::SetTangentBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTangentBuffer != buffer)
		{
			// store and update
			mTangentBuffer = (SLBuffer_GL2 *)buffer;
		}
	}

	// SetTexCoordBuffer
	void SLMesh_GL2::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mTexCoordBuffer != buffer)
		{
			// store and update
			mTexCoordBuffer = (SLBuffer_GL2 *)buffer;
		}
	}

	// SetWeightsBuffer
	void SLMesh_GL2::SetWeightsBuffer(ISLBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsBufferExists(buffer)))
			return;

		// check if changed
		if (mWeightsBuffer != buffer)
		{
			// store and update
			mWeightsBuffer = (SLBuffer_GL2 *)buffer;
		}
	}

	// SetIndexBuffer
	void SLMesh_GL2::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		// check if exists in renderer
		if ((buffer != nullptr) && (!GetRenderer()->IsIndexBufferExists(buffer)))
			return;

		// check if changed
		if (mIndexBuffer != buffer)
		{
			// store and update
			mIndexBuffer = (SLIndexBuffer_GL2 *)buffer;
		}
	}

	// SetPrimitiveCount
	void SLMesh_GL2::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
		UpdateElementsCount();
	}

	// SetPrimitiveType
	void SLMesh_GL2::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
		mGLPrimitiveMode = cSLPrimitiveTypeToGLPrimitiveMode[mPrimitiveType];
		UpdateElementsCount();
	}

	// GetBaseColor
	void SLMesh_GL2::GetBaseColor(float& r, float& g, float& b, float& a) const
	{
		r = mBaseColor[0];
		g = mBaseColor[1];
		b = mBaseColor[2];
		a = mBaseColor[3];
	}

	// GetBaseTexture
	ISLTexture2D* SLMesh_GL2::GetBaseTexture() const
	{
		return mBaseTexture;
	}

	// GetDetailTexture
	ISLTexture2D* SLMesh_GL2::GetDetailTexture() const
	{
		return mDetailTexture;
	}

	// GetNormalTexture
	ISLTexture2D* SLMesh_GL2::GetNormalTexture() const
	{
		return mNormalTexture;
	}

	// GetPositionBuffer
	ISLBuffer* SLMesh_GL2::GetPositionBuffer() const
	{
		return mPositionBuffer;
	}

	// GetColorBuffer
	ISLBuffer* SLMesh_GL2::GetColorBuffer() const
	{
		return mColorBuffer;
	}

	// GetNormalBuffer
	ISLBuffer* SLMesh_GL2::GetNormalBuffer() const
	{
		return mNormalBuffer;
	}

	// GetTangentBuffer
	ISLBuffer* SLMesh_GL2::GetTangentBuffer() const
	{
		return mTangentBuffer;
	}

	// GetTexCoordBuffer
	ISLBuffer* SLMesh_GL2::GetTexCoordBuffer() const
	{
		return mTexCoordBuffer;
	}

	// GetWeightsBuffer
	ISLBuffer* SLMesh_GL2::GetWeightsBuffer() const
	{
		return mWeightsBuffer;
	}

	// GetIndexBuffer
	ISLIndexBuffer* SLMesh_GL2::GetIndexBuffer() const
	{
		return mIndexBuffer;
	}

	// GetPrimitiveCount
	uint32_t SLMesh_GL2::GetPrimitiveCount() const
	{
		return mPrimitiveCount;
	}

	// GetPrimitiveType
	SLPrimitiveType SLMesh_GL2::GetPrimitiveType() const
	{
		return mPrimitiveType;
	}
}
