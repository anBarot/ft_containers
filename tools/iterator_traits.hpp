#if !defined(ITERATOR_TRAITS_HPP)
#define ITERATOR_TRAITS_HPP

namespace ft
{
    template <class T>
    class iterator_traits<T*>
    { 
        public :
            typedef typename T::value_type value_type;
            typedef typename T::difference_type difference_type;
            typedef typename T::iterator_category iterator_category;
            typedef typename T::pointer pointer;
            typedef typename T::reference reference;
    };
}

#endif
