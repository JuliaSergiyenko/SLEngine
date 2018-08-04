#pragma once

#include <cstdint>

// ISLRenderer
class ISLRenderer;

// SLTextureWrapMode
enum SLTextureWrapMode
{
	SL_TEXTURE_WRAP_MODE_CLAMP  = 0,
	SL_TEXTURE_WRAP_MODE_REPEAT = 1,
};

// SLTextureFilterimgMode
enum SLTextureFilterimgMode
{
	SL_TEXTURE_FILTERING_MODE_NEAREST        = 0,
	SL_TEXTURE_FILTERING_MODE_LINEAR         = 1,
	SL_TEXTURE_FILTERING_MODE_MIPMAP_NEAREST = 2,
	SL_TEXTURE_FILTERING_MODE_MIPMAP_LINEAR  = 3,
};

// SLTextureDataType
enum SLTextureDataType
{
	SL_TEXTURE_DATA_TYPE_RGB  = 0,
	SL_TEXTURE_DATA_TYPE_RGBA = 1,
};

// SLPrimitiveType
enum SLPrimitiveType
{
	SL_PRIMITIVE_TYPE_POINT          = 0,
	SL_PRIMITIVE_TYPE_LINE           = 1,
	SL_PRIMITIVE_TYPE_LINE_STRIP     = 2,
	SL_PRIMITIVE_TYPE_TRIANGLE       = 3,
	SL_PRIMITIVE_TYPE_TRIANGLE_STRIP = 4,
};

// SLModelVisibilityMode
enum SLModelVisibilityMode
{
	SL_MODEL_VISIBILITY_MODE_VISIBLE     = 0,
	SL_MODEL_VISIBILITY_MODE_HIDE        = 1,
	SL_MODEL_VISIBILITY_MODE_TRANSPARENT = 2,
};

// SLRenderSceneVisibilityMode
enum SLRenderSceneVisibilityMode
{
	SL_RENDER_SCENE_VISIBILITY_MODE_VISIBLE = 0,
	SL_RENDER_SCENE_VISIBILITY_MODE_HIDE = 1,
};

// ISLTexture2D
class ISLTexture2D
{
protected:
	// hide constructor and destructor
	ISLTexture2D() {};
	~ISLTexture2D() {};
public:
	// get render device
	virtual ISLRenderer* GetRenderer() const = 0;

	// update image
	virtual void UpdateImage(int32_t mipLevel, SLTextureDataType format, uint32_t width, uint32_t height, const void* data, size_t dataSize = 0) = 0;

	// set texture wrap mode S and T
	virtual void SetWrapModeS(SLTextureWrapMode wrapMode) = 0;
	virtual void SetWrapModeT(SLTextureWrapMode wrapMode) = 0;
	virtual void SetFilteringMode(SLTextureFilterimgMode filterimgMode) = 0;

	// get texture wrap mode S and T
	virtual SLTextureWrapMode GetWrapModeS() const = 0;
	virtual SLTextureWrapMode GetWrapModeT() const = 0;
	virtual SLTextureFilterimgMode GetFilterimgMode() const = 0;
};

// ISLBuffer
class ISLBuffer
{
protected:
	// hide constructor and destructor
	ISLBuffer() {}
	~ISLBuffer() {}
public:
	// get device
	virtual ISLRenderer* GetRenderer() const = 0;

	// update data
	virtual void UpdateData(float* data, uint32_t size) = 0;

	// get buffer size
	virtual uint32_t GetSize() const = 0;
};

// ISLIndexBuffer
class ISLIndexBuffer
{
protected:
	// hide constructor and destructor
	ISLIndexBuffer() {};
	~ISLIndexBuffer() {};
public:
	// get device
	virtual ISLRenderer* GetRenderer() const = 0;

	// update data
	virtual void UpdateData(uint16_t* data, uint32_t size) = 0;

	// get buffer size
	virtual uint32_t GetSize() const = 0;
};

// ISLMesh
class ISLMesh
{
protected:
	// hide constructor and destructor
	ISLMesh() {};
	~ISLMesh() {};
public:
	// get device
	virtual ISLRenderer* GetRenderer() const = 0;

	// set colors
	virtual void SetBaseColor(float r, float g, float b, float a) = 0;

	// set textures
	virtual void SetBaseTexture(ISLTexture2D* texture) = 0;
	virtual void SetDetailTexture(ISLTexture2D* texture) = 0;
	virtual void SetNormalTexture(ISLTexture2D* texture) = 0;

	// set buffers
	virtual void SetPositionBuffer(ISLBuffer* buffer) = 0;
	virtual void SetColorBuffer(ISLBuffer* buffer) = 0;
	virtual void SetNormalBuffer(ISLBuffer* buffer) = 0;
	virtual void SetTangentBuffer(ISLBuffer* buffer) = 0;
	virtual void SetTexCoordBuffer(ISLBuffer* buffer) = 0;
	virtual void SetWeightsBuffer(ISLBuffer* buffer) = 0;
	virtual void SetIndexBuffer(ISLIndexBuffer* buffer) = 0;

	// set primitive info
	virtual void SetPrimitiveCount(uint32_t count) = 0;
	virtual void SetPrimitiveType(SLPrimitiveType primitiveType) = 0;

