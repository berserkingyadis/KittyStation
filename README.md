# KittyStation
Playstation Emulator in C++ 

This is a PSX Emulator very (very) early in development. I am following several guides to get the gist how to do this, so dont expect any playability or even graphics in a long time.

## Dependencies

You will need SDL2 and cmake to compile on Windows or Linux.

```bash
mkdir build && cd build
cmake ..
make
```

## Running the emulator

```bash
./KittyStation <Path to PS1-BIOS>
```

The supported BIOS is SCPH1001.BIN (md5: `924e392ed05558ffdb115408c263dccf`)

## Compiling under Linux

After installing SDL2 you can just follow the steps under #Dependencies, cmake will find the dependencies.

## Compiling under Windows

You will need to download the [SDL2 develop libraries](https://www.libsdl.org/download-2.0.php). For cmake to find it follow [this tutorial](https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/).
