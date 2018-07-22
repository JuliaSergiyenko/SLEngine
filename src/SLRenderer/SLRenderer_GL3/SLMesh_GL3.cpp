#include "SLMesh_GL3.hpp"
#include <stdexcept>

namespace SLR_GL3
{
	// SLMesh_GL3
	SLMesh_GL3::SLMesh_GL3(ISLRenderer* renderer) : mRenderer(renderer)
	{
	}

	// ~SLMesh_GL3
	SLMesh_GL3::~SLMesh_GL3()
	{
	}

	// GetRenderer
	ISLRenderer* SLMesh_GL3::GetRenderer() const
	{
		return mRenderer;
	}

	// SetBaseColor
	void SLMesh_GL3::SetBaseColor(float r, float g, float b, float a)
	{
		mBaseColor[0] = r;
		mBaseColor[1] = g;
		mBaseColor[2] = b;
		mBaseColor[3] = a;
	}

	// SetBaseTexture
	void SLMesh_GL3::SetBaseTexture(ISLTexture2D* texture)
	{
		mBaseTexture = (SLTexture2D_GL3 *)texture;
	}

	// SetDetailTexture
	void SLMesh_GL3::SetDetailTexture(ISLTexture2D* texture)
	{
		mDetailTexture = (SLTexture2D_GL3 *)texture;
	}

	// SetNormalTexture
	void SLMesh_GL3::SetNormalTexture(ISLTexture2D* texture)
	{
		mNormalTexture = (SLTexture2D_GL3 *)texture;
	}

	// SetPositionBuffer
	void SLMesh_GL3::SetPositionBuffer(ISLBuffer* buffer)
	{
		mPositionBuffer = (SLBuffer_GL3 *)buffer;
	}

	// SetColorBuffer
	void SLMesh_GL3::SetColorBuffer(ISLBuffer* buffer)
	{
		mColorBuffer = (SLBuffer_GL3 *)buffer;
	}

	// SetNormalBuffer
	void SLMesh_GL3::SetNormalBuffer(ISLBuffer* buffer)
	{
		mNormalBuffer = (SLBuffer_GL3 *)buffer;
	}

	// SetTangentBuffer
	void SLMesh_GL3::SetTangentBuffer(ISLBuffer* buffer)
	{
		mTangentBuffer = (SLBuffer_GL3 *)buffer;
	}

	// SetTexCoordBuffer
	void SLMesh_GL3::SetTexCoordBuffer(ISLBuffer* buffer)
	{
		mTexCoordBuffer = (SLBuffer_GL3 *)buffer;
	}

	// SetWeightsBuffer
	void SLMesh_GL3::SetWeightsBuffer(ISLBuffer* buffer)
	{
		mWeightsBuffer = (SLBuffer_GL3 *)buffer;
	}

	// SetIndexBuffer
	void SLMesh_GL3::SetIndexBuffer(ISLIndexBuffer* buffer)
	{
		mIndexBuffer = (SLIndexBuffer_GL3 *)buffer;
	}

	// SetPrimitiveCount
	void SLMesh_GL3::SetPrimitiveCount(uint32_t count)
	{
		mPrimitiveCount = count;
	}

	// SetPrimitiveType
	void SLMesh_GL3::SetPrimitiveType(SLPrimitiveType primitiveType)
	{
		mPrimitiveType = primitiveType;
	}

	// GetBaseColor
	void SLMesh_GL3::GetBaseColor(float& r, float& g, float& b, float& a)
	{
		r = mBaseColor[0];
		g = mBaseColor[1];
		b = mBaseColor[2];
		a = mBaseColor[3];
	}

	// GetBaseTexture
	ISLTexture2D* SLMesh_GL3::GetBaseTexture() const
	{
		return mBaseTexture;
	}

	// GetDetailTexture
	ISLTexture2D* SLMesh_GL3::GetDetailTexture() const
	{
		return mDetailTexture;
	}

	// GetNormalTexture
	ISLTexture2D* SLMesh_GL3::GetNormalTexture() const
	{
		return mNormalTexture;
	}

	// GetPositionBuffer
	ISLBuffer* SLMesh_GL3::GetPositionBuffer() const
	{
		return mPositionBuffer;
	}

	// GetColorBuffer
	ISLBuffer* SLMesh_GL3::GetColorBuffer() const
	{
		return mColorBuffer;
	}

	// GetNormalBuffer
	ISLBuffer* SLMesh_GL3::GetNormalBuffer() const
	{
		return mNormalBuffer;
	}

	// GetTangentBuffer
	ISLBuffer* SLMesh_GL3::GetTangentBuffer() const
	{
		return mTangentBuffer;
	}

	// GetTexCoordBuffer
	ISLBuffer* SLMesh_GL3::GetTexCoordBuffer() const
	{
		return mTexCoordBuffer;
	}

	// GetWeightsBuffer
	ISLBuffer* SLMesh_GL3::GetWeightsBuffer() const
	{
		return mWeightsBuffer;
	}

	// GetIndexBuffer
	ISLIndexBuffer* SLMesh_GL3::GetIndexBuffer() const
	{
		return mIndexBuffer;
	}

	// GetPrimitiveCount
	uint32_t SLMesh_GL3::GetPrimitiveCount() const
	{
		return mPrimitiveCount;
	}

	// GetPrimitiveType
	SLPrimitiveType SLMesh_GL3::GetPrimitiveType() const
	{
		return mPrimitiveType;
	}
}