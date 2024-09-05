# ONVIF_player


## How to build
You need next programs/libraries to be installed:
- Qt 5.12
- OpenSSL 3.3.1 (https://slproweb.com/products/Win32OpenSSL.html)
- FFmgpeg 4.4, not higher (https://github.com/andrewGuzGRSE/FFmpegBuilds, https://github.com/BtbN/FFmpeg-Builds)

### Update submodules after clone
```
git submodule update --init --recursive
```

### Build commands
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug/Release -DCMAKE_PREFIX_PATH="PATH_TO_YOUR_QT\lib\cmake" -DFFMPEG_PATH="PATH_TO_YOUR_FFMPEG"  ..
cmake --build . --config Debug/Release -j N
```
CMAKE_PREFIX_PATH and FFMPEG_PATH needed only on Windows. On Linux libraries installed in system will be used.

### Run tests
```
ctest -C Debug/Release
```
