// so if we would like to use classes in multiple files
// we are supposed to define them inside .h files, 
// we cannot define classes in .cpp files,
// refer to them via a .h file,
// and then have them called by a different .cpp file
// instead, the class definition must be inside a .h file
// it seems also that there are only one class definition
// per .h file, which must have the same name as the class
// we are defining. 

#pragma once
#ifndef someMaths
//#define someMaths
// we cannot use public or private here, seeing that
// we are in the global namespace, where everything is public
class someMaths {
	// it seems that we need to indent it like this when we do 
	// public stuff
public:
	// dont forget the fucking parenthesis for the method that 
	// we are defining ffs.
	int someRandomIn() {
		return 10;
	}
};
#endif // !someMaths
