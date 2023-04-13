#pragma once

#include <cstddef>

namespace mmpack {

// TODO: impl this

template<typename T, std::size_t alignment>
class aligned_allocator {
    public:
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef std::size_t size_type;
        typedef ptrdiff_t difference_type;

        template <typename U>
        struct rebind {
            typedef aligned_allocator<U, alignment> other;
        };

        aligned_allocator() = default;
        ~aligned_allocator();

        pointer address(reference x) const;
        const_pointer address(const_reference x) const;
        
        pointer allocate(size_type n, const void* hint = 0);
        void deallocate(pointer, size_type n);

        size_type max_size() const;
        
        template<class U, class... Args>
        void construct(U* p, Args&&... args);

        template<class U>
        void destroy(U* p);

    private:     
};


} // mmpack
