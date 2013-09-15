#include <iostream>

#include "Dedika.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "[W] Nothing to start" << std::endl;
		return 0;
	}
	
	std::cout << "[I] Attempting to start " << argv[1] << std::endl;
	
	Dedika app(argc, argv);
	
	// Attempt to inititalize
	if (!app.Init(argv[1])) {
		std::cout << "[E] Couldn't inititalize application" << std::endl;
		return 0;
	}
	
	std::cout << "[I] App inititialized" << std::endl;
	
	// Attempt to run
	if (!app.Run()) {
		std::cout << "[E] Couldn't run application" << std::endl;
		return 0;
	}
	
	std::cout << "[I] Quitting silently..." << std::endl;
	
	return 0;
}
