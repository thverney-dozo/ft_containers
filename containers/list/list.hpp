/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:34:23 by aeoithd           #+#    #+#             */
/*   Updated: 2021/01/20 11:23:49 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <algorithm>

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			list();
			~list();	
			list& operator=(const list &affect)
			{
				clear();
				insert(begin(), affect.begin(), affect.end());
				return (*this);
			};
            typedef struct 		s_lst
			{
				value_type		elm;
				struct s_lst	*next;
				struct s_lst	*prev;
			}					t_lst;

		
		private:
            t_lst		*first;
			t_lst		*last;
			size_type	size_value;

		public:
			typedef T 											value_type;	
			typedef T& 											reference;
			typedef T const 									&reference;
			typedef T* 											pointer;
			typedef T const 									*pointer;
			typedef list_iterator<value_type>					iterator;
			typedef list_iterator<value_type const> 			const_iterator;
			typedef list_reverse_iterator<value_type> 		reverse_iterator;
			typedef list_reverse_iterator<value_type const> 	const_reverse_iterator;
			typedef	std::allocator<value_type>					allocator_type;
			typedef std::ptrdiff_t 								difference_type;
			typedef unsigned int 								size_type;
		
		public:
			iterator begin() 									{ return array; };
			const_iterator begin() 						const 	{ return array; };
			iterator end() 										{ return (array + size_value); };
			const_iterator end() 						const 	{ return (array + size_value); };
			reverse_iterator rbegin() 							{ return (array + size_value - 1); };
			const_reverse_iterator rbegin() 			const 	{ return (array + size_value - 1); };
			reverse_iterator rend() 							{ return (array - 1); };
			const_reverse_iterator rend() 				const 	{ return (array - 1); };

			size_type size() 							const	{ return (size_value); };
			size_type max_size() 						const 	{ return (std::numeric_limits<difference_type>::max()) } ;
			size_type capacity() 						const 	{ return (allocated_size); };
			bool empty() 								const	{ return (!(size_value)); };
			reference operator[] (size_type n)					{ return (ptr[n]); };
			const_reference operator[] (size_type n) 	const 	{ return (ptr[n]); };
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
						alloc_type.construct(&new_ptr[i], ptr[i]);
						alloc_type.destroy(&ptr[i]);
					}
					alloc_type.deallocate(ptr, allocated_size);
					ptr = new_ptr;
					allocated_size = to_allocate;
				}
			};

			void resize (size_type n, value_type val = value_type())
			{
				if (n < size_value)
					erase(iterator(_ptr + n), end());
				if (n > size_value)
					insert(end(), n - _size, val);
				size_value = n;
			};

			reference at (size_type n)
			{
				if (n >= size_value && n >= 0)
					throw std::out_of_range("Index out of range");
				return (ptr[n]);
			};
			const_reference at (size_type n) const;
			{
				if (n >= size_value && n >= 0)
					throw std::out_of_range("Index out of range");
				return (ptr[n]);
			};
			reference front() 										{ return (ptr[0]); };
			const_reference front() 					const		{ return (ptr[0]); };
			reference back()										{ return (ptr[size_value -1]); };
			const_reference back() 						const		{ return (ptr[size_value -1]); };;

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
			void push_front (const value_type& val);
			void pop_front();
			iterator insert (iterator position, const value_type& val) 
			{
				insert(position, 1, val);
				return (position);

			};
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type		new_info = position.ptr - ptr;
				allocator_type	alloc_type;

				reserve(size_value + n);

				for (size_type i = size_value - 1; i > new_info - 1; i--)
				{
					alloc_type.construct(&ptr[i + n], ptr[i]);
					alloc_type.destroy(&ptr[i]);
				}
				for (size_type k = 0; k < n; k++)
					alloc_type.construct(&ptr[k + new_info], val);
				size_value += n;
			};
			void insert(iterator position, iterator first, iterator last)
			{
				size_type		n = last._ptr - first._ptr;
				size_type		new_info = position._ptr - ptr;
				allocator_type	alloc_type;

				reserve(size_value + n);
				for (size_type i = size_value - 1; i > new_info - 1; i--)
				{
					alloc_type.construct(&ptr[i + n], ptr[i]);
					alloc_type.destroy(&ptr[i]);
				}
				for (size_type k = 0; k < n; k++)
					alloc_type.construct(&ptr[k + new_info], *first++);
				size_value += n;

			};
			iterator erase (iterator position)
			{
				return erase(position, position + 1);
			};
			iterator erase (iterator first, iterator last)
			{
				size_type		n = last.ptr - first.ptr;
				size_type		new_info = first.ptr - ptr;
				allocator_type	alloc_type;

				for (size_type k = 0; k < n; k++)
					actr.destroy(&ptr[k]);
				for (size_type i = new_info; i < size_value; i++)
				{
					actr.construct(&ptr[i], ptr[i + n]);
					actr.destroy(&ptr[i + n]);
				}
				size_value -= n;
				return (iterator(ptr + new_info));
			};
			void swap (list& x)
			{
				std::swap(ptr, x.ptr);
				std::swap(size_value, x.size_value);
				std::swap(allocated_size. x.allocated_size);
			};
			void clear()
			{
				erase(begin(), end());
			};
			void splice (iterator position, list& x)
			{

			};
			void splice (iterator position, list& x, iterator i)
			{

			};
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				
			};
	};
	template <class T>
	bool operator==(const list<T>& a, const list<T>& b)
	{
		if (a.size() != b.size())
			return (false);
		for (unsigned int i = 0; i < a.size(); i++)
			if (a[i] != b[i])
				return (false);
		return (true);
	}

	template <class T>
	bool operator!=(const list<T>& a, const list<T>& b)
	{
		return (!(a == b));
	}

	template <class T>
	bool operator<(const list<T>& a, const list<T>& b)
	{
		size_t		n;

		n = a.size() > b.size() ? b.size() : a.size;
		for (typename list<T>::size_type i = 0; i < n; i++)
			if (a.at(i) != b.at(i))
				return(a.at(i) < b.at(i) ? true : false);
		return (a.size() < b.size());
	}

	template <class T>
	bool operator<=(const list<T>& a, const list<T>& b)
	{
		return (a < b || a == b);
	}

	template <class T>
	bool operator>(const list<T>& a, const list<T>& b)
	{
		return (!(a < b) && !(a == b));
	}

	template <class T>
	bool operator>=(const list<T>& a, const list<T>& b)
	{
		return (!(a < b));
	}
}

#endif
