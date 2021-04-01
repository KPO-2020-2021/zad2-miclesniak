#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Porównanie")
{
    LZespolona x,y;

    x.re = 3;
    x.im = 7;

    y.re = 3;
    y.im = 7;

    CHECK(x == y);
}

TEST_CASE("test LZespolona Porównanie 2")
{
    LZespolona x,y;

    x.re = 3;
    x.im = 7;

    y.re = 7;
    y.im = 3;

    CHECK_FALSE(x == y);
}

TEST_CASE("test LZespolona Porównanie 2")
{
    LZespolona x,y;

    x.re = 2.999;
    x.im = 7;

    y.re = 3;
    y.im = 7;

    CHECK_FALSE(x == y);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma")
{
    LZespolona x,y,z;

    x.re = 3;
    x.im = 7;

    y.re = 7;
    y.im = 11;

    z.re = 10;
    z.im = 18;

    CHECK(x+y == z);
}

TEST_CASE("test LZespolona suma 2"){
    LZespolona x,y,z;

    x.re = 3;
    x.im = 1;

    y.re = 3;
    y.im = 5;

    z.re = 6;
    z.im = 6;

    CHECK((x += y) == z);
}
