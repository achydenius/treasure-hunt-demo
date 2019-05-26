# Treasure Hunt demo

ZX Spectrum tile-based bitmap graphics demo. The executable `main.tap` is included in the repository.

## Build instructions

[z88dk](https://github.com/z88dk/z88dk) is required for building the executable. [Pipenv](https://github.com/pypa/pipenv) is required for converting PNG bitmap to source code.

1. Install Python dependencies with `pipenv install`
2. Convert graphics to source code with `pipenv run python png2src.py > data.h`
3. Build the executable with `make`
