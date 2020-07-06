#include <iostream>
#include "parameters.hpp"
#include <cpr/cpr.h>

namespace steamget {
	const std::string SteamURL = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"; // HTTP POST
	
	struct params { std::string fileid = "NONE"; std::string opath = "./"; };

	params getParameters() {
		params out;
		
		// get the arguments
		out.fileid = parameters::getArg('i');
		out.opath = parameters::getArg('o');

		return out;
	}

	// cpr::Response sendHTTPPost( auto data ) { return; }

}

int main( int argc, char** argv ) {
	parameters::init( argc, argv );	// pass the parameters
	steamget::params P = steamget::getParameters();
	
	std::cout << P.opath << std::endl;

	return 0;
}
