#include <iostream>

#include <SLRenderer/SLRenderer.hpp>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
// 	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
// 	glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// select OpenGL version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW OpenGL3", nullptr, nullptr);

	// set current context
	glfwMakeContextCurrent(window);

	// setup thescene ready for rendering
	int width = 0, height = 0;
	glfwGetFramebufferSize(window, &width, &height);

	//////////////////////////////////////////////////////////////////////////

	// create renderer
	ISLRenderer* renderer = SLRendererFabric::CreateRenderer(SL_RENDERER_TYPE_GL3);
	std::cout << renderer->GetDescription() << std::endl;

	// create buffers
	ISLBuffer* positionBuffer = renderer->CreateBuffer();
	positionBuffer->UpdateData(nullptr, 1024);
	ISLBuffer* noramlBuffer = renderer->CreateBuffer();
	noramlBuffer->UpdateData(nullptr, 1024);
	ISLIndexBuffer* indexBuffer = renderer->CreateIndexBuffer();
	indexBuffer->UpdateData(nullptr, 1024);

	// create texture 
	ISLTexture2D* baseTexture = renderer->CreateTexture2D();
	std::cout << baseTexture->GetRenderer()->GetDescription();

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
	ISLScene* scene = renderer->CreateScene();
	scene->AddModel(model);
	scene->SetCamera(camera);

	//////////////////////////////////////////////////////////////////////////
	
	// main loop
	double dt = 0, last_update_time = 0;
	while (!glfwWindowShouldClose(window))
	{
		// render!
		renderer->Render();

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

	renderer->DeleteResources();
	
	//////////////////////////////////////////////////////////////////////////

	// exit
	glfwTerminate();

	// exit
	return EXIT_SUCCESS;
}