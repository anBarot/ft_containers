#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
    // class input_iterator_tag {};
    // class output_iterator_tag {};
    // class forward_iterator_tag       : public input_iterator_tag {};
    // class bidirectional_iterator_tag : public forward_iterator_tag {};
    // class random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class iterator_tag, class T>
    class iterator_traits
    {
        public :
            typedef std::ptrdiff_t  difference_type;
            typedef T               value_type;
            typedef T*              pointer;
            typedef T&              reference;
            typedef iterator_tag    iterator_category;
    };
}

#endif
