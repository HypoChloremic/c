# CPP

## Object types

### static objects

#### When to use `static`
One rule of thumb: 'Should I be able to call this method even if no object has been constructed yet', where if yes it the method should be static. For instance, say we have a fahrenheit-to-celsius converter inside an object. This converter will not look any different, irrespective of the object that is constructed with it, therefore make it as a struct

#### What static does
The static keyword denotes objects that belongs to the class itelf and not the constructed instance of the given class. 

Furthermore, using the keyword `static` makes the object belong to the *type* of the given object, and not to the instances by themselves. 

### struct
Allows us to group variables together. It is very much like a class. All objects inside the struct are public, and need to be declared private if we want them so, unlike classes in cpp. 

## Compiling commands

`gcc MovingPoly.cpp -lGL -lGLU -lglut -lm -o MovingPoly`

1. The `-o` flag denotes the name of the output object. 

2. The `-l[name]` flag denotes a library that needs to be included when compiling the code, and is a very important flag to consider. Note that there are several such flags in the aforementioned line of code, indicating that there are several libraries that are required for the compilation. 

