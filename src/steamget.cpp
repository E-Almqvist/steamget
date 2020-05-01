#include <iostream>

using namespace std;

namespace steamget {
	const char * url = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v0001/";

	void info( string txt, bool linebreak = true ) {
		cout << txt;
		if( linebreak ) {
			cout << endl;
		}
	}
	
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

	void downloadItem( params addonInfo ) {
		info( "Downloading addon: ", false );
		cout << addonInfo.addonID << endl;
	}
}

int main( int argc, char** argv ) {
	steamget::params P = steamget::getArgs( argc, argv ); // apply the arguments
	steamget::downloadItem( P );
	return 0;
}
