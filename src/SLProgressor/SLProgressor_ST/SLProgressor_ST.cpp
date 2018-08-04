#include "SLProgressor_ST.hpp"
#include <algorithm>

// SLP_ST
namespace SLP_ST
{
	// SLProgressor_ST
	SLProgressor_ST::SLProgressor_ST()
	{
		// empty
	}

	// ~SLProgressor_ST
	SLProgressor_ST::~SLProgressor_ST()
	{
		// empty
	}

	// AddProgressable
	void SLProgressor_ST::AddProgressable(ISLProgressable* progressable)
	{
		// check for exists
		if (!IsProgressableExists(progressable))
			mProgressables.push_back(progressable);
	}

	// RemoveProgressable
	void SLProgressor_ST::RemoveProgressable(ISLProgressable* progressable)
	{
		// remove existing cameras
		mProgressables.erase(std::remove_if(mProgressables.begin(), mProgressables.end(), [&](ISLProgressable* item) {
			return item == item;
		}), mProgressables.end());
	}

	// IsProgressableExists
	bool SLProgressor_ST::IsProgressableExists(ISLProgressable * progressable)
	{
		return (std::find(mProgressables.begin(), mProgressables.end(), progressable) != mProgressables.end());
	}

	// SetMaxDeltaTime
	void SLProgressor_ST::SetMaxDeltaTime(float deltaTime)
	{
		mMaxDeltaTime = deltaTime;
	}

	// SetMinDeltaTime
	void SLProgressor_ST::SetMinDeltaTime(float deltaTime)
	{
		mMinDeltaTime = deltaTime;
	}

	// GetMaxDeltaTime
	float SLProgressor_ST::GetMaxDeltaTime(float deltaTime)
	{
		return mMaxDeltaTime;
	}

	// GetMinDeltaTime
	float SLProgressor_ST::GetMinDeltaTime(float deltaTime)
	{
		return mMinDeltaTime;
	}

	// Progress
	void SLProgressor_ST::Progress()
	{
		// update time stamps
		mPrevTimePoint = mCurrTimePoint;
		mCurrTimePoint = std::chrono::high_resolution_clock::now();

		// update progress sttaus
		mProgressStatus.ProgressTime = std::chrono::duration_cast<std::chrono::nanoseconds>(mCurrTimePoint - mStartTimePoint).count() * 1e-9f;
		mProgressStatus.DeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(mCurrTimePoint - mPrevTimePoint).count() * 1e-9f;

		// apply restrictions
		mProgressStatus.DeltaTime = std::min(mProgressStatus.DeltaTime, mMaxDeltaTime);
		mProgressStatus.DeltaTime = std::max(mProgressStatus.DeltaTime, mMinDeltaTime);

		// progress
		for (int i = 0; i < mProgressables.size(); i++)
			mProgressables[i]->Progress(mProgressStatus);
	}

	// GetDescription
	const char* SLProgressor_ST::GetDescription()
	{
		return "Multi-threaded progressor by OpenMP";
	}
}

// global create SLProgressor
ISLProgressor* CreateSLProgressor()
{
	return new SLP_ST::SLProgressor_ST();
}

// global destroy SLProgressor
void DestroySLProgressor(ISLProgressor* progressor)
{
	delete (SLP_ST::SLProgressor_ST *)progressor;
}