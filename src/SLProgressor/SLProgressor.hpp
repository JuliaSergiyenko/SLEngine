#pragma once

// SLProgressStatus
struct SLProgressStatus
{
	float ProgressTime = 0;
	float DeltaTime = 0;
};

// ISLProgressable
class ISLProgressable
{
public:
	virtual void Progress(const SLProgressStatus& progressStatus) = 0;
};

// ISLProgressor
class ISLProgressor
{
public:
	// progressable functions
	virtual void AddProgressable(ISLProgressable* progressable) = 0;
	virtual void RemoveProgressable(ISLProgressable* progressable) = 0;
	virtual bool IsProgressableExists(ISLProgressable* progressable) = 0;

	// time restrictions settings
	virtual void SetMaxDeltaTime(float deltaTime) = 0;
	virtual void SetMinDeltaTime(float deltaTime) = 0;

	// time restrictions getters
	virtual float GetMaxDeltaTime(float deltaTime) = 0;
	virtual float GetMinDeltaTime(float deltaTime) = 0;

	// progress
	virtual void Progress() = 0;

	// get description
	virtual const char* GetDescription() = 0;
};

// global create SLProgressor
ISLProgressor* CreateSLProgressor();

// global destroy SLProgressor
void DestroySLProgressor(ISLProgressor* progressor);
