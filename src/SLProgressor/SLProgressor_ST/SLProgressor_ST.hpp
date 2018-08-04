#pragma once

// local libraries
#include "../SLProgressor.hpp"

// standard libraries
#include <vector>
#include <chrono>

// SLP_ST
namespace SLP_ST
{
	// SLProgressor_ST
	class SLProgressor_ST : public ISLProgressor
	{
	private:
		// time stamps
		std::chrono::high_resolution_clock::time_point mStartTimePoint = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::time_point mCurrTimePoint = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::time_point mPrevTimePoint = std::chrono::high_resolution_clock::now();

		// progress status
		SLProgressStatus mProgressStatus;

		// time restrictions
		float mMaxDeltaTime = 0.0f;
		float mMinDeltaTime = 0.0f;

		// progressables
		std::vector<ISLProgressable *> mProgressables;
	public:
		// constructor and destructor
		SLProgressor_ST();
		~SLProgressor_ST();

		// progressable functions
		void AddProgressable(ISLProgressable* progressable);
		void RemoveProgressable(ISLProgressable* progressable);
		bool IsProgressableExists(ISLProgressable* progressable);

		// time restrictions settings
		void SetMaxDeltaTime(float deltaTime);
		void SetMinDeltaTime(float deltaTime);

		// time restrictions getters
		float GetMaxDeltaTime(float deltaTime);
		float GetMinDeltaTime(float deltaTime);

		// progress
		void Progress();

		// get description
		const char* GetDescription();
	};
}