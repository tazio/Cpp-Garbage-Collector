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

#ifndef __UTILITIES_HPP
#define __UTILITIES_HPP

#if __GNUC__ < 4 || ( __GNUC__ < 5 &&__GNUC_MINOR < 6 ) //nullptr is supported in gcc 4.6

const class
{
public:
	template<class T> operator T*() const { return 0; }            // pointer...
	template<class C, class T> operator T C::*() const  { return 0; }
private:
	void operator&() const;    // whose address can't be taken
} nullptr = {};              // and whose name is nullptr

#endif

//Check the no-throw contract at debug time
#ifdef EXCEPTION_DEBUG
	#define THROW_CHECK() throw()
#else
	#define THROW_CHECK()
#endif

#endif
