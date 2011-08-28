#ifndef __UTILITIES_HPP
#define __UTILITIES_HPP

#if __GNUC__ < 4
#warning "pippip"
#endif

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
