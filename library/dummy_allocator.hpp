#ifndef DUMMY_ALLOCATOR_HPP
#define DUMMY_ALLOCATOR_HPP

#include <stddef.h>
#include <new>
#include <iostream>

namespace gc{

template <typename T>
class dummy_allocator
{
public:
    typedef size_t     size_type;
    typedef ptrdiff_t  difference_type;
    typedef T*       pointer;
    typedef const T* const_pointer;
    typedef T&       reference;
    typedef const T& const_reference;
    typedef T        value_type;

    template<typename U>
    struct rebind {
        typedef dummy_allocator<U> other;
    };

    dummy_allocator() throw(){};
    dummy_allocator(const dummy_allocator&) throw(){};

    template <typename U>
    dummy_allocator(const dummy_allocator<U>&) throw(){};

    ~dummy_allocator() throw(){};

    pointer address(reference x) const;
    const_pointer address(const_reference x) const;

    pointer allocate(size_type n, const void * = 0);

    void deallocate(pointer p, size_type n);

    size_type max_size() const throw();

    void construct(pointer p, const_reference val);

    void destroy(pointer p);
};

// definitions
template <typename T> typename dummy_allocator<T>::pointer dummy_allocator<T>::address(reference x) const
{
    std::cout << "address" << std::endl;
    return(&x);
}

template <typename T> typename dummy_allocator<T>::const_pointer dummy_allocator<T>::address(const_reference x) const
{
    std::cout << "address" << std::endl;
    return(&x);
}

template <typename T> typename dummy_allocator<T>::size_type dummy_allocator<T>::max_size() const throw()
{
    std::cout << "max_size" << std::endl;
    return size_t(-1) / sizeof(T);
}

template <typename T> typename dummy_allocator<T>::pointer dummy_allocator<T>::allocate(size_type n, const void *)
{
    std::cout << "allocate" << std::endl;
    if (n > this->max_size())
        std::__throw_bad_alloc();

    return(static_cast<pointer>(::operator new(n * sizeof(T))));
}

template <typename T> void dummy_allocator<T>::deallocate(pointer p, size_type n)
{
    std::cout << "deallocate" << std::endl;
    ::operator delete(p);
}

template <typename T> void dummy_allocator<T>::construct(pointer p, const_reference val)
{
    std::cout << "construct" << std::endl;

    ::new(static_cast<void *>(p)) T(val);
}

template <typename T> void dummy_allocator<T>::destroy(pointer p)
{
    std::cout << "destroy" << std::endl;

    p->~T();
}

} // namespace

#endif // DUMMY_ALLOCATOR_HPP
