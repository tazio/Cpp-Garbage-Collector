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

/**
 *	@file allocators_test.hpp
 * 	@note This file is goint to be included for testing purposes only - no real program.
 */

#ifndef __ALLOCATORS_TEST_HPP
#define __ALLOCATORS_TEST_HPP

#include <vector>
#include <iostream>

#include "../library/dummy_allocator.hpp"
#include <boost/test/included/unit_test.hpp>
#include "testmocks.hpp"

BOOST_AUTO_TEST_CASE ( standard_vector )
{
	std::cout << "standard vector" << std::endl;
	std::vector<int, gc::dummy_allocator<int> > vec;

	std::vector<test_obj, gc::dummy_allocator<test_obj> > vecprova;

	for ( int i = 0; i < 12; ++i ) vec.push_back(i);

	BOOST_CHECK(vec[3] = 3);

	for ( int j = 0; j < 3; ++j ) vec.pop_back();

	test_obj t(2);
	for ( int k = 0; k < 5; ++k ) vecprova.push_back(t);

	BOOST_CHECK(vecprova[2] == t);
}



#endif
