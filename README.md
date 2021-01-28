# Dstruct - A data structure library written in C

### Use
This library is intended to be a type agnostic library, some minor memory management is required; however this is not much more than passing the size of each data type in bytes.

You must cast your original pointer to a void* in order to store it. When retrieving data from the data structure, you must cast back to the original pointer type and dereference to get the value.


Ex. Creating a linked list
```C
int p = 4;
llist l = create_list();
llist_add(l,(void*)&p,sizeof(int)); // an int is 4 bytes, you can pass 4 here if you'd like
printf("Item: %d\n",*(int*)l.get(0)); // prints the number 4
```


### Building library
There are no external dependencies for this library just build with a build system of your choice.

### GNU Make
```
$ make
```
- Optionally to make the demo program
```
$ make demo
```

### CMake
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Meson
```
$ meson build
$ cd build
$ meson compile
```

### Linking the library to your project

### Make
Copy the shared dstruct library to your project

### CMake 
You can copy the dstruct subdirectory into your project and put `add_subdirectory(dstruct)` in your toplevel CMakeLists.txt


