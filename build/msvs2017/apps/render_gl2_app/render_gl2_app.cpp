#include <SLRenderer/SLRenderer.hpp>
#include <glm/glm.hpp>
#include <iostream>

// main
int main(int argc, char** argv)
{
	// create renderer
	ISLRenderer* renderer = SLRendererFabric::CreateRenderer(SL_RENDERER_TYPE_GL2);
	std::cout << renderer->GetDescription() << std::endl;

	// create buffers
	ISLBuffer* positionBuffer = renderer->CreateBuffer(nullptr, 1024);
	ISLBuffer* noramlBuffer = renderer->CreateBuffer(nullptr, 1024);
	ISLIndexBuffer* indexBuffer = renderer->CreateIndexBuffer(nullptr, 1024);

	// create texture 
	ISLTexture2D* baseTexture = renderer->CreateTexture2D(nullptr, 0, 1, 1, SL_PIXEL_DATA_TYPE_RGRA);

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
	model->SetTransform(&transform[0][0]);
	model->SetVisibilityMode(SL_MESH_GROUP_VISIBILITY_MODE_VISIBLE);

	// create camera
	ISLCamera* camera = renderer->CreateCamera();
	camera->SetFOV(45.0f);
	camera->SetNearPlane(0.1f);
	camera->SetFarPlane(100.0f);

	// render
	while (true) renderer->Render(camera);

	// delete camera
	renderer->DeleteCamera(camera);

	// delete model
	renderer->DeleteModel(model);

	// delete mesh
	renderer->DeleteMesh(mesh);

	// delete texture
	renderer->DeleteTexture2D(baseTexture);

	// delete buffers
	renderer->DeleteIndexBuffer(indexBuffer);
	renderer->DeleteBuffer(noramlBuffer);
	renderer->DeleteBuffer(positionBuffer);

	return std::system("pause");
}