#include <iostream>

namespace parameters {
	int argc = 0;
	char** argv;

	void init( int ac, char** av ) { // pass over the vars from the main function
		argc = ac;
		argv = av;
	}

	char* getArg( char key ) {
		int lenBuf;
		if( argc > 0 ) {
			for( int i = 0; i < argc; i++ ) { // this is dumb
				lenBuf = sizeof(argv[i])/sizeof(char);
				std::cout << i << " : " << lenBuf << " |" << argv[i] << "|" << std::endl;

				if( argv[i][0] == '-' && lenBuf > 1 ) {
					// return whatever is behind it
					if ( argv[i][1] == key ) { std::cout << "reached return" << std::endl; return argv[i+1]; } 
				}
			}
		}
	}
}
