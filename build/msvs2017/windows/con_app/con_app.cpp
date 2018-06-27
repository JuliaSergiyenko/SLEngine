#include <iostream>

// SLRenderDevice
class SLRenderDevice;

// SLRDTextureWrapMode
enum SLRDTextureWrapMode
{
	SLRD_TEXTURE_WRAP_MODE_CLAMP  = 0,
	SLRD_TEXTURE_WRAP_MODE_REPEAT = 1,
};

// SLRDTextureFilterimgMode
enum SLRDTextureFilterimgMode 
{
	SLRD_TEXTURE_FILTERING_MODE_NEAREST = 0,
	SLRD_TEXTURE_FILTERING_MODE_LINEAR  = 1,
	SLRD_TEXTURE_FILTERING_MODE_MIPMAP_NEAREST = 2,
	SLRD_TEXTURE_FILTERING_MODE_MIPMAP_LENEAR = 3,
};

// SLRDPixelDataType
enum SLRDPixelDataType 
{
	SLRD_PIXEL_DATA_TYPE_R    = 0,
	SLRD_PIXEL_DATA_TYPE_RG   = 1,
	SLRD_PIXEL_DATA_TYPE_RGB  = 2,
	SLRD_PIXEL_DATA_TYPE_BGR  = 3,
	SLRD_PIXEL_DATA_TYPE_RGRA = 4,
	SLRD_PIXEL_DATA_TYPE_BGRA = 5,
};

// SLRDPixelDataType
enum SLRDBufferUsage 
{
	SLRD_BUFFER_USAGE_STATIC  = 0,
	SLRD_BUFFER_USAGE_DYNAMIC = 1,
};

// ISLRDTexture2D
class ISLRDTexture2D
{
private:
	// render device
	SLRenderDevice * mDevice = nullptr;

	// properties
	SLRDTextureWrapMode mWrapModeS = SLRD_TEXTURE_WRAP_MODE_CLAMP;
	SLRDTextureWrapMode mWrapModeT = SLRD_TEXTURE_WRAP_MODE_CLAMP;
	SLRDTextureFilterimgMode mFilterimgMode = SLRD_TEXTURE_FILTERING_MODE_NEAREST;

	// hide constructor
	ISLRDTexture2D() {};
public:
	// get render device
	SLRenderDevice * GetRenderDevice() const { return mDevice; }

	// get texture wrap mode S and T
	virtual SLRDTextureWrapMode GetWrapModeS() const { return mWrapModeS; }
	virtual SLRDTextureWrapMode GetWrapModeT() const { return mWrapModeS; }

	// set texture wrap mode S and T
	virtual void SetWrapMode(SLRDTextureWrapMode wrapModeS, SLRDTextureWrapMode wrapModeT)
	{
		mWrapModeS = wrapModeS;
		mWrapModeT = wrapModeT;
	}

	// set texture filtering mode
	virtual void SetFilterimgMode(SLRDTextureFilterimgMode filterimgMode) { mFilterimgMode = filterimgMode; }

	// get texture filtering mode
	virtual SLRDTextureFilterimgMode GetFilterimgMode() const { return mFilterimgMode; }
};

// ISLRDBuffer
class ISLRDBuffer
{
private:
	// render device
	SLRenderDevice * mDevice = nullptr;

	// properties
	size_t mSize = 0;
	SLRDBufferUsage mBufferUsage = SLRD_BUFFER_USAGE_DYNAMIC;

	// hide constructor
	ISLRDBuffer() {};
public:
	// get buffer size
	size_t GetSize() { return mSize; };

	// get buffer usage
	virtual void SetUsage(SLRDBufferUsage bufferUsage) { mBufferUsage = bufferUsage; }
	virtual SLRDBufferUsage GetUsage() const { return mBufferUsage; }
};

// ISLRDPrimitive
class ISLRDPrimitive
{
private:
	// render device
	SLRenderDevice * mDevice = nullptr;

	// properties

	// hide constructor
	ISLRDPrimitive() {};
public:
};

// ISLRenderDevice
class ISLRenderDevice
{
private:
	// hide constructor
	ISLRenderDevice() {}
public:
	// texture functions
	virtual ISLRDTexture2D* CreateTexture2D(void * data, size_t dataSize, size_t width, size_t height, SLRDPixelDataType pixelDataType, size_t mipLevel = 0) = 0;
	virtual void UpdateTexture2D(ISLRDTexture2D* texture2d, void * data, size_t dataSize, size_t width, size_t height, SLRDPixelDataType pixelDataType, size_t mipLevel = 0) = 0;
	virtual void DeleteTexture2D(ISLRDTexture2D* texture2d) = 0;

	// buffer functions
	virtual ISLRDBuffer* CreateBuffer(void* data, size_t size) = 0;
	virtual void UpdateBuffer(ISLRDBuffer* buffer, void* data, size_t size) = 0;
	virtual void DeleteBuffer(ISLRDBuffer* buffer) = 0;

	// buffer functions
	virtual ISLRDPrimitive* CreatePrimitive(ISLRDBuffer* vertexBuffer, ISLRDBuffer* indexBuffer, size_t count) = 0;
	virtual void UpdatePrimitive(ISLRDPrimitive* primitive, ISLRDBuffer* vertexBuffer, ISLRDBuffer* indexBuffer, size_t count) = 0;
	virtual void DeletePrimitive(ISLRDPrimitive* primitive) = 0;
};

class SLRenderDevice_GL2 : public ISLRenderDevice {};
class SLRenderDevice_GLES2 : public ISLRenderDevice {};
class SLRenderDevice_Vulkan : public ISLRenderDevice {};
class SLRenderDevice_D3D9 : public ISLRenderDevice {};

int main(int argc, char** argv)
{
	return std::system("pause");
}