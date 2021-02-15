/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:34:23 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/15 11:34:32 by aeoithd          ###   ########.fr       */
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
			};

		
		private:
            t_lst		*first;
			t_lst		*last;
			size_type	size_value;

		
		public:
			iterator begin(void) {};
			const_iterator begin(void) const {};
			iterator end(void) {};
			const_iterator end(void) const {};
			reverse_iterator rbegin(void) {};
			const_reverse_iterator rbegin(void) const {};
			reverse_iterator rend(void) {};
			const_reverse_iterator rend(void) const {};

			bool empty(void) const
			{
			};
			size_type size(void) const
			{
			};
			size_type max_size(void) const
			{
			};
			reference front(void)
			{
			};
			const_reference front(void) const
			{
			};
			reference back(void)
			{
			};
			const_reference back(void) const
			{
			};
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
			};
			void assign(size_type n, const value_type &value)
			{
			};
			void push_front(const value_type &value)
			{
			};
			void pop_front(void)
			{
			};
			void push_back(const value_type &value)
			{
			}
			void pop_back(void)
			{
			};
			iterator insert(iterator position, const value_type &value)
			{
			};
			void insert(iterator position, size_type n, const value_type &value)
			{
			};
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
			};
			iterator erase(iterator position)
			{
			};
			iterator erase(iterator first, iterator last)
			{
			};
			void swap(List &x)
			{
			};
			void resize(size_type n, value_type value = value_type())
			{
			};
			void clear(void)
			{
			};
			void splice(iterator position, List &x)
			{
			};
			void splice(iterator position, List &x, iterator i)
			{
			};
			void splice(iterator position, List &x, iterator first, iterator last)
			{
			};
			void remove(const value_type &value)
			{
			};
			template <class Predicate>
			void remove_if(Predicate pred)
			{
			};
			void unique(void)
			{
			};
			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
			};
			void merge(List &x)
			{
			};
			template <class Compare>
			void merge(List &x, Compare comp)
			{
			};
			void sort(void)
			{
			};
			template <class Compare>
			void sort(Compare comp)
			{
			};
			void reverse(void)
			{
			};
	};
	template <class T>
	bool operator==(const list<T>& a, const list<T>& b)
	{
	}

	template <class T>
	bool operator!=(const list<T>& a, const list<T>& b)
	{
	}

	template <class T>
	bool operator<(const list<T>& a, const list<T>& b)
	{
	}

	template <class T>
	bool operator<=(const list<T>& a, const list<T>& b)
	{
	}

	template <class T>
	bool operator>(const list<T>& a, const list<T>& b)
	{
	}

	template <class T>
	bool operator>=(const list<T>& a, const list<T>& b)
	{
	}
}

#endif
