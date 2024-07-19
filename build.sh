defines="-D_CRT_SECURE_NO_WARNINGS"
libs="-luser32 -lopengl32 -lgdi32"
includes="-Ithird_party"
warnings="-Wall -Wextra -Wno-gnu-zero-variadic-macro-arguments"
cppflags="-std=c++17"

clang++ $defines $libs $includes $warnings $cppflags src/main.cpp -g -o quartz.exe