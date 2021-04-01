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

TEST_CASE("Test LZespolona ilorazu 2"){
    LZespolona x,y,z;

    x.re = 1;
    x.im = 8;

    y.re = 2;
    y.im = 3;

    z.re = 2;
    z.im = 1;

    CHECK((x /= y) == z); 
}

TEST_CASE("Test wypisywania LZespolona"){
    std::stringstream os;
    LZespolona x;
    x.re = 2.3;
    x.im = 3.7;

    os<<x;
    CHECK_EQ("(2.3+3.7i)", os.str());
}

TEST_CASE("Test wypisywania LZespolona 2"){
    std::stringstream os;
    LZespolona x;
    x.re = 7;
    x.im = -2;

    os<<x;
    CHECK_EQ("(7-2i)", os.str());
}

TEST_CASE("Test wczytywanie LZespolona "){
    std::stringstream is;
    LZespolona x,y;
    is<<"(4+3.1i)";
    is>>x;

    y.re = 4;
    y.im = 3.1;
    CHECK_EQ(x,y);
}