#include "BracketContentParser.hpp"

#include "Error.hpp"
#include "Range.hpp"
#include "Token.hpp"

#include "catch.hpp"

TEST_CASE("BracketContentParser", "[Parser]")
{
  using namespace std::literals;
  using namespace cmake::language;

  SECTION("Parse")
  {
    SECTION("Classic case")
    {
      Parser<ElementType::BracketContent> parser(0);
      auto script = " comment \n comment ]]"sv;
      Range r{ script.begin(), script.end() };
      auto result = parser.Parse(r);
      REQUIRE(result);
      REQUIRE(result.value().range == Range{ r.begin, r.end - 2 });
    }

    SECTION("Classic case with \'=\'")
    {
      Parser<ElementType::BracketContent> parser(3);
      auto script = " comment \n comment ]===]"sv;
      Range r{ script.begin(), script.end() };
      auto result = parser.Parse(r);
      REQUIRE(result);
      REQUIRE(result.value().range == Range{ r.begin, r.end - 5 });
    }
  }

  SECTION("!Parse")
  {
    SECTION("Without closing bracket")
    {
      Parser<ElementType::BracketContent> parser(0);
      auto script = "test   "sv;
      Range r{ script.begin(), script.end() };
      auto result = parser.Parse(r);
      REQUIRE(!result);
    }

    SECTION("With closing bracket of different length")
    {
      Parser<ElementType::BracketContent> parser(0);
      auto script = "test ]=]"sv;
      Range r{ script.begin(), script.end() };
      auto result = parser.Parse(r);
      REQUIRE(!result);
    }
  }
}
