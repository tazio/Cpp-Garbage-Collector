#ifndef DUMMY_ALLOCATOR_HPP
#define DUMMY_ALLOCATOR_HPP

using std::size_t;
using std::ptrdiff_t;

template <typename _Tp>
class dummy_allocator
{
public:
    typedef size_t     size_type;
    typedef ptrdiff_t  difference_type;
    typedef _Tp*       pointer;
    typedef const _Tp* const_pointer;
    typedef _Tp&       reference;
    typedef const _Tp& const_reference;
    typedef _Tp        value_type;

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

    pointer allocate(size_type n, dummy_allocator<void>::const_pointer hint=0);

    void deallocate(pointer p, size_type n);

    size_type max_size() const throw();

    void construct(pointer p, const_reference val);

    void destroy(pointer p);
};

// definitions
template <typename _Tp> dummy_allocator<_Tp>::pointer dummy_allocator<_Tp>::address(reference x) const
{
    return(&x);
}

template <typename _Tp> dummy_allocator<_Tp>::const_pointer dummy_allocator<_Tp>::address(const_reference x) const
{
    return(&x);
}

template <typename _Tp> dummy_allocator<_Tp>::size_type dummy_allocator<_Tp>::max_size() const throw()
{
    return size_t(-1) / sizeof(_Tp);
}


// memory managment
template <typename _Tp> dummy_allocator<_Tp>::pointer dummy_allocator<_Tp>::allocate(size_type n, dummy_allocator<void>::const_pointer hint)
{
    if (n > this->max_size())
        std::__throw_bad_alloc();

    return( static_cast<pointer>(::operator new(n * sizeof(_Tp))) );
}

template <typename _Tp> void dummy_allocator<_Tp>::deallocate(pointer p, size_type n)
{
    ::operator delete(p);
}

template <typename _Tp> void dummy_allocator<_Tp>::construct(pointer p, const_reference val)
{
    ::new(static_cast<void *>(p)) _Tp(val);
}

template <typename _Tp> void dummy_allocator<_Tp>::destroy(pointer p)
{
    p->~Tp();
}

#endif // DUMMY_ALLOCATOR_HPP
