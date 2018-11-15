#include "catch.hpp"
#include "../include/js/Context.hpp"

TEST_CASE("js::Context") {
    js::Context context;

    SECTION("Context() Make sure that construction worked correctly") {
        REQUIRE(context.getContext() != nullptr);
        duk_eval_string(context.getContext(), "1+2");
        REQUIRE(duk_get_int(context.getContext(), -1) == 3);
    }

    SECTION("getContext()") {
        REQUIRE(context.getContext() != nullptr);
    }

    SECTION("evalNoResult()") {
        // TODO improve
        REQUIRE_THROWS(context.evalNoResult("a+b"));

    }


}