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

#ifndef __SMART_POINTERS_HPP
#define __SMART_POINTERS_HPP
#include "utilities.hpp"

#include <ostream>
#include <utility>

namespace gc
{
	// Here we have three kinds of smart pointers
	// 1) smart pointer to an element
	// 2) smart pointer to an array
	// 3) smart pointer to an element in an array
	template<class T>
	class smart_pointer
	{
		T* p;
	public:
		typedef T element_type;

		template<typename... Args>
		smart_pointer(Args&& ... ca )
		{
			p = new T( std::forward<Args>(ca)... ); //! @todo allocator needed
		}

		smart_pointer(smart_pointer&& p);
		smart_pointer(T* pointer): p(pointer) THROW_CHECK() {}

		template<class Y> smart_pointer(smart_pointer<Y> const & r);

		~smart_pointer() THROW_CHECK()
		{
			delete p; //! @todo allocator needed
		}

		smart_pointer & operator=(smart_pointer const & r);
		template<class Y> smart_pointer& operator=(smart_pointer<Y> const & r);
		smart_pointer & operator=(T * r);

		void reset();
		void reset(T * r);

		T & operator*() THROW_CHECK() const { return *p; }
		T * operator->() THROW_CHECK() const  { return p; }
		T * get() THROW_CHECK() const { return p; }

		operator bool() THROW_CHECK() const { return p == nullptr; }

		void swap(smart_pointer& b) THROW_CHECK() { T* temp = p; p = b.p; b.p = p; }

		//Friends!
		template<class X, class U>
		friend bool operator==(smart_pointer<X> const & a, smart_pointer<U> const & b) THROW_CHECK();

		template<class X, class U>
		friend bool operator!=(smart_pointer<X> const & a, smart_pointer<U> const & b) THROW_CHECK();

		template<class X>
		friend bool operator==(smart_pointer<X> const & a, X * b) THROW_CHECK();

		template<class X>
		friend bool operator!=(smart_pointer<X> const & a, X * b) THROW_CHECK();

		template<class X>
		friend bool operator==(T * a, smart_pointer<X> const & b) THROW_CHECK();

		template<class X>
		friend bool operator!=(T * a, smart_pointer<X> const & b) THROW_CHECK();

		template<class X, class U>
		friend bool operator<(smart_pointer<X> const & a, smart_pointer<U> const & b) THROW_CHECK();

		template<class X>  friend  X * get_pointer(smart_pointer<X> const & p) THROW_CHECK();

		template<class X, class U>
		friend smart_pointer<T> static_pointer_cast(smart_pointer<U> const & r) THROW_CHECK();

		template<class X, class U>
		friend smart_pointer<X> const_pointer_cast(smart_pointer<U> const & r) THROW_CHECK();

		template<class X, class U>
		friend smart_pointer<X> dynamic_pointer_cast(smart_pointer<U> const & r) THROW_CHECK();

		template<class E, class X, class Y>
		friend std::basic_ostream<E, X> & operator<< (std::basic_ostream<E, X> & os, smart_pointer<Y> const & p);
	};

	template<class T, class U>
	bool operator==(smart_pointer<T> const & a, smart_pointer<U> const & b) THROW_CHECK() { return a.p == b.p; }

	template<class T, class U>
	bool operator!=(smart_pointer<T> const & a, smart_pointer<U> const & b) THROW_CHECK() { return a.p != b.p; }

	template<class T>
	bool operator==(smart_pointer<T> const & a, T * b) THROW_CHECK() { return a.p == b; }

	template<class T>
	bool operator!=(smart_pointer<T> const & a, T * b) THROW_CHECK() { return a.p != b; }

	template<class T>
	bool operator==(T * a, smart_pointer<T> const & b) THROW_CHECK() { a == b.p; }

	template<class T>
	bool operator!=(T * a, smart_pointer<T> const & b) THROW_CHECK() { a != b.p; }

	template<class T, class U>
	bool operator<(smart_pointer<T> const & a, smart_pointer<U> const & b) THROW_CHECK() { a.p < b.p; }

	//template<class T> void swap(smart_pointer<T> & a, smart_pointer<T> & b) THROW_CHECK(); // never throws

	template<class T> T * get_pointer(smart_pointer<T> const & p) THROW_CHECK() { return p.p; }

	template<class T, class U>
	smart_pointer<T> static_pointer_cast(smart_pointer<U> const & r) THROW_CHECK()
	{
		smart_pointer<T> ret ( static_cast<T> (r.p) );
		return ret;
	}

	template<class T, class U>
	smart_pointer<T> const_pointer_cast(smart_pointer<U> const & r) THROW_CHECK()
	{
		smart_pointer<T> ret ( const_cast<T> ( r.p ) );
		return ret;
	}

	template<class T, class U>
	smart_pointer<T> dynamic_pointer_cast(smart_pointer<U> const & r) THROW_CHECK()
	{
		smart_pointer<T> ret ( dynamic_cast<T>(r.p) );
		return ret;
	}

	template<class E, class T, class Y>
	std::basic_ostream<E, T> & operator<< (std::basic_ostream<E, T> & os, smart_pointer<Y> const & p)
	{
		os << p.p;
		return os;
	}
}

#endif
