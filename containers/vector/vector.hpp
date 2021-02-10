/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:49:13 by thverney          #+#    #+#             */
/*   Updated: 2021/02/09 17:41:19 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <algorithm>
# include "../../iterators/random_access_iterator.hpp"
# include "../../iterators/rev_random_access_iterator.hpp"

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
			size_t 			size_value;
			size_t 			allocated_size;
			allocator_type 	_allocator;
		
		public:
			iterator begin() 									{ return iterator(_ptr); };
			const_iterator begin() 						const 	{ return const_iterator(_ptr); };
			iterator end() 										{ return iterator(_ptr + size_value); };
			const_iterator end() 						const 	{ return const_iterator(_ptr + size_value); };
			reverse_iterator rbegin() 							{ return reverse_iterator(_ptr + size_value - 1); };
			const_reverse_iterator rbegin() 			const 	{ return const_reverse_iterator(_ptr + size_value - 1); };
			reverse_iterator rend() 							{ return reverse_iterator(_ptr - 1); };
			const_reverse_iterator rend() 				const 	{ return const_reverse_iterator(_ptr - 1); };

			size_type size() 							const	{ return (size_value); };
			size_type max_size() 						const 	{ return (std::numeric_limits<difference_type>::max()); };
			size_type capacity() 						const 	{ return (allocated_size); };
			bool empty() 								const	{ return (!(size_value)); };
			reference operator[] (size_type n)					{ return (_ptr[n]); };
			const_reference operator[] (size_type n) 	const 	{ return (_ptr[n]); };
			void reserve (size_type n)
			{
				pointer			new_ptr;
				allocator_type	alloc_type;
				size_type		to_allocate;
			
				if (n > allocated_size)
				{
					to_allocate = allocated_size ? allocated_size : 32;
					while (to_allocate < n)
						to_allocate *= 2;
					new_ptr = alloc_type.allocate(to_allocate);
					for (size_type i = 0; i < size_value; i++)
					{
						alloc_type.construct(&new_ptr[i], _ptr[i]);
						alloc_type.destroy(&_ptr[i]);
					}
					alloc_type.deallocate(_ptr, allocated_size);
					_ptr = new_ptr;
					allocated_size = to_allocate;
				}
			};

			void resize (size_type n, value_type val = value_type())
			{
				if (n < size_value)
					erase(iterator(_ptr + n), end());
				if (n > size_value)
					insert(end(), n - size_value, val);
				size_value = n;
			};

			reference at (size_type n)
			{
				if (n >= size_value && n >= 0)
					throw std::out_of_range("Index out of range");
				return (_ptr[n]);
			};
			const_reference at (size_type n) const
			{
				if (n >= size_value && n >= 0)
					throw std::out_of_range("Index out of range");
				return (_ptr[n]);
			};
			reference front() 										{ return (_ptr[0]); };
			const_reference front() 					const		{ return (_ptr[0]); };
			reference back()										{ return (_ptr[size_value -1]); };
			const_reference back() 						const		{ return (_ptr[size_value -1]); };;

			void assign(const_iterator first, const_iterator last)
			{
				clear();
				insert(begin(), first, last);
			};
			void assign (size_type n, const value_type& val)
			{
				clear();
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

				reserve(size_value + n);

				for (size_type i = size_value - 1; i > new_info - 1; i--)
				{
					alloc_type.construct(&_ptr[i + n], _ptr[i]);
					alloc_type.destroy(&_ptr[i]);
				}
				for (size_type k = 0; k < n; k++)
					alloc_type.construct(&_ptr[k + new_info], val);
				size_value += n;
			};
			void insert(iterator position, iterator first, iterator last)
			{
				size_type		n = last._ptr - first._ptr;
				size_type		new_info = position._ptr - _ptr;
				allocator_type	alloc_type;

				reserve(size_value + n);
				for (size_type i = size_value - 1; i > new_info - 1; i--)
				{
					alloc_type.construct(&_ptr[i + n], _ptr[i]);
					alloc_type.destroy(&_ptr[i]);
				}
				for (size_type k = 0; k < n; k++)
					alloc_type.construct(&_ptr[k + new_info], *first++);
				size_value += n;

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
				for (size_type i = new_info; i < size_value; i++)
				{
					alloc_type.construct(&_ptr[i], _ptr[i + n]);
					alloc_type.destroy(&_ptr[i + n]);
				}
				size_value -= n;
				return (iterator(_ptr + new_info));
			};
			void swap (vector& x)
			{
				std::swap(_ptr, x._ptr);
				std::swap(size_value, x.size_value);
				std::swap(allocated_size, x.allocated_size);
			};
			void clear()
			{
				erase(begin(), end());
			};

		public:
			explicit vector(const allocator_type &allocator = allocator_type()) :
					size_value(0), allocated_size(0), _allocator(allocator)
			{_ptr = _allocator.allocate(0); };

			vector(size_type n, const value_type& val = value_type());
			// template <typename InputIterator>
         	// 	vector(InputIterator first, InputIterator last, typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, int>::type = 0);
			vector(const vector& x) : allocated_size(0), size_value(0), _ptr(NULL) { vector::insert(begin(), x.begin(), x.end()); };
			~vector();	
			vector& operator=(const vector &affect)
			{
				clear();
				insert(begin(), affect.begin(), affect.end());
				return (*this);
			};
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