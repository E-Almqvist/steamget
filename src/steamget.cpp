#include <iostream>

using namespace std;

namespace steamget {
	const char * url = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v0001/";

	char * addonID = "1059823362"; // vars for the addon to be downloaded
	char * outPath = "./";

	void getArgs( int argc, char ** argv ) {
		for( int i = 0; i < argc; i++ ) {
			if( argv[i][0] == '-' && sizeof(argv[i]) == 2 ) {
				if( argv[i][1] == 'i' ) { 
					addonID = argv[i+1]; 
				} else if( argv[i][1] == 'o' ) {
					outPath = argv[i+1];		
				}
			}
		}
	}

	void downloadItem() {
		PublishedFileId_t a;
	}
}

int main( int argc, char** argv ) {
	steamget::getArgs( argc, argv ); // apply the arguments
	return 0;
}
