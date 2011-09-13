#ifndef TEST__SMART_POINTERS_HPP
#define TEST__SMART_POINTERS_HPP

/**

	Copyright (C) 2011 Tazio Ceri

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <boost/test/included/unit_test.hpp>
#include "testmocks.hpp"
#include "../library/smart_pointers.hpp"


BOOST_AUTO_TEST_CASE ( smart_p_construction )
{
	gc::smart_pointer<test_obj> c(43);
	gc::smart_pointer<test_obj> H(22,2.0,3.5,9.9);
	gc::smart_pointer<double> d(3.45);
	gc::smart_pointer<char> e('c');

	std::cout << "Pointed address: " << d << std::endl;
}

BOOST_AUTO_TEST_CASE ( smart_pointer_asterisk)
{
	std::cout << "smart_pointers_and_asterisk" << std::endl;
	gc::smart_pointer<int> c(12);

	BOOST_CHECK( *c == 12 );

	gc::smart_pointer<test_obj> b(43);
	test_obj d(43);

	BOOST_CHECK ( b->getValue() == 43 );
	BOOST_CHECK ( *b == d );
}

BOOST_AUTO_TEST_CASE ( smart_pointers_and_inheritance )
{
	std::cout << "smart_pointers_and_inheritance" << std::endl;
	gc::smart_pointer<son_obj> son ( 1.0, 1.0, 22,2.0,3.5,9.9);
	gc::smart_pointer<test_obj> father ( 22,2.0,3.5,9.9 );

	BOOST_CHECK ( son->tester() == true );
	BOOST_CHECK ( father->tester() == false );
}

#endif
