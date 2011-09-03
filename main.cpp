#include <iostream>

#include "library/utilities.hpp"
#include "library/smart_pointers.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test
#include <boost/test/included/unit_test.hpp>


class prova
{
	int a;
public:
	prova(int x):a(x) {}
};

using namespace gc;

BOOST_AUTO_TEST_SUITE ( smart_pointer_interface )

BOOST_AUTO_TEST_CASE ( smart_p_construction )
{
	smart_pointer<prova> c(43);
}



BOOST_AUTO_TEST_SUITE_END()

