## MSVC-C-TEMPLATE

### Required Softwares
- [Build Tools for Visual Studio 2026][0]
- [Cmake][1]
- [Ninja][2]

### How to use
```sh
$ git clone --depth 1 https://github.com/doccaico/msvc-c-template.git my-folder
$ cd my-folder
```

### Debug
```sh
# Normal debug build
$ cmake -S . -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
$ cmake --build build/debug --config Debug && build\debug\app.exe

# Using CRTDBG
$ cmake -S . -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DENABLE_CRTDBG=ON
...

# Using ASAN
$ cmake -S . -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DENABLE_ASAN=ON
...
```

### Release
```sh
$ cmake -S . -B build/release -G Ninja -DCMAKE_BUILD_TYPE=Release
$ cmake --build build/release --config Release && build\release\app.exe
```

### Memo
`--build`した時に`メモ: インクルード ファイル:***`というのが大量に出る場合がある。そういう場合は、`build`フォルダーを1度削除してから`chcp 65001`して再度ビルドするとなおる。

[0]: https://visualstudio.microsoft.com/downloads/ "Build Tools for Visual Studio 2026"
[1]: https://cmake.org/download/ "Cmake - Download"
[2]: https://github.com/ninja-build/ninja/releases "Ninja - Download"
