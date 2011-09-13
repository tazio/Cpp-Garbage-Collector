#ifndef __TESTMOCKS_HPP
#define __TESTMOCKS_HPP

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

#include <iostream>

class test_obj
{
	int a;
	double b;
	double c;
	double d;
public:
	test_obj() { std::cout << "Build with no args.." << std::endl; }
	test_obj(int x):a(x) { std::cout << "Test Object Built!" << std::endl; }
	test_obj(int x, double y, double t, double z):a(x),b(y),c(t),d(z) { std::cout << "Test Object Built with multiple arguments!" << std::endl; }
	test_obj(const test_obj& t):a(t.a),b(t.b), c(t.c), d(t.d) { std::cout << "Copy constructor for test_obj" << std::endl; }
	int getValue() const { return a; }
	bool operator==( const test_obj& b ) const { return a == b.a; }
	virtual bool tester() const { return  b == c == d;}
	virtual ~test_obj() throw() { std::cout << "Test object was destroyed!" << std::endl; }
};

class son_obj: test_obj
{
	double xx;
	double yy;
public:
	son_obj(double X, double Y, int x, double y, double t, double z): xx(X), yy(Y), test_obj(x,y,t,z) { std::cout << "Son object built!" << std::endl; }
	virtual bool tester() const { return xx == yy; }
	virtual ~son_obj() throw() { std::cout << "Son object destroyed!" << std::endl; }
};

#endif 
