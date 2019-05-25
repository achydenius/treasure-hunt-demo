import png
from itertools import zip_longest

PNG_FILE = "test.png"


def pack_pixels(pixels):
    """Pack an array of continuous rgb values to tuples:
    e.g. [0, 1, 2, 3, 3, 3] -> [(0, 1, 2), (3, 3, 3)]"""
    return list(zip(*[iter(pixels)] * 3))


def is_block_empty(rows):
    """Define if all pixels in block are empty"""
    return all(all(pixel == (0, 0, 0) for pixel in cols) for cols in rows)


def read_block(data, y, x):
    """Read an 8x8 pixel block from input data"""
    return [pack_pixels(row[x:x + 24]) for row in data[y:y + 8]]

width, height, data, _ = png.Reader(PNG_FILE).read()
pixels = list(data)

blocks = []
for i in range(0, height, 8):
    row = [read_block(pixels, i, j) for j in range(0, width, 8)]

    # Exit on completely empty row of blocks
    if all(is_block_empty(block) for block in row):
        break
    else:
        blocks.append(row)

print(blocks)
