#include <iostream>
#include "SLProgressor/SLProgressor.hpp"

// Progressed
class Progressed : public ISLProgressable
{
public:
	// Progress
	void Progress(const SLProgressStatus& progressStatus)
	{
		std::cout << progressStatus.ProgressTime << " " << progressStatus.DeltaTime << std::endl;
	}
};

// main
int main(int argc, char ** argv)
{
	// progressor
	ISLProgressor* progressor = CreateSLProgressor();
	progressor->AddProgressable(new Progressed());
	progressor->AddProgressable(new Progressed());
	progressor->AddProgressable(new Progressed());
	std::cout << progressor->GetDescription() << std::endl;

	// progress
	progressor->Progress();
	progressor->Progress();
	progressor->Progress();
	progressor->Progress();
	progressor->Progress();
	progressor->Progress();

	// pause
	std::system("pause");
}