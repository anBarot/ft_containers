#if !defined(ITERATOR_TRAITS_HPP)
#define ITERATOR_TRAITS_HPP

template <class Iterator>
class iterator_traits
{
    public :
        typedef difference_type;
        typedef value_type;
        typedef pointer;
        typedef reference;
        typedef iterator_category;
}

template <class T>
class iterator_traits<T*>
{ 
    public :
        typedef difference_type;
        typedef value_type ;
        typedef pointer ;
        typedef reference ;		
        typedef iterator_category;
}

template <class T>
class iterator_traits<const T*>
{
    public :
        typedef difference_type;
        typedef value_type ;
        typedef pointer ;
        typedef reference ;
        typedef iterator_category;
}

#endif