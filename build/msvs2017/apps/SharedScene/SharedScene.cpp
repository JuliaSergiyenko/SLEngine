#include "SharedScene.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

// CreateScene
void CreateScene(ISLRenderer* renderer)
{
	// create buffers
	ISLBuffer* positionBuffer = renderer->CreateBuffer();
	positionBuffer->UpdateData(nullptr, 1024);
	ISLBuffer* noramlBuffer = renderer->CreateBuffer();
	noramlBuffer->UpdateData(nullptr, 1024);
	ISLIndexBuffer* indexBuffer = renderer->CreateIndexBuffer();
	indexBuffer->UpdateData(nullptr, 1024);

	// create texture 
	ISLTexture2D* baseTexture = renderer->CreateTexture2D();
	baseTexture->UpdateImage(nullptr, 0, 1024, 1024, SL_PIXEL_DATA_TYPE_RGRA);

	// create mesh and setup buffers
	ISLMesh* mesh = renderer->CreateMesh();
	mesh->SetPositionBuffer(positionBuffer);
	mesh->SetNormalBuffer(noramlBuffer);
	mesh->SetIndexBuffer(indexBuffer);
	mesh->SetBaseTexture(baseTexture);
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
}

// DeleteScene
void DeleteRenderScene(ISLRenderer* renderer)
{
	renderer->DeleteResources();
}
