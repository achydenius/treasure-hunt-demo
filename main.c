#include <stdio.h>
#include <input.h>
#include "data.h"
#include "map.h"

#define SCREEN_ADDR 0x4000
#define ATTR_ADDR 0x05800

#define KEY_LEFT 0x8
#define KEY_RIGHT 0x9
#define KEY_DOWN 0xA
#define KEY_UP 0xB

typedef struct Player {
    char x, y;
    char needs_update;
    char previous_x, previous_y;
} Player;

char allowed_tile_count = 24;
char allowed_tiles[] = {
    0x07,
    0x0A, 0x0B, 0x2A, 0x2B,
    0x0C, 0x2C,
    0x0D, 0x0E, 0x0F, 0x10, 0x2D, 0x2E, 0x2F, 0x30, 0x4D, 0x4E, 0x4F, 0x50,
    0x18, 0x19, 0x38, 0x39,
    0x1A
};

void draw_tile(int index, int x, int y) {
    char *tile = block_data[index];
    char attr = block_attr[index];

    *(char*)(ATTR_ADDR + (y * 32 + x)) = attr;

    y <<= 3;
    char low = ((y & 0b00111000) << 2) | x;
    char high = (SCREEN_ADDR >> 8) | ((y & 0b11000000) >> 3) | (y & 0b00000111);

    for (int i = 0; i < 8; i++) {
        *(char*)((high << 8) | low) = tile[i];
        high++;
    }
}

char is_allowed(int x, int y) {
    char tile = map[y][x];
    for (int i = 0; i < allowed_tile_count; i++) {
        if (allowed_tiles[i] == tile) {
            return 1;
        }
    }
    return 0;
}

void move_player(Player *p, int x, int y) {
    char nx = p->x + x;
    char ny = p->y + y;

    if (is_allowed(nx, ny) && is_allowed(nx + 1, ny) && is_allowed(nx, ny + 1) && is_allowed(nx + 1, ny + 1)) {
        p->previous_x = p->x;
        p->previous_y = p->y;
        p->x = nx;
        p->y = ny;
        p->needs_update = 1;
    }
}

void draw_player(Player *p) {
    // TODO: Draw only changed background tiles
    draw_tile(map[p->previous_y][p->previous_x], p->previous_x, p->previous_y);
    draw_tile(map[p->previous_y][p->previous_x + 1], p->previous_x + 1, p->previous_y);
    draw_tile(map[p->previous_y + 1][p->previous_x], p->previous_x, p->previous_y + 1);
    draw_tile(map[p->previous_y + 1][p->previous_x + 1], p->previous_x + 1, p->previous_y + 1);

    draw_tile(1, p->x, p->y);
    draw_tile(2, p->x + 1, p->y);
    draw_tile(33, p->x, p->y + 1);
    draw_tile(34, p->x + 1, p->y + 1);
}

int main() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 32; j++) {
            draw_tile(map[i][j], j, i);
        }
    }

    Player player = { 20, 17, 1 };

    while (1) {
        if (player.needs_update) {
            draw_player(&player);
            player.needs_update = 0;
        }

        in_wait_key();

        char c = in_inkey();
        if (c == KEY_LEFT) {
            move_player(&player, -1, 0);
        } else if (c == KEY_RIGHT) {
            move_player(&player, 1, 0);
        } else if (c == KEY_DOWN) {
            move_player(&player, 0, 1);
        } else if (c == KEY_UP) {
            move_player(&player, 0, -1);
        }

        in_wait_nokey();
    }
}
