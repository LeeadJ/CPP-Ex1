/* 
Testing File
*/
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>

TEST_CASE("Good input") { // 3 tests
    CHECK(mat(9, 7, '@', '-') == "@@@@@@@@@\n"
                                "@-------@\n"
                                "@-@@@@@-@\n"
                                "@-@---@-@\n"
                                "@-@@@@@-@\n"
                                "@-------@\n"
                                "@@@@@@@@@");

    CHECK(mat(3, 5, '$', '+') == "$$$\n"
                                "$+$\n"
                                "$+$\n"
                                "$+$\n"
                                "$$$");

    CHECK(mat(13, 5, '@', '-') == "@@@@@@@@@@@@@\n"
                                "@-----------@\n"
                                "@-@@@@@@@@@-@\n"
                                "@-----------@\n"
                                "@@@@@@@@@@@@@");                       
}

TEST_CASE("Even number input") { // 3 tests
    CHECK_THROWS(mat(1, 4, '$', '-')); // Even Rows
    CHECK_THROWS(mat(5, 2, '$', '-')); // Even Colunms
    CHECK_THROWS(mat(2, 2, '$', '-')); // Evan Colunms and Rows
}
TEST_CASE("Zero int input"){ // 3 tests
    CHECK_THROWS(mat(0, 5, '$', '-')); // Zero Columns
    CHECK_THROWS(mat(5, 0, '$', '-')); // Zero Rows
    CHECK_THROWS(mat(0, 0, '$', '-')); // Zero Columns and Rows
}
TEST_CASE("Negative input"){ // 3 tests
    CHECK_THROWS(mat(-2, 5, '$', '-')); // Negative value Columns
    CHECK_THROWS(mat(5, -2, '$', '-')); // Negative value Rows
    CHECK_THROWS(mat(-2, -6, '$', '-')); // Negative value Columns and Rows
}
TEST_CASE("One-Liners"){ // 3 tests
    CHECK(mat(1,1, '#', ')') == "#");
    CHECK(mat(1,3, '#', ')') == "#\n"
                                "#\n"
                                "#");
    CHECK(mat(3,1, '#', ')') == "###");
}
TEST_CASE("Missing Symbol"){ // 3 tests
    CHECK_THROWS(mat(-2, 5, ' ', '*')); // Missing value Columns
    CHECK_THROWS(mat(-2, 5, '*', ' ')); // Missing value Rows
    CHECK_THROWS(mat(-2, 5, ' ', ' ')); // Missing value Columns and Rows
}
TEST_CASE("In-Valid Symbol"){ // 2 tests
    CHECK_THROWS(mat(2, 5, '%', '\n')); // Missing value Rows
    CHECK_THROWS(mat(2, 5, '\n', '%')); // Missing value Rows
}


