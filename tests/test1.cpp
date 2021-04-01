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

TEST_CASE("test LZespolona Porównanie 3")
{
    LZespolona x,y;

    x.re = 2.99;
    x.im = 7;

    y.re = 3;
    y.im = 7;

    CHECK_FALSE(x == y);
}

TEST_CASE("test LZespolona Porównanie 4")
{
    LZespolona x,y;

    x.re = 1.0001;
    x.im = 6.9999;

    y.re = 1;
    y.im = 7;

    CHECK(x == y);
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

TEST_CASE("test LZespolona Suma 1 ")
{
    LZespolona x,y,z;

    x.re = 3;
    x.im = 7;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 3;
    z.im = 7;

    CHECK(x+y == z);
}

TEST_CASE("test LZespolona suma 2"){
    LZespolona x,y,z;

    x.re = 0.0009;
    x.im = 0.2;

    y.re = 0.0001;
    y.im = 0.54;

    z.re = 0.0010;
    z.im = 0.74;

    CHECK((x += y) == z);
}
