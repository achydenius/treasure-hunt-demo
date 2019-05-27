# Treasure Hunt ZX Spectrum game demo

After pixeling some ZX Spectrum graphics during [Alive Dead Media course](https://mycourses.aalto.fi/course/view.php?id=20799) at Aalto Media Lab, I decided to do a small programming exercise and take a look at how the graphics could be used in a real game.

The ZX Spectrum executable *main.tap* can be run with an emulator such as [Fuse](http://fuse-emulator.sourceforge.net/). The character can be moved with arrow keys.

![Demo animation](https://raw.githubusercontent.com/achydenius/treasure-hunt-demo/master/treasure-hunt-demo.gif)

## Build instructions

The bitmap (*tiles.png*) needs to be converted to C code before compiling. [z88dk](https://github.com/z88dk/z88dk) is required for building the executable. [Pipenv](https://github.com/pypa/pipenv) (and Python) is required for converting PNG bitmap to source code.

1. Install Python dependencies with `pipenv install`
2. Convert graphics to source code with `pipenv run python png2src.py > data.h`
3. Build *main.tap* with `make`
