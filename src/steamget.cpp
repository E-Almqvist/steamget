#include <iostream>
#include "parameters.hpp"
#include <cpr/cpr.h>

namespace steamget {
	const std::string SteamURL = "http://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"; // HTTP POST
	
	struct params { std::string fileid = "NONE"; std::string opath = "./"; };

	params getParameters() {
		params out;
		
		// get the arguments
		out.fileid = parameters::getArg('i');
		out.opath = parameters::getArg('o');

		return out;
	}

	cpr::Response sendHTTPPost( std::string url, cpr::Payload payload ) {
		cpr::Response r = cpr::Post(cpr::Url(url), payload);

		return r;	
	}	
}

int main( int argc, char** argv ) {
	parameters::init( argc, argv );	// pass the parameters
	steamget::params P = steamget::getParameters();
	
	std::cout << "Sending HTTP Post request to " << steamget::SteamURL << std::endl << std::endl;

	// Payload 
	cpr::Payload payload = { 
		{"itemcount", "1"}, 
		{"publishedfileids[0]", 
			{"107455292"} // insert the -i (the id parameter) here instead 
		} 
	};
	
	// TO DO: parse the response, and then download the file_url
	// It returns something weird, no file extension... Probably a .gma, no clue.

	cpr::Response res = steamget::sendHTTPPost( steamget::SteamURL, payload );

	std::cout << "--Response--" << std::endl << "Status: " << res.status_code << std::endl << "Elapsed (s): " << res.elapsed << std::endl << "Text: " << std::endl << res.text << std::endl;
	return 0;
}
