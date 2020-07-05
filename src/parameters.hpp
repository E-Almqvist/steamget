#include <iostream>

namespace parameters {
	int argc = 0;
	char** argv;
	int argle[];

	void init( int ac, char** av, int alen[] ) { // pass over the vars from the main function
		argc = ac;
		argv = av;
		arglen = alen;
	}

	char* getArg( char key ) {
		int lenBuf;
		if( argc > 0 ) {
			for( int i = 0; i < argc; i++ ) { // this is dumb
				std::cout << i << " : " << lenBuf << " |" << argv[i] << "|" << std::endl;

				if( argv[i][0] == '-' && arglen[i] > 1 ) {
					// return whatever is behind it
					if ( argv[i][1] == key ) { std::cout << "reached return" << std::endl; return argv[i+1]; } 
				}
			}
		}
	}
}
