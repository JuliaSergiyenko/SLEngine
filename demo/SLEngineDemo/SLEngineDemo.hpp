#pragma once

// dependencies
#include <glm/glm.hpp>

// SLEngine
#include <SLEngine.hpp>

// SLEngineDemo
class SLEngineDemo
{
private:
	// engine
	SLEngine * mEngine = nullptr;

	// render onjects
	ISLCamera* mCamera = nullptr;

	// camera position
	glm::vec3 mCameraEye = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 mCameraDir = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 mCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	// camera angles
	float mCameraPitch = 0.0f;
	float mCameraYaw = -90.0f;

	// should close
	bool mShouldClose = false;

	// InitDemo
	void InitDemo();
	void InitSponza();
public:
	// constructor and destructor
	SLEngineDemo();
	~SLEngineDemo();

	// main functions
	void Init();
	void Update();
	void ShutDown();

	// get should close
	bool GetShouldClose();
};