#include <iostream>

#include <SLRenderer/SLRenderer.hpp>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

void bar(const char * str)
{
	std::cout << str << std::endl;
}

void func(void(*GetProcAddress)(const char *))
{
	GetProcAddress("hello!");
}

// main
int main(int argc, char** argv)
{
	//////////////////////////////////////////////////////////////////////////
	// set error handling
	glfwSetErrorCallback([](int error, const char* description) {
		std::cout << "Error: " << description << std::endl;
	});

	// init glfw
	glfwInit();

	// select OpenGL ES version
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// 	// select OpenGL version
	// 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	// create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL3", nullptr, nullptr);

	// set current context
	glfwMakeContextCurrent(window);

	// setup the scene ready for rendering
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);

	//////////////////////////////////////////////////////////////////////////

	// create renderer
	ISLRenderer* renderer = SLRendererFabric::CreateRenderer(SL_RENDERER_TYPE_GL3);
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

	//////////////////////////////////////////////////////////////////////////

	// main loop
	double dt = 0, last_update_time = 0;
	while (!glfwWindowShouldClose(window))
	{
		// render!
		renderer->Render(camera);

		// display and process events through callbacks
		glfwSwapBuffers(window);
		glfwPollEvents();

		// get frame time
		dt = glfwGetTime();
		if ((dt - last_update_time) > 0.2)
			last_update_time = dt;
	}

	//////////////////////////////////////////////////////////////////////////

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

	//////////////////////////////////////////////////////////////////////////

	// exit
	glfwTerminate();

	// exit
	return EXIT_SUCCESS;
}