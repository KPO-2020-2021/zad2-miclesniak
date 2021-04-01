#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

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

TEST_CASE("Test WyrazenieZesp dodawanie") {
    WyrazenieZesp x;
    LZespolona y,z;
    
    x.Arg1.re = 2;
    x.Arg1.im = 2;
    
    x.Op = Op_Dodaj;

    x.Arg2.re = 4;
    x.Arg2.im = -2;

    y.re = 6;
    y.im = 0;

    z= x.Oblicz();
    CHECK( z == y);
}

TEST_CASE("Test WyrazenieZesp odejmnowanie") {
    WyrazenieZesp x;
    LZespolona y,z;
    
    x.Arg1.re = 5;
    x.Arg1.im = 7;
    
    x.Op = Op_Odejmij;

    x.Arg2.re = 4;
    x.Arg2.im = -2;

    y.re = 1;
    y.im = 9;

    z= x.Oblicz();
    CHECK(z == y);
}

TEST_CASE("Test WyrazenieZesp mnozenie") {
    WyrazenieZesp x;
    LZespolona y,z;
    
    x.Arg1.re = 3;
    x.Arg1.im = 2;
    
    x.Op = Op_Mnoz;

    x.Arg2.re = 4;
    x.Arg2.im = -2;

    y.re = 16;
    y.im = 2;

    z= x.Oblicz();
    CHECK(z == y);
}

TEST_CASE("Test WyrazenieZesp dzielenie") {
    WyrazenieZesp x;
    LZespolona y,z;
    
    x.Arg1.re = 1;
    x.Arg1.im = 8;
    
    x.Op = Op_Dziel;

    x.Arg2.re = 2;
    x.Arg2.im = 3;

    y.re = 2;
    y.im = 1;

    z = x.Oblicz();
    CHECK(z == y);
}