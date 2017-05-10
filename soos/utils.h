//
// Created by Jfm Meyers on 5/9/17.
//
#ifndef HORIZONSCREEN_UTILS_H
#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <sys/stat.h>
#include <sys/types.h>
#if __APPLE__
#include <malloc/malloc.h>
#else
#include <malloc.h>
#endif
#include <errno.h>
#include <stdarg.h>
#include <fcntl.h>
#ifndef WIN32
#include <arpa/inet.h>
#include <netdb.h>
typedef int SOCKET;
typedef struct pollfd WSAPOLLFD;
#endif
#include <poll.h>
#include "inet_pton.h"
#include "tga/targa.h"
#include <turbojpeg.h>
#include "ctrufont_bin.h"
void drawtext(char *wat, int sx, int sy, int color, int scx, int scy);
SDL_Texture *font;
SDL_Window *win;
SDL_Renderer *rendertop;
SDL_Texture *tex[2];
SDL_Surface *screens[2];

#endif //HORIZONSCREEN_UTILS_H
