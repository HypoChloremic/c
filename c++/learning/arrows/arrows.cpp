// It's to access a member function or member variable of an object through a pointer, as opposed to a regular variable or reference.

// For example: with a regular variable or reference, you use the . operator to access member functions or member variables.

// std::string s = "abc";
// std::cout << s.length() << std::endl;

// But if you're working with a pointer, you need to use the -> operator:

// std::string* s = new std::string("abc");
// std::cout << s->length() << std::endl;
// This kind of makes sense, where we gots a pointer, and we would like
// to access and use some functions associated with the object type etc

// It seems to be a general way to be passing objects around in C++, into 
// various methods. Say we gots a function, and we would like to feed it a 
// special variable. We give it the pointer to the variable, such that the 
// changes may be universal. If we would then like to use the methods attached
// to the passed object, we use the arrow, because the normal period . will
// not work. 