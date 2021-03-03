/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:49:13 by thverney          #+#    #+#             */
/*   Updated: 2021/03/03 13:35:28 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <algorithm>
# include "../iterators/random_access_iterator.hpp"
# include "../iterators/rev_random_access_iterator.hpp"
# include "../iterators/checkers.hpp"

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
			typedef std::size_t 								size_type;
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
			size_type max_size() 						const 	{ return (allocator_type().max_size()); };
			void resize (size_type n, value_type val = value_type())
			{
				if (n > _allocated_size)
					ralloc(n);
				while (n > _size_value)
					push_back(val);
				while (n < _size_value)
					pop_back();
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
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				this->~vector();
				_ptr = _allocator.allocate(static_cast<size_type>(last - first));
				
				size_type i = 0;
				for (; first != last; ++i, ++first)
					_allocator.construct(&_ptr[i], *first);
				_size_value = i;
			};
			void assign (size_type n, const value_type& val)
			{
				this->~vector();
				_ptr = _allocator.allocate(n);
				
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&_ptr[i], val);
				_size_value = n;
			};
			void push_back (const value_type& val)
			{
				if (_size_value + 1 > _allocated_size)
					ralloc(!_allocated_size ? 1 : _allocated_size * 2);
				_allocator.construct(&_ptr[_size_value++], val);
			}
			void pop_back()															{ erase(end() - 1); };
			iterator insert (iterator position, const value_type& val) 
			{
				iterator it;
				size_t dist = ft::distance(this->begin(), position);

				if (_allocated_size < _size_value + 1) {
					this->reserve(_allocated_size * 2 + (_allocated_size == 0));
					position = this->begin() + dist;
				}
				it = this->end();
				while (it != position)
				{
					*it = *(it - 1);
					it--;
				}
				*it = val;
				_size_value++;
				return (position);
			};
			void insert (iterator position, size_type n, const value_type& val)
			{
				while (n--)
					position = insert(position, val);
			};
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				while (first != last)
				{
					position = insert(position, *first) + 1;
					++first;
				}
			};
			iterator erase (iterator position)
			{
				int i = 0;
				while (position + i != this->end())
				{
					if (position + i + 1 != this->end())
						*(position + i) = *(position + i + 1);
					i++;
				}
				if (position == this->end())
					return (this->end());
				_size_value--;
				return (position);
			};
			iterator erase (iterator first, iterator last)
			{
				iterator ret = first;
				while (first != last)
				{
					this->erase(first);
					last--;
				}
				return (ret);
			};
			void swap (vector& x)
			{
				std::swap(this->_ptr, x._ptr);
				std::swap(this->_size_value, x._size_value);
				std::swap(this->_allocated_size, x._allocated_size);
				std::swap(this->_allocator, x._allocator);
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
					_allocator(alloc), _size_value(n), _allocated_size(n)
			{
				_ptr = _allocator.allocate(_allocated_size);
				
				for (size_type i = 0; i < _size_value; ++i)
					_allocator.construct(&_ptr[i], val);
			}
			// Range of iterators contructor
			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0) :
						 _size_value(0), _allocator(alloc)
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
			vector(const vector& x) :  _ptr(NULL), _size_value(0), _allocated_size(0)
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
					_allocator.destroy(&(*it));
				_allocator.deallocate(_ptr, _allocated_size);
			}
		private:
			void ralloc(size_type capacity)
			{
				pointer tmp = _allocator.allocate(capacity);
				for (size_type i = 0; i < _size_value; ++i)
					_allocator.construct(&tmp[i], _ptr[i]);
				this->~vector();
				_allocated_size = capacity;
				_ptr = tmp;
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

		n = a.size() > b.size() ? b.size() : a.size();
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