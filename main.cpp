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

#include "library/utilities.hpp"
#include "library/smart_pointers.hpp"
#include "library/dummy_allocator.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test
#include <boost/test/included/unit_test.hpp>

//#include "test/testmocks.hpp"

using namespace gc;

BOOST_AUTO_TEST_SUITE ( cppgc )

#include "test/smart_pointers.hpp"

#include "test/allocators_test.hpp"

BOOST_AUTO_TEST_SUITE_END()

