#include "SharedScene.hpp"

// OpenGL attributes locations
// GLuint mGLPositionAttrLoc = 0;
// GLuint mGLColorAttrLoc = 1;
// GLuint mGLNormalAttrLoc = 2;
// GLuint mGLTangentAttrLoc = 3;
// GLuint mGLTexCoordAttrLoc = 4;
// GLuint mGLWeightsAttrLoc = 5;

// simple triangle positions
static const float positions[] =
{
	-0.6f, -0.4f, +0.0f,
	+0.6f, -0.4f, +0.0f,
	+0.0f, +0.6f, +0.0f,
};

// simple triangle colors
static const float colors[] =
{
	+1.0f, +0.0f, +0.0f, +1.0f,
	+0.0f, +1.0f, +0.0f, +1.0f,
	+0.0f, +0.0f, +1.0f, +1.0f,
};

// CreateScene
void CreateScene(ISLRenderer* renderer, ISLModel** ppModel, ISLCamera** ppCamera)
{
	// create buffers
	ISLBuffer* positionBuffer = renderer->CreateBuffer();
	positionBuffer->UpdateData((float *)positions, sizeof(positions));
	ISLBuffer* colorBuffer = renderer->CreateBuffer();
	colorBuffer->UpdateData((float *)colors, sizeof(colors));

	// create texture 
	ISLTexture2D* baseTexture = renderer->CreateTexture2D();
	baseTexture->UpdateImage(nullptr, 0, 1024, 1024, SL_PIXEL_DATA_TYPE_RGRA);

	// create mesh and setup buffers
	ISLMesh* mesh = renderer->CreateMesh();
	mesh->SetPositionBuffer(positionBuffer);
	mesh->SetColorBuffer(colorBuffer);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_POINT);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_LINE);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_LINE_STRIP);
	mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_TRIANGLE);
	mesh->SetPrimitiveCount(1);
	mesh->SetBaseColor(1.0f, 1.0f, 1.0f, 1.0f);

	// create model
	glm::mat4 transform(1.0f);
	ISLModel* model = renderer->CreateModel();
	model->AddMesh(mesh);
	model->SetTransform(glm::value_ptr(transform));
	model->SetVisibilityMode(SL_MODEL_VISIBILITY_MODE_VISIBLE);

	// create camera
	glm::mat4 projection = glm::lookAt(glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	ISLCamera* camera = renderer->CreateCamera();
	camera->SetTransform(glm::value_ptr(transform));
	camera->SetProjection(glm::value_ptr(projection));
	camera->SetViewport(800, 600);

	// create scene
	ISLRenderScene* scene = renderer->CreateScene();
	scene->AddModel(model);
	scene->SetCamera(camera);

	*ppModel = model;
	*ppCamera = camera;
}

// DeleteScene
void DeleteRenderScene(ISLRenderer* renderer)
{
	renderer->DeleteResources();
}
