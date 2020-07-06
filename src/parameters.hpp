#include <iostream>
#include <string>

namespace parameters {
	int argc = 0;
	char** argv;

	void init( int ac, char** av ) { // pass over the vars from the main function
		argc = ac;
		argv = av;
	}

	std::string getArg( char key ) {
		if( argc > 0 ) {
			int strBuf;

			for( int i = 0; i < argc; i++ ) { // this is dumb
				strBuf = std::string(argv[i]).length();
				
				if( argv[i][0] == '-' && strBuf > 1 ) {
					// return whatever is behind it
					if ( argv[i][1] == key && i+1 < argc ) { 
						return std::string(argv[i+1]);
					} 
				}
			}
		}
		return "";
	}
}
