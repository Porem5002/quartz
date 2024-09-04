# Quartz

A library for making graphical applications and games

**BEWARE:**
Quartz is still in its infancy meaning that API breaking changes are constantly being made, there is pretty much no documentation and cross platform support is still limited.

## Game of Life in Quartz
https://github.com/user-attachments/assets/441ea195-ef05-487b-b5bd-c6e622b0eb93

## Code Example
```C
#include <quartz.h>

int main() 
{
    quartz_start(900, 600, "My Blue Window");

    while(quartz_update())
    {
        quartz_clear(QUARTZ_BLUE);
    }

    quartz_finish();

    return 0;
}
```

## Platform Support
The only platform supported right now is Windows.

Quartz uses OpenGL 4.3 internally so it can only run on systems with drivers that support it.

## Using Quartz
You can use Quartz either as a static library or as a dynamic one, both versions are provided in the [Precompiled Binaries](https://github.com/Porem5002/quartz/releases/)
 
To use the dynamic version (**quartzdyn**) make sure to define the macro **QUARTZ_DYNAMIC_LIB_IMPORT** when compiling your project (on Windows you also need to link with **quartzdyn.lib**)

To use the static version (**quartz**) you need to link it when compiling your project. Depending on your platform you will also need to link with other native libraries:
- Windows - **user32.lib**, **opengl32.lib** and **gdi32.lib**

After setting up the library for using in your project, you just need to include **quartz.h** to get access to the API.

## Building from source
To compile Quartz you will need a C++ compiler. At the moment of writing, any of the popular C++ compilers (MSVC, Clang and GCC) should work.

The main way of compiling the library is using the [CMake](https://cmake.org) build system.

To build the library you just need to follow these steps:
```sh
mkdir build
cd build
cmake ..
cmake --build .
```

You can also specify some options to control what will be compiled and how it will be compiled:
- **DYNAMIC** - if **ON** compiles as a dynamic library otherwise as a static library
- **EXAMPLES** - if **ON** the examples will be compiled

These options can be specified on the third command of the build steps, for example this will generate a dynamic library without compiling the examples.
```sh
cmake -DDYNAMIC=ON -DEXAMPLES=OFF ..
```

Finally to explicitly select if you want a debug build or a release build you use the **--config** flag of the last build step, like this:
```sh
cmake --build . --config=debug
# OR
cmake --build . --config=release
```

# License
Quartz is licensed under the [MIT License](LICENSE)
