/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:31 by thverney          #+#    #+#             */
/*   Updated: 2021/02/08 17:09:44 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "is_const_it.hpp"
# include "reverse_bidirectional_iterator.hpp"

namespace ft
{
	template<typename T, bool B>
	class bidirectional_iterator
	{
		public:

			typedef long int		difference_type;
			typedef T				value_type;
			typedef size_t			size_type;

			typedef typename is_it_const<B, T&, const T&>::_type		reference;
			typedef typename is_it_const<B, T*, const T*>::_type		pointer;
			typedef T*													non_const_pointer;

			bidirectional_iterator(non_const_pointer val = 0) : _ptr(val) {}
			bidirectional_iterator(const bidirectional_tionaliterator<T, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			bidirectional_iterator(const ft::reverse_bidirectional_iterator<T, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			bidirectional_iterator& operator=(const bidirectional_iterator& affect)
			{
				if (this != &affect)
					_ptr = affect._ptr;
				return (*this);
			}
			~bidirectional_iterator() {}
			
			non_const_pointer	getNConstPtr() const						{ return _ptr; }
			bool operator==(const bidirectional_iterator& it) const	{ return (it._ptr == _ptr); }
			bool operator!=(const bidirectional_iterator& it) const	{ return (it._ptr != _ptr); }
			reference operator*()									{ return (*_ptr); }
			pointer operator->() const								{ return (_ptr); }
			bidirectional_iterator& operator++()					{ ++_ptr; return (*this); }
			bidirectional_iterator operator++(int)					{ bidirectional_iterator ret(*this); ++(*this); return (ret); };
			bidirectional_iterator& operator--()					{ --_ptr; return (*this); }
			bidirectional_iterator operator--(int)					{ bidirectional_iterator ret(*this); --(*this); return (ret); };
			
		protected:
			non_const_pointer	_ptr;
	};
}

#endif