# my cpp-project-template

Adapted from some of my pet projects, and to be used as a starting point for new projects. **Needs more work and refining**.

## Notes:
- `cmake` build system (min: `3.22`)
- for both `app` and `lib`, `fmtlog` logging package is included
- Package management using `vcpkg`
- separate shared library (`lib`) project
- `app` project that links `lib`
- auto generation of config.h file (that contains project constants that are part of the build, `config.h.in`)
- `.clang-format`, `.editorconfig`, `.gitignore`...
- `header-only` libs go should go into `deps/`
- tested on latest macOS (intel, m1) and windows
- plays nicely with vscode (with `c++`, `cmake`, `clang-format` extensions), visual studio 2022 and CLion
- look at `fmt` on how to add packages with vcpkg (relevant files: `vcpkg.json` and project `CMakeLists.txt` files)

## Future improvements:
- Add testing
- Add install targets
- `vcpkg` per project, or a way to build/split packages/projects in a modular way
- ... (feel free to suggest)

## Steps to run/setup
1. Get all git submodules
```
git submodule update --init --recursive
```

2. Windows (vcpkg)
```
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg.exe install
```

2. Mac (vcpkg)
```
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install
```

3. Finally, configure, build and run (Windows, but should be the same (other than `.exe` extension) for other platforms)
```
mkdir build
cd build
cmake ../
cmake --build . --config Debug --target ALL_BUILD -j 18
Debug/app.exe
```

## PR's are more than welcome :)
