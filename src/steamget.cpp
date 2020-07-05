#include <iostream>
#include "parameters.hpp"
#include <cpr/cpr.h>

namespace steamget {
	const std::string SteamURL = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"; // HTTP POST
	
	struct params { std::string fileid = "NONE"; std::string opath = "./"; };

	params getParameters() {
		params out;
		
		std::cout << "getting args" << std::endl << "fileid" << std::endl;
		// get the arguments
		out.fileid = parameters::getArg('i');
		std::cout << "opath" << std::endl;
		out.opath = parameters::getArg('o');

		return out;
	}

	// cpr::Response sendHTTPPost( auto data ) { return; }

}

int main( int argc, char** argv ) {
	std::cout << "init" << std::endl;
	parameters::init( argc, argv );	// pass the parameters
	std::cout << "post init" << std::endl;

	std::cout << "calling params" << std::endl;
	steamget::params P = steamget::getParameters();
	std::cout << "post call, outputting params opath" << std::endl;
	std::cout << P.opath << std::endl;

	return 0;
}
