// Normal headers
#include <iostream>

using namespace std;

namespace steamget {
	const string SteamURL = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/";
	
	struct params {
		char * addonID = "NONE";
		char * outPath = "./";
	};

	params getArgs( int argc, char ** argv ) {
		params returnParams;
		for( int i = 0; i < argc; i++ ) {
			if( argv[i][0] == '-' ) {
				if( argv[i][1] == 'i' ) { 
					returnParams.addonID = argv[i+1]; 
				} else if( argv[i][1] == 'o' ) {
					returnParams.outPath = argv[i+1];
				}
			}
		}
		return returnParams;
	}
}

int main( int argc, char** argv ) {
	steamget::params P = steamget::getArgs( argc, argv ); // apply the arguments
	return 0;
}
