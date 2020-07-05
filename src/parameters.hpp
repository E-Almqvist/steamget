namespace parameters {
	int argc = 0;
	char** argv;

	void init( int ac, char** av ) { // pass over the vars from the main function
		argc = ac;
		argv = av;
	}

	char* getArg( char key ) {
		if( argc > 0 ) {
			for( int i = 0; i < argc; i++ ) { // this is dumb 
				if( argv[i][0] == '-' && argv[i][1] == key ) { // if it is the correct key
					return argv[i+1]; // return whatever is behind it
				}
			}
		}
	}
}
