#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona odejmowanie"){
    LZespolona x,y,z;

    x.re = 5;
    x.im = 10;

    y.re = 2;
    y.im = 7;

    z.re = 3;
    z.im = 3;

    CHECK(x-y == z); 
}