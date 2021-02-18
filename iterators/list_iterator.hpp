/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 05:12:55 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/18 10:23:13 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "is_const_it.hpp"
# include "checkers.hpp"

namespace ft
{
    template<typename T, typename Node, bool B>
	class list_iterator
	{
		public:

			typedef long int										        difference_type;
			typedef T												        value_type;
			typedef size_t											        size_type;
			
			typedef typename choose_if_const<B, T&, const T&>::_type		reference;
			typedef typename choose_if_const<B, T*, const T*>::_type		pointer;
			typedef Node*											        non_const_pointer;
            typedef std::input_iterator_tag 							    iterator_category;


			list_iterator(non_const_pointer node = 0) : _ptr(node) {}
			list_iterator(const list_iterator<T, Node, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			list_iterator& operator=(const list_iterator& affect)
			{
				if (this != &affect)
					_ptr = affect._ptr;
				return (*this);
			}
			~list_iterator() {}
			non_const_pointer	getNConstPtr()      const	{ return _ptr; }
			reference operator*()                   const   { return (_ptr->info); }
			pointer operator->()                    const   { return (_ptr); }
			list_iterator &operator++(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};
			list_iterator &operator--(void)
			{
				_ptr = _ptr->prev;
				return (*this);
			};
			list_iterator operator++(int)
			{
				list_iterator tmp(*this);
				operator++();
				return (tmp);
			};
			list_iterator operator--(int)
			{
				list_iterator tmp(*this);
				operator--();
				return (tmp);
			};
			bool operator==(const list_iterator& it) const	{ return (it._ptr == _ptr); }
			bool operator!=(const list_iterator& it) const	{ return (it._ptr != _ptr); }

			private:
				non_const_pointer	_ptr;
	};

    template<typename T, typename Node, bool B>
	class reverse_list_iterator
	{
		public:

			typedef long int										        difference_type;
			typedef T												        value_type;
			typedef size_t											        size_type;
			
			typedef typename choose_if_const<B, T&, const T&>::_type		reference;
			typedef typename choose_if_const<B, T*, const T*>::_type		pointer;
			typedef Node*											        non_const_pointer;
            typedef std::input_iterator_tag 							    iterator_category;

			reverse_list_iterator(non_const_pointer node = 0) : _ptr(node) {}
			reverse_list_iterator(const reverse_list_iterator<T, Node, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			reverse_list_iterator& operator=(const reverse_list_iterator& affect)
			{
				if (this != &affect)
					_ptr = affect._ptr;
				return (*this);
			}
			~reverse_list_iterator() {}
			non_const_pointer	getNConstPtr()      const	{ return _ptr; }
			reference operator*()                   const   { return (_ptr->info); }
			pointer operator->()                    const   { return (_ptr); }
			reverse_list_iterator& operator++()		
            {
                _ptr = _ptr->prev;
                return (*this); 
            }
			reverse_list_iterator operator++(int)		
            {
                reverse_list_iterator res(*this);
                ++(*this);
                return (res); 
            };
			reverse_list_iterator& operator--()		
            {
                _ptr = _ptr->next;
                return (*this); 
            }
			reverse_list_iterator operator--(int)		
            {
                reverse_list_iterator res(*this);
                --(*this);
                return (res); 
            };
			bool operator==(const reverse_list_iterator& it) const	{ return (it._ptr == _ptr); }
			bool operator!=(const reverse_list_iterator& it) const	{ return (it._ptr != _ptr); }

			private:
				non_const_pointer	_ptr;
	};
}

#endif