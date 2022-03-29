#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "linearRegression.hpp"

TEST_CASE("Testing Regression"){

    std::vector<Point> RegressionPoints;
    REQUIRE(RegressionPoints.size() == 0);

    SUBCASE("no points"){
        CHECK_THROWS(Regression(RegressionPoints));
    }

    SUBCASE("one point"){
        RegressionPoints.push_back({1.,2.});
        CHECK_THROWS(Regression(RegressionPoints));
    }

    SUBCASE("two points vertical"){
        RegressionPoints.push_back({1.,2.});
        RegressionPoints.push_back({1.,45.});
        CHECK_THROWS(Regression(RegressionPoints));
    }

    SUBCASE("two points"){
        RegressionPoints.push_back({1.,2.});
        RegressionPoints.push_back({2.,3.});
        Regression Reg{RegressionPoints};
        CHECK(Reg.fitA() == doctest::Approx(1));
        CHECK(Reg.fitB() == doctest::Approx(1));
        CHECK(Reg.fit().A == doctest::Approx(1));
        CHECK(Reg.fit().B == doctest::Approx(1));
        CHECK(Reg.getRegressionData().sum_x2_ == doctest::Approx(5));    
        CHECK(Reg.getRegressionData().sum_x_ == doctest::Approx(3));
        CHECK(Reg.getRegressionData().sum_xy_ == doctest::Approx(8));
        CHECK(Reg.getRegressionData().sum_y_ == doctest::Approx(5));    
    }

    SUBCASE("fit reale"){
        std::vector<Point> vect{{89.91,2.17},{80.21,1.82},{69.95,1.4},{60.01,0.97},{49.84,0.65}};
        Regression Reg{vect};
        //CHECK(Reg.fit().A == doctest::Approx(-1.31));
        //CHECK(Reg.fit().B == doctest::Approx(0.038));
    }

}
