/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:49:13 by thverney          #+#    #+#             */
/*   Updated: 2021/02/10 20:23:29 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <algorithm>
# include "../../iterators/random_access_iterator.hpp"
# include "../../iterators/rev_random_access_iterator.hpp"
# include "../../iterators/checkers.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:
			typedef T 											value_type;	
			typedef T& 											reference;
			typedef T const 									&const_reference;
			typedef T* 											pointer;
			typedef T const 									*const_pointer;
			typedef std::ptrdiff_t 								difference_type;
			typedef unsigned int 								size_type;
			typedef Alloc										allocator_type;

			typedef typename ft::random_access_iterator<T, false>		iterator;
			typedef typename ft::random_access_iterator<T, true>		const_iterator;
			typedef typename ft::rev_random_access_iterator<T, false>	reverse_iterator;
			typedef typename ft::rev_random_access_iterator<T, true>	const_reverse_iterator;
		
		private:
			pointer 		_ptr;
			size_t 			_size_value;
			size_t 			_allocated_size;
			allocator_type 	_allocator;
		
		public:

		/*
			   ___    _____    ___     ___     ___    _____    ___     ___     ___   
			  |_ _|  |_   _|  | __|   | _ \   /   \  |_   _|  / _ \   | _ \   / __|  
			   | |     | |    | _|    |   /   | - |    | |   | (_) |  |   /   \__ \  
			  |___|   _|_|_   |___|   |_|_\   |_|_|   _|_|_   \___/   |_|_\   |___/  
			_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
			"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'                               
		*/
			iterator begin() 									{ return iterator(_ptr); };
			const_iterator begin() 						const 	{ return const_iterator(_ptr); };
			iterator end() 										{ return iterator(_ptr + _size_value); };
			const_iterator end() 						const 	{ return const_iterator(_ptr + _size_value); };
			reverse_iterator rbegin() 							{ return reverse_iterator(_ptr + _size_value - 1); };
			const_reverse_iterator rbegin() 			const 	{ return const_reverse_iterator(_ptr + _size_value - 1); };
			reverse_iterator rend() 							{ return reverse_iterator(_ptr - 1); };
			const_reverse_iterator rend() 				const 	{ return const_reverse_iterator(_ptr - 1); };

		/*
		  	   ___     ___      ___    ___     ___     ___    _____  __   __ 
			  / __|   /   \    | _ \  /   \   / __|   |_ _|  |_   _| \ \ / / 
			 | (__    | - |    |  _/  | - |  | (__     | |     | |    \ V /  
			  \___|   |_|_|   _|_|_   |_|_|   \___|   |___|   _|_|_   _|_|_  
			_|"""""|_|"""""|_| """ |_|"""""|_|"""""|_|"""""|_|"""""|_| """ | 
			"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
		*/
			size_type size() 							const	{ return (_size_value); };
			size_type max_size() 						const 	{ return (std::numeric_limits<difference_type>::max()); };
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size_value)
					erase(iterator(_ptr + n), end());
				if (n > _size_value)
					insert(end(), n - _size_value, val);
				_size_value = n;
			};
			size_type capacity() 						const 	{ return (_allocated_size); };
			bool empty() 								const	{ return (!(_size_value)); };
			void reserve (size_type n)
			{
				pointer			new_ptr;
				allocator_type	alloc_type;
				size_type		to_allocate;
			
				if (n > _allocated_size)
				{
					to_allocate = _allocated_size ? _allocated_size : 32;
					while (to_allocate < n)
						to_allocate *= 2;
					new_ptr = alloc_type.allocate(to_allocate);
					for (size_type i = 0; i < _size_value; i++)
					{
						alloc_type.construct(&new_ptr[i], _ptr[i]);
						alloc_type.destroy(&_ptr[i]);
					}
					alloc_type.deallocate(_ptr, _allocated_size);
					_ptr = new_ptr;
					_allocated_size = to_allocate;
				}
			};

			/*
				   ___     _       ___   __  __    ___    _  _    _____             ___     ___     ___     ___     ___     ___   
				  | __|   | |     | __| |  \/  |  | __|  | \| |  |_   _|           /   \   / __|   / __|   | __|   / __|   / __|  
				  | _|    | |__   | _|  | |\/| |  | _|   | .` |    | |             | - |  | (__   | (__    | _|    \__ \   \__ \  
				  |___|   |____|  |___| |_|__|_|  |___|  |_|\_|   _|_|_            |_|_|   \___|   \___|   |___|   |___/   |___/  
				_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
				"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
			*/
			reference operator[] (size_type n)					{ return (_ptr[n]); };
			const_reference operator[] (size_type n) 	const 	{ return (_ptr[n]); };
			reference at (size_type n)
			{
				if (n >= _size_value && n >= 0)
					throw std::out_of_range("Index out of range");
				return (_ptr[n]);
			};
			const_reference at (size_type n) const
			{
				if (n >= _size_value && n >= 0)
					throw std::out_of_range("Index out of range");
				return (_ptr[n]);
			};
			reference front() 										{ return (_ptr[0]); };
			const_reference front() 					const		{ return (_ptr[0]); };
			reference back()										{ return (_ptr[_size_value -1]); };
			const_reference back() 						const		{ return (_ptr[_size_value -1]); };;

			/*
				 __  __    ___     ___     ___      ___    ___     ___     ___     ___   
				|  \/  |  / _ \   |   \   |_ _|    | __|  |_ _|   | __|   | _ \   / __|  
				| |\/| | | (_) |  | |) |   | |     | _|    | |    | _|    |   /   \__ \  
				|_|__|_|  \___/   |___/   |___|   _|_|_   |___|   |___|   |_|_\   |___/  
				_|"""""|_|"""""|_|"""""|_|"""""|_| """ |_|"""""|_|"""""|_|"""""|_|"""""| 
				"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
			*/
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last),
					typename ft::enable_if<ft::is_input_iterator<InputIT>::value, InputIT>::void_t)
			{
				this->~vector();
				insert(begin(), first, last);
			};
			void assign (size_type n, const value_type& val)
			{
				this->~vector();
				insert(begin(), n, val);
			};
			void push_back (const value_type& val) 									{ insert(end(), val); };
			void pop_back()															{ erase(end() - 1); };
			iterator insert (iterator position, const value_type& val) 
			{
				insert(position, 1, val);
				return (position);

			};
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type		new_info = position._ptr - _ptr;
				allocator_type	alloc_type;

				reserve(_size_value + n);

				for (size_type i = _size_value - 1; i > new_info - 1; i--)
				{
					alloc_type.construct(&_ptr[i + n], _ptr[i]);
					alloc_type.destroy(&_ptr[i]);
				}
				for (size_type k = 0; k < n; k++)
					alloc_type.construct(&_ptr[k + new_info], val);
				_size_value += n;
			};
			void insert(iterator position, iterator first, iterator last)
			{
				size_type		n = last._ptr - first._ptr;
				size_type		new_info = position._ptr - _ptr;
				allocator_type	alloc_type;

				reserve(_size_value + n);
				for (size_type i = _size_value - 1; i > new_info - 1; i--)
				{
					alloc_type.construct(&_ptr[i + n], _ptr[i]);
					alloc_type.destroy(&_ptr[i]);
				}
				for (size_type k = 0; k < n; k++)
					alloc_type.construct(&_ptr[k + new_info], *first++);
				_size_value += n;

			};
			iterator erase (iterator position)
			{
				return erase(position, position + 1);
			};
			iterator erase (iterator first, iterator last)
			{
				size_type		n = last._ptr - first._ptr;
				size_type		new_info = first._ptr - _ptr;
				allocator_type	alloc_type;

				for (size_type k = 0; k < n; k++)
					alloc_type.destroy(&_ptr[k]);
				for (size_type i = new_info; i < _size_value; i++)
				{
					alloc_type.construct(&_ptr[i], _ptr[i + n]);
					alloc_type.destroy(&_ptr[i + n]);
				}
				_size_value -= n;
				return (iterator(_ptr + new_info));
			};
			void swap (vector& x)
			{
				std::swap(_ptr, x._ptr);
				std::swap(_size_value, x._size_value);
				std::swap(_allocated_size, x._allocated_size);
			};
			void clear()
			{
				erase(begin(), end());
			};

		/*		 ██████╗ ██████╗ ██████╗ ██╗     ██╗███████╗███╗   ██╗    ███████╗ ██████╗ ██████╗ ███╗   ███╗
				██╔════╝██╔═══██╗██╔══██╗██║     ██║██╔════╝████╗  ██║    ██╔════╝██╔═══██╗██╔══██╗████╗ ████║
				██║     ██║   ██║██████╔╝██║     ██║█████╗  ██╔██╗ ██║    █████╗  ██║   ██║██████╔╝██╔████╔██║
				██║     ██║   ██║██╔═══╝ ██║     ██║██╔══╝  ██║╚██╗██║    ██╔══╝  ██║   ██║██╔══██╗██║╚██╔╝██║
				╚██████╗╚██████╔╝██║     ███████╗██║███████╗██║ ╚████║    ██║     ╚██████╔╝██║  ██║██║ ╚═╝ ██║
				 ╚═════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝╚══════╝╚═╝  ╚═══╝    ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝
                                                                                              
        */
		public:
			// Default constructor
			explicit vector(const allocator_type &allocator = allocator_type()) :
					_size_value(0), _allocated_size(0), _allocator(allocator)
			{
				_ptr = _allocator.allocate(0);
			};
			// Fill constructor
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) :
					_alloc(alloc), _size(n), _allocated_size(n)
			{
				_ptr = _alloc.allocate(_allocated_size);
				
				for (size_type i = 0; i < _size_value; ++i)
					_alloc.construct(&_ptr[i], val);
			}
			// Range of iterators contructor
			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<ft::is_input_iterator<InputIT>::value, InputIT>::void_t) :
						_allocator(alloc), _size_value(0)
				{
					InputIterator tmp(first);
					while (tmp++ != last)
						_size_value++;
					
					_allocated_size = _size_value;
					_ptr = _allocator.allocate(_allocated_size);

					for (int i = 0; first != last; ++first, ++i)
						_allocator.construct(&_ptr[i], *first);
				}
			// Copy constructor
			vector(const vector& x) : _allocated_size(0), _size_value(0), _ptr(NULL)
			{ 
				vector::insert(begin(), x.begin(), x.end());
			};
			// Affectation overload
			vector& operator=(const vector &affect)
			{
				clear();
				insert(begin(), affect.begin(), affect.end());
				return (*this);
			};
			// Deep destructor
			~vector()
			{
				for (iterator it = begin(); it != end(); ++it)
					_alloc.destroy(&(*it));
				_alloc.deallocate(_vector, _capacity);
			}	
	};
	template <class T>
	bool operator==(const vector<T>& a, const vector<T>& b)
	{
		if (a.size() != b.size())
			return (false);
		for (unsigned int i = 0; i < a.size(); i++)
			if (a[i] != b[i])
				return (false);
		return (true);
	}

	template <class T>
	bool operator!=(const vector<T>& a, const vector<T>& b)
	{
		return (!(a == b));
	}

	template <class T>
	bool operator<(const vector<T>& a, const vector<T>& b)
	{
		size_t		n;

		n = a.size() > b.size() ? b.size() : a.size;
		for (typename vector<T>::size_type i = 0; i < n; i++)
			if (a.at(i) != b.at(i))
				return(a.at(i) < b.at(i) ? true : false);
		return (a.size() < b.size());
	}

	template <class T>
	bool operator<=(const vector<T>& a, const vector<T>& b)
	{
		return (a < b || a == b);
	}

	template <class T>
	bool operator>(const vector<T>& a, const vector<T>& b)
	{
		return (!(a < b) && !(a == b));
	}

	template <class T>
	bool operator>=(const vector<T>& a, const vector<T>& b)
	{
		return (!(a < b));
	}
}

#endif