	// get colors
	virtual void GetBaseColor(float& r, float& g, float& b, float& a) const = 0;

	// get textures
	virtual ISLTexture2D* GetBaseTexture() const = 0;
	virtual ISLTexture2D* GetDetailTexture() const = 0;
	virtual ISLTexture2D* GetNormalTexture() const = 0;

	// get buffers
	virtual ISLBuffer* GetPositionBuffer() const = 0;
	virtual ISLBuffer* GetColorBuffer() const = 0;
	virtual ISLBuffer* GetNormalBuffer() const = 0;
	virtual ISLBuffer* GetTangentBuffer() const = 0;
	virtual ISLBuffer* GetTexCoordBuffer() const = 0;
	virtual ISLBuffer* GetWeightsBuffer() const = 0;
	virtual ISLIndexBuffer* GetIndexBuffer() const = 0;

	// get primitive info
	virtual uint32_t GetPrimitiveCount() const = 0;
	virtual SLPrimitiveType GetPrimitiveType() const = 0;
};

// ISLModel
class ISLModel
{
protected:
	ISLModel() {}
	~ISLModel() {}
public:
	// get device
	virtual ISLRenderer* GetRenderer() const = 0;

	// visibility functions
	virtual void SetVisibilityMode(SLModelVisibilityMode visibilityMode) = 0;
	virtual SLModelVisibilityMode GetVisibilityMode() const = 0;

	// mesh functions
	virtual void AddMesh(ISLMesh* mesh) = 0;
	virtual void RemoveMesh(ISLMesh* mesh) = 0;
	virtual bool IsMeshExists(ISLMesh* mesh) const = 0;

	// transform matrix functions
	virtual void SetTransform(float* mat) = 0;
	virtual void GetTransform(float* mat) const = 0;
};

// ISLCamera
class ISLCamera
{
protected:
	ISLCamera() {}
	~ISLCamera() {}
public:
	// get device
	virtual ISLRenderer* GetRenderer() const = 0;

	// set properties
	virtual void SetViewport(size_t width, size_t height) = 0;
	virtual void SetTransform(float* mat) = 0;
	virtual void SetProjection(float* mat) = 0;

	// set properties
	virtual void GetViewport(size_t& width, size_t& height) const = 0;
	virtual void GetTransform(float* mat) const = 0;
	virtual void GetProjection(float* mat) const = 0;
};

// ISLRenderScene
class ISLRenderScene
{
protected:
	ISLRenderScene() {}
	~ISLRenderScene() {}
public:
	// get device
	virtual ISLRenderer* GetRenderer() const = 0;

	// camera functions
	virtual void SetCamera(ISLCamera* camera) = 0;
	virtual ISLCamera* GetCamera() const = 0;

	// model functions
	virtual void AddModel(ISLModel* model) = 0;
	virtual void RemoveModel(ISLModel* model) = 0;
	virtual bool IsModelExists(ISLModel* model) const = 0;

	// properties
	virtual void SetVisibilityMode(SLRenderSceneVisibilityMode visibilityMode) = 0;
	virtual SLRenderSceneVisibilityMode GetVisibilityMode() const = 0;
};

// ISLRenderer
class ISLRenderer
{
protected:
	// hide constructor
	ISLRenderer() {}
	~ISLRenderer() {}
public:
	// texture functions
	virtual ISLTexture2D* CreateTexture2D() = 0;
	virtual void DeleteTexture2D(ISLTexture2D* texture2d) = 0;
	virtual bool IsTexture2DExists(ISLTexture2D* texture2d) const = 0;

	// buffer functions
	virtual ISLBuffer* CreateBuffer() = 0;
	virtual void DeleteBuffer(ISLBuffer* buffer) = 0;
	virtual bool IsBufferExists(ISLBuffer* buffer) const = 0;

	// index buffer functions
	virtual ISLIndexBuffer* CreateIndexBuffer() = 0;
	virtual void DeleteIndexBuffer(ISLIndexBuffer* buffer) = 0;
	virtual bool IsIndexBufferExists(ISLIndexBuffer* buffer) const = 0;

	// mesh functions
	virtual ISLMesh* CreateMesh() = 0;
	virtual void DeleteMesh(ISLMesh* mesh) = 0;
	virtual bool IsMeshExists(ISLMesh* mesh) const = 0;

	// model functions
	virtual ISLModel* CreateModel() = 0;
	virtual void DeleteModel(ISLModel* model) = 0;
	virtual bool IsModelExists(ISLModel* model) const = 0;

	// camera functions
	virtual ISLCamera* CreateCamera() = 0;
	virtual void DeleteCamera(ISLCamera* camera) = 0;
	virtual bool IsCameraExists(ISLCamera* camera) const = 0;

	// render scene functions
	virtual ISLRenderScene* CreateScene() = 0;
	virtual void DeleteRenderScene(ISLRenderScene* scene) = 0;
	virtual bool IsRenderSceneExists(ISLRenderScene* scene) const = 0;

	// render
	virtual void Render() = 0;

	// delete resource
	virtual void DeleteResources() = 0;

	// get description
	virtual const char* GetDescription() const = 0;
};

// global create SLRenderer
ISLRenderer* CreateSLRenderer();

// global destroy SLRenderer
void DestroySLRenderer(ISLRenderer* renderer);
