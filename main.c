#include <stdio.h>
#include <input.h>
#include "data.h"
#include "map.h"

#define KEY_LEFT 0x8
#define KEY_RIGHT 0x9
#define KEY_DOWN 0xA
#define KEY_UP 0xB

typedef struct Player {
    char x, y;
    char needs_update;
    char previous_x, previous_y;
} Player;

char *attr = (char*)0x5800;

void draw_block(int index, int x, int y) {
    char *block = data[index];

    y <<= 3;
    char low = ((y & 0b00111000) << 2) | x;
    char high = 0x40 | ((y & 0b11000000) >> 3) | (y & 0b00000111);

    for (int i = 0; i < 8; i++) {
        *(char*)((high << 8) | low) = block[i];
        high++;
    }
}

void move_player(Player *p, int x, int y) {
    p->previous_x = p->x;
    p->previous_y = p->y;
    p->x += x;
    p->y += y;
    p->needs_update = 1;
}

void draw_player(Player *p) {
    // TODO: Draw only changed background tiles
    draw_block(map[p->previous_y][p->previous_x], p->previous_x, p->previous_y);
    draw_block(map[p->previous_y][p->previous_x + 1], p->previous_x + 1, p->previous_y);
    draw_block(map[p->previous_y + 1][p->previous_x], p->previous_x, p->previous_y + 1);
    draw_block(map[p->previous_y + 1][p->previous_x + 1], p->previous_x + 1, p->previous_y + 1);

    draw_block(1, p->x, p->y);
    draw_block(2, p->x + 1, p->y);
    draw_block(33, p->x, p->y + 1);
    draw_block(34, p->x + 1, p->y + 1);
}

int main() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 32; j++) {
            draw_block(map[i][j], j, i);
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
