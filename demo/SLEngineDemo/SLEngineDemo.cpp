#include "SLEngineDemo.hpp"

// SLEngine
#include <SLStaticMeshes.hpp>

// dependencies
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <imgui.h>

// SLEngineDemo
SLEngineDemo::SLEngineDemo()
{
	mEngine = new SLEngine();
}

// ~SLEngineDemo
SLEngineDemo::~SLEngineDemo()
{
	delete mEngine;
}

// Init
void SLEngineDemo::Init()
{
	// get base objects
	ISLRenderer* renderer = mEngine->GetRenderer();
	ISLProgressor* progressor = mEngine->GetProgressor(); (void)progressor;

	// create buffers
	ISLBuffer* positionBuffer = renderer->CreateBuffer();
	positionBuffer->UpdateData((float *)SLQuadBuffer_Position, sizeof(SLQuadBuffer_Position));
	ISLBuffer* colorBuffer = renderer->CreateBuffer();
	colorBuffer->UpdateData((float *)SLQuadBuffer_Colors, sizeof(SLQuadBuffer_Colors));
	ISLBuffer* textCoordsBuffer = renderer->CreateBuffer();
	textCoordsBuffer->UpdateData((float *)SLQuadBuffer_TexCoords, sizeof(SLQuadBuffer_TexCoords));

	// create texture 
	int x = 0, y = 0, n = 4;
	stbi_uc *textureData = stbi_load("data/brick.jpg", &x, &y, &n, 4);
	ISLTexture2D* baseTexture = renderer->CreateTexture2D();
	//baseTexture->mCameraUpdateImage(0, SL_PIXEL_DATA_TYPE_RGRA, 512, 512, textureData);
	baseTexture->UpdateImage(0, SL_TEXTURE_DATA_TYPE_RGBA, 512, 512, textureData);
	baseTexture->SetFilteringMode(SL_TEXTURE_FILTERING_MODE_LINEAR);
	stbi_image_free(textureData);

	// create mesh and setmCameraUp buffers
	ISLMesh* mesh = renderer->CreateMesh();
	mesh->SetPositionBuffer(positionBuffer);
	mesh->SetColorBuffer(colorBuffer);
	mesh->SetTexCoordBuffer(textCoordsBuffer);
	mesh->SetBaseTexture(baseTexture);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_POINT);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_LINE);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_LINE_STRIP);
	//mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_TRIANGLE);
	mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_TRIANGLE_STRIP);
	mesh->SetPrimitiveCount(2);
	mesh->SetBaseColor(1.0f, 1.0f, 1.0f, 1.0f);

	// create model
	glm::mat4 transform(1.0f);
	mModel = renderer->CreateModel();
	mModel->AddMesh(mesh);
	mModel->SetTransform(glm::value_ptr(transform));
	mModel->SetVisibilityMode(SL_MODEL_VISIBILITY_MODE_VISIBLE);

	// create camera
	glm::mat4 projection = glm::lookAt(glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mCamera = renderer->CreateCamera();
	mCamera->SetTransform(glm::value_ptr(transform));
	mCamera->SetProjection(glm::value_ptr(projection));
	mCamera->SetViewport(800, 600);

	// create scene
	ISLRenderScene* scene = renderer->CreateScene();
	scene->AddModel(mModel);
	scene->SetCamera(mCamera);
}

// mCameraUpdate
void SLEngineDemo::Update()
{
	// get base objects
	ISLRenderer* renderer = mEngine->GetRenderer();
	ISLProgressor* progressor = mEngine->GetProgressor();
	ImGuiIO& io = ImGui::GetIO();

	// camera move 
	if (io.KeysDown[GLFW_KEY_W] || io.KeysDown[GLFW_KEY_UP]) mCameraEye += mCameraDir / io.Framerate * 2.0f;
	if (io.KeysDown[GLFW_KEY_S] || io.KeysDown[GLFW_KEY_DOWN]) mCameraEye -= mCameraDir / io.Framerate * 2.0f;
	if (io.KeysDown[GLFW_KEY_A] || io.KeysDown[GLFW_KEY_LEFT]) mCameraEye -= glm::normalize(glm::cross(mCameraDir, mCameraUp)) / io.Framerate * 2.0f;
	if (io.KeysDown[GLFW_KEY_D] || io.KeysDown[GLFW_KEY_RIGHT]) mCameraEye += glm::normalize(glm::cross(mCameraDir, mCameraUp)) / io.Framerate * 2.0f;
	if (io.KeysDown[GLFW_KEY_E]) mCameraEye += mCameraUp / io.Framerate * 2.0f;
	if (io.KeysDown[GLFW_KEY_Q]) mCameraEye -= mCameraUp / io.Framerate * 2.0f;
	if (io.KeysDown[GLFW_KEY_ESCAPE]) mShouldClose = true;

	// mouse rotate
	if (io.MouseDown[0]) mCameraYaw += io.MouseDelta.x / 3.0f;
	if (io.MouseDown[0]) mCameraPitch -= io.MouseDelta.y / 3.0f;
	if (mCameraPitch >= +90) mCameraPitch = +89;
	if (mCameraPitch <= -90) mCameraPitch = -89;

	// set new camera mCameraDirection
	mCameraDir = glm::normalize(glm::vec3(
		cos(glm::radians(mCameraPitch)) * cos(glm::radians(mCameraYaw)),
		sin(glm::radians(mCameraPitch)),
		cos(glm::radians(mCameraPitch)) * sin(glm::radians(mCameraYaw))
	));

	// viewport size
	float width = (float)io.DisplaySize.x*io.DisplayFramebufferScale.x;
	float height = (float)io.DisplaySize.y*io.DisplayFramebufferScale.y;

	// create matrices
	glm::mat4 modelMat = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(1.0f, 0.5f, 0.1f));
	glm::mat4 viewMat = glm::lookAt(mCameraEye, mCameraEye + mCameraDir, mCameraUp);
	glm::mat4 projMat = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);

	// set camera matrices
	mModel->SetTransform(glm::value_ptr(modelMat));
	mCamera->SetTransform(glm::value_ptr(viewMat));
	mCamera->SetProjection(glm::value_ptr(projMat));
	mCamera->SetViewport((size_t)width, (size_t)height);

	// Start the Dear ImGui frame
	ImGui::NewFrame();
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("Renderer info");
	ImGui::Text(renderer->GetDescription());
	ImGui::Text(progressor->GetDescription());
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
	ImGui::Text("mCameraEye: (%.3f,%.3f,%.3f)", mCameraEye.x, mCameraEye.y, mCameraEye.z);
	ImGui::Text("mCameraDir: (%.3f,%.3f,%.3f)", mCameraDir.x, mCameraDir.y, mCameraDir.z);
	ImGui::End();
	ImGui::EndFrame();

	// get base objects
	mEngine->GetProgressor()->Progress();
	mEngine->GetRenderer()->Render();
	ImGui::Render();
}

// ShutDown
void SLEngineDemo::ShutDown()
{
	mEngine->GetRenderer()->FreeResources();
}

// get should close
bool SLEngineDemo::GetShouldClose()
{
	return mShouldClose;
}
