/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bidirectional_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:38 by thverney          #+#    #+#             */
/*   Updated: 2021/02/08 16:43:00 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_BIDIRECTIONAL_ITERATOR_HPP
# define REVERSE_BIDIRECTIONAL_ITERATOR_HPP

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
			bidirectional_iterator(const bidirec_tionaliterator<T, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			bidirectional_iterator& operator=(const bidirectional_iterator& affect)
			{
				if (this != &affect)
					_ptr = affect._ptr;
				return (*this);
			}
			~bidirectional_iterator() {}
			
			nonConstPointer	getNConstPtr() const						{ return _ptr; }
			bool operator==(const bidirectional_iterator& it) const	{ return (it._ptr == _ptr); }
			bool operator!=(const bidirectional_iterator& it) const	{ return (it._ptr != _ptr); }
			reference operator*()									{ return (*_ptr); }
			pointer operator->() const								{ return (_ptr); }
			bidirectional_iterator& operator++()					{ ++_ptr; return (*this); }
			bidirectional_iterator operator++(int)					{ bidirectional_iterator ret(*this); ++(*this); return (ret); };
			bidirectional_iterator& operator--()					{ --_ptr; return (*this); }
			bidirectional_iterator operator--(int)					{ bidirectional_iterator ret(*this); --(*this); return (ret); };
			
		protected:
			nonConstPointer	_ptr;
	};
}

#endif