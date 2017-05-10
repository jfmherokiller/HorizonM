//
// Created by Jfm Meyers on 5/9/17.
//


#include "utils.h"

void drawtext(char *wat, int sx, int sy, int color, int scx, int scy) {
    if (color >> 24) {
        SDL_SetTextureAlphaMod(font, color >> 24);
    } else {
        SDL_SetTextureAlphaMod(font, 0xFF);
    }
    Uint8 red = (color & 0xFF);
    Uint8 green = (color >> 8) & 0xFF;
    Uint8 blue = (color >> 16) & 0xFF;

    SDL_SetTextureColorMod(font, red , green, blue);

    SDL_Rect dest;
    dest.w = scx * 8;
    dest.h = scy * 8;

    SDL_Rect src;
    src.w = 8;
    src.h = 8;

    //int i = 0;
    int x = sx;
    int y = sy;
    char c;

    while (y < 240) {
        while (x < 720) {
            c = *(wat++);

            if (!c) return;
            if (c == '\n') break;

            dest.x = x;
            dest.y = y;
            src.x = (c & 0xF) << 3;
            src.y = ((c >> 4) & 0xF) << 3;

            SDL_RenderCopyEx(rendertop, font, &src, &dest, 0.0, NULL, SDL_FLIP_NONE);

            x += dest.w;
        }

        x = sx;
        y += dest.h;
    }
}
