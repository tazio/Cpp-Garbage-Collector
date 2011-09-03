#include <iostream>

#include "library/utilities.hpp"
#include "library/smart_pointers.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test
#include <boost/test/included/unit_test.hpp>


class test_obj
{
	int a;
	double b;
	double c;
	double d;
public:
	test_obj(int x):a(x) { std::cout << "Test Object Built!" << std::endl; }
	test_obj(int x, double y, double t, double z):a(x),b(y),c(t),d(z) { std::cout << "Test Object Built with multiple arguments!" << std::endl; }
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

using namespace gc;

BOOST_AUTO_TEST_SUITE ( smart_pointer_interface )

BOOST_AUTO_TEST_CASE ( smart_p_construction )
{
	smart_pointer<test_obj> c(43);
	smart_pointer<test_obj> H(22,2.0,3.5,9.9);
	smart_pointer<double> d(3.45);
	smart_pointer<char> e('c');

	std::cout << "Pointed address: " << d << std::endl;
}

BOOST_AUTO_TEST_CASE ( smart_pointer_asterisk)
{
	smart_pointer<int> c(12);

	BOOST_CHECK( *c == 12 );

	smart_pointer<test_obj> b(43);
	test_obj d(43);

	BOOST_CHECK ( b->getValue() == 43 );
	BOOST_CHECK ( *b == d );
}

BOOST_AUTO_TEST_CASE ( smart_pointers_and_inheritance )
{
	smart_pointer<son_obj> son ( 1.0, 1.0, 22,2.0,3.5,9.9);
	smart_pointer<test_obj> father ( 22,2.0,3.5,9.9 );

	BOOST_CHECK ( son->tester() == true );
	BOOST_CHECK ( father->tester() == false );
}


BOOST_AUTO_TEST_SUITE_END()

