compiler="g++"
cppflags="-O2 -static -std=c++17 -Wall -Wextra -Wpedantic -D_CRT_SECURE_NO_WARNINGS"

includedirs="-Ithird_party"
$compiler $cppflags $includedirs quartz/quartz_impl.cpp -c -o quartz.obj

libs="-luser32 -lopengl32 -lgdi32"
includedirs="-Iquartz"
$compiler $cppflags $includedirs examples/pong/*.cpp quartz.obj $libs -o pong.exe