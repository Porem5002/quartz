# Quartz

A library for making graphical applications and games

**BEWARE:**
Quartz is still in its infancy meaning that API breaking changes are constantly being made, there is pretty much no documentation and cross platform support is still limited.

<!-- ## Game of Life in Quartz
Example will be here -->

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

## Building from source
To compile Quartz you will need a C++ compiler. At the moment of writing, any of the popular C++ compilers (MSVC, Clang and GCC) should work.

The main way of compiling the library is using the [CMake](https://cmake.org) build system.

To build a debug build you just need to follow these steps:
```sh
mkdir build
cd build
cmake ..
cmake --build .
```

To build a release build replace the last command with this one:
```sh
cmake --build . --config=release
```

If everything was setup correctly and executed successfully, the compiled library will be inside the **build** directory along with the executables of the examples from the **examples** directory.

# License
Quartz is licensed under the [MIT License](LICENSE)
