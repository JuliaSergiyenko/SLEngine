#include "SLProgressor_OMP.hpp"
#include <algorithm>
#pragma warning( push )
#pragma warning( disable : 4199)
#include <omp.h>
#pragma warning( pop )

// SLP_OMP
namespace SLP_OMP
{
	// SLProgressor_OMP
	SLProgressor_OMP::SLProgressor_OMP()
	{
		// empty
	}

	// ~SLProgressor_OMP
	SLProgressor_OMP::~SLProgressor_OMP()
	{
		// empty
	}

	// AddProgressable
	void SLProgressor_OMP::AddProgressable(ISLProgressable* progressable)
	{
		// check for exists
		if (!IsProgressableExists(progressable))
			mProgressables.push_back(progressable);
	}

	// RemoveProgressable
	void SLProgressor_OMP::RemoveProgressable(ISLProgressable* progressable)
	{
		// remove existing cameras
		mProgressables.erase(std::remove_if(mProgressables.begin(), mProgressables.end(), [&](ISLProgressable* item) {
			return item == item;
		}), mProgressables.end());
	}

	// IsProgressableExists
	bool SLProgressor_OMP::IsProgressableExists(ISLProgressable * progressable)
	{
		return (std::find(mProgressables.begin(), mProgressables.end(), progressable) != mProgressables.end());
	}

	// SetMaxDeltaTime
	void SLProgressor_OMP::SetMaxDeltaTime(float deltaTime)
	{
		mMaxDeltaTime = deltaTime;
	}

	// SetMinDeltaTime
	void SLProgressor_OMP::SetMinDeltaTime(float deltaTime)
	{
		mMinDeltaTime = deltaTime;
	}

	// GetMaxDeltaTime
	float SLProgressor_OMP::GetMaxDeltaTime(float deltaTime)
	{
		return mMaxDeltaTime;
	}

	// GetMinDeltaTime
	float SLProgressor_OMP::GetMinDeltaTime(float deltaTime)
	{
		return mMinDeltaTime;
	}

	// Progress
	void SLProgressor_OMP::Progress()
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
		#pragma warning( push )
		#pragma warning( disable : 4199)
		#pragma omp parallel for
		for (int i = 0; i < mProgressables.size(); i++)
			mProgressables[i]->Progress(mProgressStatus);
		#pragma warning( pop ) 
	}

	// GetDescription
	const char* SLProgressor_OMP::GetDescription()
	{
		return "Multi-threaded progressor by OpenMP";
	}
}

// global create SLProgressor
ISLProgressor* CreateSLProgressor()
{
	return new SLP_OMP::SLProgressor_OMP();
}

// global destroy SLProgressor
void DestroySLProgressor(ISLProgressor* progressor)
{
	delete (SLP_OMP::SLProgressor_OMP *)progressor;
}