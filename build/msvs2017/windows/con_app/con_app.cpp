#include <SLRenderer/SLRenderer.hpp>

// main
int main(int argc, char** argv)
{
	// create renderer
	ISLRenderer* renderer = SLRendererFabric::CreateRenderer();

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
	mesh->SetBaseColor(glm::vec4(1.0f));

	// create model
	ISLModel* model = renderer->CreateModel();
	model->AddMesh(mesh);
	model->SetVisibilityMode(SL_MESH_GROUP_VISIBILITY_MODE_VISIBLE);

	// create camera
	ISLCamera* camera = renderer->CreateCamera();
	camera->SetFOV(45.0f);
	camera->SetNearPlane(0.1f);
	camera->SetFarPlane(100.0f);

	// render
	while(true) renderer->Render(camera);

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