#define BOOST_TEST_MODULE My Test

#include <boost/test/included/unit_test.hpp>

#include <yagbe_core/yagbe_core.hpp>


BOOST_AUTO_TEST_CASE(FIRST_TEST) {
    BOOST_CHECK_EQUAL(yagbe::lib{}.foo(), 5);
}



