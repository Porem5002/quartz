defines="-D_CRT_SECURE_NO_WARNINGS"
libs="-luser32 -lopengl32 -lgdi32"
includes="-Ithird_party -Isrc"
warnings="-Wall -Wextra -Wno-gnu-zero-variadic-macro-arguments"
cppflags="-std=c++17"

clang++ $defines $libs $includes $warnings $cppflags example/main.cpp -g -o quartz.exe