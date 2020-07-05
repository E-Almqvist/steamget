#include <iostream>
#include "parameters.hpp"
#include <cpr/cpr.h>

using namespace std;

namespace steamget {
	const string SteamURL = "https://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"; // HTTP POST
	
	struct params { string fileid = "NONE"; string opath = "./"; };

	params getParameters() {
		params out;
		
		cout << "getting args" << endl << "fileid" << endl;
		// get the arguments
		out.fileid = parameters::getArg('i');
		cout << "opath" << endl;
		out.opath = parameters::getArg('o');

		return out;
	}
	
	void prepairPayload( string* param ) {
	
	}

	// cpr::Response sendHTTPPost( auto data ) { return; }

}

int main( int argc, char** argv ) {
	cout << "init" << endl;
	parameters::init( argc, argv );	// pass the parameters
	cout << "post init" << endl;

	cout << "calling params" << endl;
	steamget::params P = steamget::getParameters();
	cout << "post call, outputting params opath" << endl;
	cout << P.opath << endl;

	return 0;
}
