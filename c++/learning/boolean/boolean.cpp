// Regarding the usage of |= in c++
// a |= b; is just syntactic sugar for a = a | b;. Same syntax is valid for almost every operator in C++.
// But int i |= 5; is an error, because in the definition line you must have an initialisation, that is an expression that does not use the variable being declared.
// int i=3;
// i |= 5;
// is valid and will give value 7 (3 | 5) to i.
