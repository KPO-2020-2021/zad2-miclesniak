#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "Statystyki.hh"

TEST_CASE("Test LZespolona iloczynu"){
    LZespolona x,y,z;

    x.re = 3;
    x.im = 2;

    y.re = 2;
    y.im = 7;

    z.re = -8;
    z.im = 25;

    CHECK(x*y == z); 
}

TEST_CASE("Test LZespolona iloczyn 2"){
    LZespolona x,y,z;

    x.re = 2.5;
    x.im = 6.75;

    y.re = 2.3;
    y.im = 4.5;

    z.re = -24.625;
    z.im = 26.775; 

    CHECK(x*y == z); 
}

TEST_CASE("Test Statystka Procent"){
    stat x;
    x.l_poprawna = 4;
    x.l_niepoprawna = 6;

    double y = 40;
    CHECK(x.procent() == y);
}