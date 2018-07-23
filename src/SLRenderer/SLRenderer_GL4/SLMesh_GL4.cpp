#include "SLMesh_GL4.hpp"
#include <stdexcept>

namespace SLR_GL4
{
	// SLMesh_GL4
	SLMesh_GL4::SLMesh_GL4(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLMesh_GL4
	SLMesh_GL4::~SLMesh_GL4()
	{
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
		mPositionBuffer = (SLBuffer_GL4 *)buffer;
	}

	// SetColorBuffer
	void SLMesh_GL4::SetColorBuffer(ISLBuffer* buffer)
	{
		mColorBuffer = (SLBuffer_GL4 *)buffer;
	}

	// SetNormalBuffer
	void SLMesh_GL4::SetNormalBuffer(ISLBuffer* buffer)
	{
		mNormalBuffer = (SLBuffer_GL4 *)buffer;
	}

	// SetTangentBuffer
	void SLMesh_GL4::SetTangentBuffer(ISLBuffer* buffer)
	{
		mTangentBuffer = (SLBuffer_GL4 *)buffer;
	}

	// SetTexCoordBuffer
	void SLMesh_GL4::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		mTexCoordBuffer = (SLBuffer_GL4 *)buffer;
	}

	// SetWeightsBuffer
	void SLMesh_GL4::SetWeightsBuffer(ISLBuffer* buffer)
	{
		mWeightsBuffer = (SLBuffer_GL4 *)buffer;
	}

	// SetIndexBuffer
	void SLMesh_GL4::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		mIndexBuffer = (SLIndexBuffer_GL4 *)buffer;
	}

	// SetPrimitiveCount
	void SLMesh_GL4::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
	}

	// SetPrimitiveType
	void SLMesh_GL4::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
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
}
