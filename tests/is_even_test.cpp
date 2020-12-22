#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <is_even.hpp>

TEST_CASE("testing the is_even function") {
  CHECK(is_even(1) == false);
  CHECK(is_even(2) == true);
  CHECK(is_even(5) == false);
  CHECK(is_even(12) == true);
  CHECK(is_even(42) == true);
  CHECK(is_even(666) == true);
  CHECK(is_even(2137) == false);
}