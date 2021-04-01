#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 3;
    x.im = 3;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 3"){
    LZespolona x,y;
    double t=3;

    x.re=1;
    x.im=1;

    y.re=0.3333;
    y.im=0.3333;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona sprzezenie") {
    LZespolona x,y;
    
    x.re = 2;
    x.im = 2;
 
    y.re = 2;
    y.im = -2;
    CHECK(x.Sprzezenie() == y);
}

TEST_CASE("Test LZespolona modul") {
    LZespolona x;
    double y = 8.0;
    
    x.re = 2;
    x.im = 2;
 
    CHECK(x.Modul2() == y);
}