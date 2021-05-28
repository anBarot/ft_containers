#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <utility>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>> 
	class Map
	{
		public :
			class	value_compare; 
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef 										iterator;
			typedef 										const_iterator;
			typedef 										reverse_iterator;
			typedef 										const_reverse_iterator;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;

		private :
			pointer	_pdata;
			size_t	_size;

		public :
			// Coplien
			explicit Map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			template <class InputIterator>
  			Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			Map(const map &x);
			map &operator=(const map &x);
			~Map();

			// Iterator
			iterator begin();
			const_iterator begin() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
			
			// Getters
			mapped_type& at(const key_type& k);
			const mapped_type& at(const key_type& k) const;
			size_type size() const;
			size_type count(const key_type& k) const;
			bool empty() const;
			pair<iterator,iterator>             equal_range (const key_type& k);
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			allocator_type get_allocator() const;
			key_compare key_comp() const { return(Compare); };
			size_type max_size() const;
			mapped_type& operator[](const key_type &k);
			value_compare value_comp() const;

			// Setters
			void clear();
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);
			pair<iterator, bool> insert(const value_type &val);
			iterator insert(iterator position, const value_type &val);
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last);

			// Other member functions
			void swap (map& x);
	};
}

template<class Key, class T, class Compare, class Alloc> 
class ft::Map<Key, T, Compare, Alloc>::value_compare
{
	public :
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}

	public:
		bool operator() (const value_type& x, const value_type& y) const
		{
		  return comp(x.first, y.first);
		}
}

#endif // MAP_HPP
