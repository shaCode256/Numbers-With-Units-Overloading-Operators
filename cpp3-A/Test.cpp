/* 

 *
 * TEST FOR SNOWMAN.CPP
 *
 * AUTHOR: Shavit Luzon
 *
 * Date: 2021-04
 *

*/

 #include "NumberWithUnits.hpp"
#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "doctest.h"
#include <string>
// using namespace std;
using namespace ariel;

/* 
  Functions to check: all operations.
 */

 TEST_CASE("Checking the demo works as expected")
 {
     NumberWithUnits a{ 2, "km"}; // 2 kilometers
    // CHECK_EQ(  a ,  "2[km]");          // Check that Prints "2[km]".
    // CHECK_EQ( (cout << (-a)) , "-2[km]");       // Prints "-2[km]"
    // CHECK_EQ( (cout << (3 * a)) , "6[km]");    // Prints "6[km]"
     NumberWithUnits b{300, "m"}; // 300 meters
    // CHECK_EQ( (cout << (a + b)) , "2.3[km]");     // Prints "2.3[km]". Note: units are determined by first number (a).
    // CHECK_EQ( (cout <<(b - a)) , "-1700[m]");     // Prints "-1700[m]". Note: units are determined by first number (b).

   //cout << boolalpha;                                 // print booleans as strings from now on:
    CHECK_EQ (a < b, false);                           // Prints "false"
    CHECK_EQ (a < b, false);                          // Prints "false"
//    CHECK_EQ( (a == NumberWithUnits{2000, "m"}) , true); // Prints "true"

//     CHECK_EQ( (cout << a) , "700[kg]");                                // Prints "700[kg]"
//     CHECK_EQ (( cout<< (a += NumberWithUnits{1, "ton"})) , "1700[kg]"); // prints "1700[kg]"
//      CHECK_EQ (( cout << a ) , "1700[kg]");                     // Prints "1700[kg]". Note that a has changed.
 }

TEST_CASE(".."){
    NumberWithUnits a{ 2, "km"}; // 2 kilometers
    NumberWithUnits b{ 2, "km"}; // 2 kilometers
//     //CHECK_EQ( ( a == b )  , true);                     // Prints "true".
    CHECK_EQ (  a < b , false );                     // Prints "false".
    CHECK_EQ (  a > b , false );                     // Prints "false".
}

TEST_CASE("Check opeartors <, >"){
    NumberWithUnits a{ 4, "km"}; // 2 kilometers
    NumberWithUnits b{ 4, "km"}; // 2 kilometers
//     // CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
    CHECK_EQ ( a < b , false );                     // Prints "false".
    CHECK_EQ ( a > b , false );                     // Prints "false".
}

TEST_CASE("//"){
    NumberWithUnits a{ 6, "km"}; // 2 kilometers
    NumberWithUnits b{ 6, "km"}; // 2 kilometers
//    // CHECK_EQ (( ( a == b )  , true);                     // Prints "true".
     CHECK_EQ ( a < b , false);                     // Prints "false".
     CHECK_EQ (  a > b , false);                     // Prints "false".
}

TEST_CASE("Checking again"){
    NumberWithUnits a{ 8, "km"}; // 2 kilometers
    NumberWithUnits b{ 8, "km"}; // 2 kilometers
//    CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
     CHECK_EQ (  a< b , false);                     // Prints "false".
    CHECK_EQ ( a > b, false );                     // Prints "false".
}

TEST_CASE("Checks"){
    NumberWithUnits a{ 10, "km"}; // 2 kilometers
    NumberWithUnits b{ 8, "km"}; // 2 kilometers
//    CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
     CHECK_EQ (  a< b , false);                     // Prints "false".
    CHECK_EQ ( a > b, true );                     // Prints "false".
}

TEST_CASE("Check operators"){
    NumberWithUnits a{ 12, "km"}; // 2 kilometers
    NumberWithUnits b{ 8, "km"}; // 2 kilometers
//    CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
     CHECK_EQ (  a< b , false);                     // Prints "false".
    CHECK_EQ ( a > b, true );                     // Prints "false".
}

TEST_CASE("Check"){
    NumberWithUnits a{ 13, "km"}; // 2 kilometers
    NumberWithUnits b{ 8, "km"}; // 2 kilometers
//    CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
     CHECK_EQ (  a< b , false);                     // Prints "false".
    CHECK_EQ ( a > b, true );                     // Prints "false".
}

TEST_CASE("check"){
    NumberWithUnits a{ 16, "km"}; // 2 kilometers
    NumberWithUnits b{ 8, "km"}; // 2 kilometers
//    CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
     CHECK_EQ (  a< b , false);                     // Prints "false".
    CHECK_EQ ( a > b, true );                     // Prints "false".
}

TEST_CASE("Checking"){
    NumberWithUnits a{ 18, "km"}; // 2 kilometers
    NumberWithUnits b{ 8, "km"}; // 2 kilometers
//    CHECK (( cout << ( a == b ) ) == "true");                     // Prints "true".
     CHECK_EQ (  a< b , false);                     // Prints "false".
    CHECK_EQ ( a > b, true );                     // Prints "false".
}

