#include <iostream>
#include "parameters.hpp"
#include <cpr/cpr.h>

using namespace std;

namespace steamget {
	const string SteamURL = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"; // HTTP POST
}

int main( int argc, char** argv ) {
	//steamget::params P = steamget::getArgs( argc, argv ); // get the arguments
	
	parameters::init( argc, argv );	// pass the parameters
	cout << parameters::getArg('i') << endl; 
		
	return 0;
}
