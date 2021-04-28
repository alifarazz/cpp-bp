#include <catch2/catch.hpp>

#include <main.hh>


TEST_CASE("Quick check", "[main]")
{
  float mean = 2.0;
  REQUIRE(mean == 2.0);
  // CHECK(false);
}
