#include <stdio.h>
#include <math.h>

struct Complex
{
    float x;
    float y;
} Complex;

float absComplex(Complex z)
{
    return sqrt((z.x * z.x) + (z.y * z.y));
}