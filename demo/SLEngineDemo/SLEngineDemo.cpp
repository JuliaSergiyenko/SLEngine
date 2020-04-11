#include "SLEngineDemo.hpp"
#include <iostream>

// SLEngine
#include <SLStaticMeshes.hpp>

// dependencies
#define STB_IMAGE_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <tiny_obj_loader.h>
#include <GLFW/glfw3.h>
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
void SLEngineDemo::InitDemo()
{
	// get base objects
	ISLRenderer* renderer = mEngine->GetRenderer();
	ISLProgressor* progressor = mEngine->GetProgressor(); (void)progressor;
	glm::mat4 transform(1.0f);

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
	ISLModel* model = renderer->CreateModel();
	model->AddMesh(mesh);
	model->SetTransform(glm::value_ptr(transform));
	model->SetVisibilityMode(SL_MODEL_VISIBILITY_MODE_VISIBLE);

	// create camera
	glm::mat4 projection = glm::lookAt(glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	mCamera = renderer->CreateCamera();
	mCamera->SetTransform(glm::value_ptr(transform));
	mCamera->SetProjection(glm::value_ptr(projection));
	mCamera->SetViewport(800, 600);

	// create scene
	ISLRenderScene* scene = renderer->CreateScene();
	scene->AddModel(model);
	scene->SetCamera(mCamera);
}

// InitSponza
void SLEngineDemo::InitSponza()
{
	// get base objects
	ISLRenderer* renderer = mEngine->GetRenderer();
	ISLProgressor* progressor = mEngine->GetProgressor(); (void)progressor;
	glm::mat4 transform(1.0f);

	// create camera
	if (!mCamera) {
		glm::mat4 projection = glm::lookAt(glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		mCamera = renderer->CreateCamera();
		mCamera->SetTransform(glm::value_ptr(transform));
		mCamera->SetProjection(glm::value_ptr(projection));
		mCamera->SetViewport(800, 600);
	}

	// create scene
	ISLRenderScene* scene = renderer->CreateScene();
	scene->SetCamera(mCamera);

	tinyobj::attrib_t attribs;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn;
	std::string err;
	tinyobj::LoadObj(&attribs, &shapes, &materials, &warn, &err, "data/A380/A380.obj", "data/A380/", true);
	//tinyobj::LoadObj(&attribs, &shapes, &materials, &err, "data/sponza/sponza.obj", "data/sponza/", true);
	std::cout << err << std::endl;

	// allocate buffers
	std::vector<float> vecVertexBuffer = {};
	std::vector<float> vecNormaldBuffer = {};
	std::vector<float> vecTexCoordBuffer = {};
	for (int i = 0; i < shapes.size(); i++)
	//for (int i = 0; i < 1; i++)
	{
		tinyobj::shape_t& shape = shapes[i];

		// create mesh
		ISLMesh* mesh = renderer->CreateMesh();
		mesh->SetPrimitiveType(SL_PRIMITIVE_TYPE_TRIANGLE);
		mesh->SetPrimitiveCount((uint32_t)shape.mesh.num_face_vertices.size());
		//materials[0].name

		// create buffers
		for (tinyobj::index_t& index : shape.mesh.indices)
		{
			// if vertex exists
			if (index.vertex_index >= 0)
			{
				vecVertexBuffer.push_back(attribs.vertices[3 * index.vertex_index + 0]);
				vecVertexBuffer.push_back(attribs.vertices[3 * index.vertex_index + 1]);
				vecVertexBuffer.push_back(attribs.vertices[3 * index.vertex_index + 2]);
			}

			// if normal exists
			if (index.normal_index >= 0)
			{
				vecNormaldBuffer.push_back(attribs.normals[3 * index.normal_index + 0]);
				vecNormaldBuffer.push_back(attribs.normals[3 * index.normal_index + 1]);
				vecNormaldBuffer.push_back(attribs.normals[3 * index.normal_index + 2]);
			}

			// if texCoords exists
			if (index.texcoord_index >= 0)
			{
				vecTexCoordBuffer.push_back(attribs.texcoords[2 * index.texcoord_index + 0]);
				vecTexCoordBuffer.push_back(attribs.texcoords[2 * index.texcoord_index + 1]);
			}
		}

		// if Vertex buffer not empty
		if (!vecVertexBuffer.empty())
		{
			ISLBuffer* bufferVertex = renderer->CreateBuffer();
			bufferVertex->UpdateData(vecVertexBuffer.data(), (uint32_t)vecVertexBuffer.size() * sizeof(float));
			mesh->SetPositionBuffer(bufferVertex);
		}

		// if Normal buffer not empty
		if (!vecNormaldBuffer.empty())
		{
			ISLBuffer* bufferNormal = renderer->CreateBuffer();
			bufferNormal->UpdateData(vecNormaldBuffer.data(), (uint32_t)vecNormaldBuffer.size() * sizeof(float));
			mesh->SetNormalBuffer(bufferNormal);
		}

		// if TexCoords buffer not empty
		if (!vecTexCoordBuffer.empty())
		{
			ISLBuffer* bufferTexCoord = renderer->CreateBuffer();
			bufferTexCoord->UpdateData(vecTexCoordBuffer.data(), (uint32_t)vecTexCoordBuffer.size() * sizeof(float));
			mesh->SetTexCoordBuffer(bufferTexCoord);
		}

		std::cout << shape.name << std::endl;

		// clear vector buffers
		vecVertexBuffer = {};
		vecNormaldBuffer = {};
		vecTexCoordBuffer = {};
		
		// create model
		ISLModel* model = renderer->CreateModel();
		model->AddMesh(mesh);
		model->SetTransform(glm::value_ptr(transform));
		model->SetVisibilityMode(SL_MODEL_VISIBILITY_MODE_VISIBLE);

		// add model
		scene->AddModel(model);
	}
}

// Init
void SLEngineDemo::Init()
{
	//InitDemo();
	InitSponza();
}

// mCameraUpdate
void SLEngineDemo::Update()
{
	// get base objects
	ISLRenderer* renderer = mEngine->GetRenderer();
	ISLProgressor* progressor = mEngine->GetProgressor();
	ImGuiIO& io = ImGui::GetIO();

	// camera move
	if (io.KeysDown[GLFW_KEY_W] || io.KeysDown[GLFW_KEY_UP]) mCameraEye += (mCameraDir * mCameraSpeed / io.Framerate);
	if (io.KeysDown[GLFW_KEY_S] || io.KeysDown[GLFW_KEY_DOWN]) mCameraEye -= (mCameraDir * mCameraSpeed / io.Framerate);
	if (io.KeysDown[GLFW_KEY_A] || io.KeysDown[GLFW_KEY_LEFT]) mCameraEye -= (glm::normalize(glm::cross(mCameraDir, mCameraUp)) * mCameraSpeed / io.Framerate);
	if (io.KeysDown[GLFW_KEY_D] || io.KeysDown[GLFW_KEY_RIGHT]) mCameraEye += (glm::normalize(glm::cross(mCameraDir, mCameraUp)) * mCameraSpeed / io.Framerate);
	if (io.KeysDown[GLFW_KEY_E]) mCameraEye += (mCameraUp * mCameraSpeed / io.Framerate);
	if (io.KeysDown[GLFW_KEY_Q]) mCameraEye -= (mCameraUp * mCameraSpeed / io.Framerate);
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
	glm::mat4 viewMat = glm::lookAt(mCameraEye, mCameraEye + mCameraDir, mCameraUp);
	glm::mat4 projMat = glm::perspective(glm::radians(45.0f), width / height, 1.0f, 10000.0f);

	// set camera matrices
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
	ImGui::Text(renderer->GetStatString());
	ImGui::DragFloat("Camera speed", &mCameraSpeed, 10.0f, 10.0f, 1000.0f);
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
