# ONVIF_player


## How to build
You need next programs/libraries to be installed:
- Qt 5.12
- OpenSSL 3.3.1 (https://slproweb.com/products/Win32OpenSSL.html)
- FFmgpeg 4.4, not higher (https://github.com/andrewGuzGRSE/FFmpegBuilds, https://github.com/BtbN/FFmpeg-Builds)
- signed-media-framework already build on your machine (https://github.com/onvif/signed-media-framework)

### Update submodules after clone
```
git submodule update --init --recursive
```

### Build commands
```
mkdir build

cd build

cmake -DCMAKE_BUILD_TYPE=Debug/Release -DCMAKE_PREFIX_PATH="PATH_TO_YOUR_QT\lib\cmake" -DFFMPEG_PATH="PATH_TO_YOUR_FFMPEG" -DSMF_INCLUDE_PATH="PATH_TO_SIGNED_MEDIA_FRAMEWORK_INCLUDES" -DSMF_LIB_PATH="PATH_TO_SIGNED_MEDIA_FRAMEWORK_LIB" ..

cmake --build . --config Debug/Release -j N
```
"Debug/Release" means Debug OR Release.

CMAKE_PREFIX_PATH and FFMPEG_PATH are needed only on Windows. On Linux libraries installed in system will be used, except you FFmpeg version is not higher that 4.4.

FFMPEG_PATH="PATH_TO_YOUR_FFMPEG" means you should point to folder where include and lib folders are presented.

SMF_XXX_PATH paths are always needed, except in Linux, if you already installed signed-media-framework library after build.


### Run tests
```
ctest -C Debug/Release
```
