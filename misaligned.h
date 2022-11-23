#ifndef _MISALIGNED_H_
#define _MISALIGNED_H_

#include <iostream>
#include <string.h>

static const char* majorColor[] = {"White ", "Red   ", "Black ", "Yellow", "Violet"};
static const char* minorColor[] = {"Blue  ", "Orange", "Green ", "Brown ", "Slate "};
static const char separator[] = " | ";
static const int MAXSINGLENUMBER    = 9;
static const int MAXINDEXDIGITCOUNT = 2;
static const int FIXEDSTRINGSIZE    = MAXINDEXDIGITCOUNT + strlen(separator)*2 + \
                                      strlen(majorColor[0]) + strlen(minorColor[0]);

std::string indexToColorPair(int majorColorIndex, int minorColorIndex);

#endif // _MISALIGNED_H_