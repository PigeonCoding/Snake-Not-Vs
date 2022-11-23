# Snake-Dak-Not-VS
 Snake-Dak for the last time but with just gud old g++ and a MakeFile
 
## how to build
### Windows
-- Install [mingw32](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z/download) (this is the version i use)
and add it to path "TheMingw32Folder/bin" [the tutorial i followed to install it](https://youtu.be/KsG6dJlLBDw)
```
mkdir build
make windows
.\build\windows\build.exe
```

### linux/macOS
-- make sure you have g++
```
mkdir build
mkdir linux
make linux
./build/linux/build.out
```
