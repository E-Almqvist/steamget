// Normal headers
#include <iostream>

// curlpp headers
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

// 
using namespace std;
using namespace curlpp::options;

namespace steamget {
	const string SteamURL = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/";

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
		cout << addonInfo.addonID << " at " << addonInfo.outPath << endl;

		try {
			curlpp::Cleanup sgCleanup;
			
			{
				cout << curlpp::options::Url(SteamURL);
			}	
		}	

		catch(curlpp::RuntimeError & e) {
			cout << e.what() << endl;
		}	

		catch(curlpp::LogicError & e) {
			cout << e.what() << endl;
		}
	}
}

int main( int argc, char** argv ) {
	steamget::params P = steamget::getArgs( argc, argv ); // apply the arguments
	steamget::downloadItem( P );
	return 0;
}
