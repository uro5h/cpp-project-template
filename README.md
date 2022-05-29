# Modern C++ project template (boilerplate)

Adapted from some of my pet projects, intended to be used as a starting template (boilerplate) for new projects.

**Needs more work and refining, but it is a solid starting point for new projects (in its current state).**

Rename `app` and `lib` to your own liking (both dirs and all occurrences) and build upon. Cheers :beers:.

## Notes:
- `cmake` build system (min: `3.22`)
- package management using `vcpkg`
- separate shared library (`lib`) project
- `app` project that links and includes `lib`
- both `app` and `lib` projects include `fmtlog` (logging library/package)
- auto generation of `config.h` file for both `app` and `lib` project (`config.h` contains project constants that are specified in the cmake files, or passed as parameters in the future, `config.h.in`)
- `.clang-format`, `.editorconfig`, `.gitignore`...
- `header-only` libs go should go into `deps/`
- tested on latest macOS monterey (both intel, m1) and windows
- plays nicely with vscode (with `c++`, `cmake`, `clang-format` extensions), Visual Studio 2022 and CLion
- look at the way `fmt` library is included in cmake and vcpkg files on more info on how to add packages with vcpkg and include in project (relevant files: `vcpkg.json` and project `CMakeLists.txt` files)

## Future improvements:
- **Improve and refine further**
- Add testing
- Add install targets
- `vcpkg` per project, or a way to build/split packages/projects in a modular way
- ... (feel free to suggest)

## Steps to run/setup
1. Get all the git submodules
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

## Contributing
**PRs, suggestions, discussions are always welcome!**
