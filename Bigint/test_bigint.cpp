#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bigint.h"

TEST_CASE("Testing Bigint addition") {
    Bigint a("12345678901234567890");
    Bigint b("98765432109876543210");


    Bigint result1 = a + b;
    CHECK(result1.to_string() == "111111111011111111100");

    Bigint c("110");
    Bigint x("10");

    Bigint result2 = c + x;

    CHECK(result2.to_string() == "120");

}
TEST_CASE("Testing Bigint string definition") {
    Bigint a("12345678901234567890");
    CHECK(a.to_string() == "12345678901234567890");
}

TEST_CASE("Testing Bigint int definition") {
    Bigint a(12345);
    CHECK(a.to_string() == "12345");
}

