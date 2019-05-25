#include <stdio.h>
#include "data.h"
#include "map.h"

char *attr = (char*)0x5800;

void draw_block(int index, int x, int y) {
    char *block = data[index];

    y <<= 3;
    char low = ((y & 0x38) << 2) | x;
    char high = 0x40 | ((y & 0xC0) >> 3) | (y & 0x7);
    for (int i = 0; i < 8; i++) {
        *(char*)((high << 8) | low) = block[i];
        high++;
    }
}

int main() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 32; j++) {
            draw_block(map[i][j], j, i);
        }
    }

    return 0;
}
