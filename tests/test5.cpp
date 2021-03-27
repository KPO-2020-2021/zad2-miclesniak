#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona ilorazu"){
    LZespolona x,y,z;

    x.re = 1;
    x.im = 8;

    y.re = 2;
    y.im = 3;

    z.re = 2;
    z.im = 1;

    CHECK(x/y == z); 
}