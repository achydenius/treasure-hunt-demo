import png
from itertools import zip_longest

PNG_FILE = "test.png"


def get_pixel(r, g, b):
    """Get corresponding ZX Spectrum color index"""
    # TODO: Real functionality
    return 0 if r == 0 and g == 0 and b == 0 else 7


def is_empty(blocks):
    """Define if all pixels in row of blocks are empty"""
    return all(all(pixel == 0 for pixel in block) for block in blocks)


def read_block(data, y, x):
    """Read an 8x8 pixel block from input data"""
    block = []
    for row in data[y:y + 8]:
        for i in range(x, x + 24, 3):
            block.append(get_pixel(row[i], row[i + 1], row[i + 2]))

    return block

width, height, data, _ = png.Reader(PNG_FILE).read()
pixels = list(data)

# Read all blocks
blocks = []
for i in range(0, height, 8):
    row = [read_block(pixels, i, j) for j in range(0, width * 3, 24)]

    # Exit on first completely empty row of blocks
    if is_empty(row):
        break
    else:
        blocks += row

# Print source code
print("char data[{0}][{1}] = {{".format(len(blocks), len(blocks[0])))
print(",\n".join("    {{ {0} }}".format(",".join(str(pixel) for pixel in block)) for block in blocks))
print("};")
