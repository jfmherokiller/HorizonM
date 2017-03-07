#pragma once

#include <3ds.h>


typedef struct
{
    u32 ani;
    u8 r[32];
    u8 g[32];
    u8 b[32];
} RGBLedPattern;

extern RGBLedPattern pat;


void PatApply();
void PatTrigger();
void PatStay(u32 col);
void PatPulse(u32 col);
void setrave();
void makerave();
