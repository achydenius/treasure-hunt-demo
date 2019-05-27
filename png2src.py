import png

PNG_FILE = "tiles.png"


def map_color(r, g, b):
    """Map RGB value to ZX Spectrum color index & brightness flag"""
    color = 0
    if r == 0 and g == 0 and b > 0:
        color = 1
    elif r > 0 and g == 0 and b == 0:
        color = 2
    elif r > 0 and g == 0 and b > 0:
        color = 3
    elif r == 0 and g > 0 and b == 0:
        color = 4
    elif r == 0 and g > 0 and b > 0:
        color = 5
    elif r > 0 and g > 0 and b == 0:
        color = 6
    elif r > 0 and g > 0 and b > 0:
        color = 7

    brightness = 1 if r > 192 or g > 192 or b > 192 else 0

    return (color, brightness)


def pack_pixels(pixels):
    """Pack list of 8 pixels to a single byte"""
    packed = 0
    for i, c in enumerate(pixels):
        if c != 0:
            packed |= 1 << (7 - i)

    return packed


def is_empty(blocks):
    """Define if all blocks in a row are empty"""
    return all(color == 0 for _, color in blocks)


def read_block(data, y, x):
    """Read an 8x8 pixel block from input data"""
    def is_set(r, g, b):
        return r != 0 or g != 0 or b != 0

    block = []
    attr = 0
    for row in data[y:y + 8]:
        pixels = []
        for i in range(x, x + 24, 3):
            color, brightness = map_color(row[i], row[i + 1], row[i + 2])
            pixels.append(color)
            if color != 0:
                attr = (brightness << 6) | color

        block.append(pack_pixels(pixels))

    return (block, attr)

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
print("char block_data[{0}][{1}] = {{".format(len(blocks), len(blocks[0][0])))
print(",\n".join("    {{ {0} }}".format(", ".join(str(pixel) for pixel in pixels)) for pixels, _ in blocks))
print("};\n")

print("char block_attr[{0}] = {{".format(len(blocks)))
print(",\n".join("    {0}".format(color) for _, color in blocks))
print("};\n")
