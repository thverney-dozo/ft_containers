/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:34:23 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/17 04:36:24 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <algorithm>
# include "../iterators/utils.hpp"

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T 										value_type;
			typedef Alloc 									allocator_type;
			typedef T& 										reference;
			typedef const T& 								const_reference;
			typedef T* 										pointer;
			typedef const T* 								const_pointer;
			typedef unsigned long 							size_type;
			typedef Node<value_type>* 						node;
			typedef ListIterator<value_type> 				iterator;
			typedef ConstListIterator<value_type> 			const_iterator;
			typedef ReverseListIterator<value_type> 		reverse_iterator;
			typedef ConstReverseListIterator<value_type> 	const_reverse_iterator;
		
		private:
            node			_firstN;
			node			_lastN;
			size_type		_size_value;
			allocator_type 	_alloc;

			node _newNode(node prev, node next, value_type val)
			{
				node nNew = new Node<value_type>();
				nNew->info = val;
				nNew->prev = prev;
				nNew->next = next;
				return (nNew);
			};
			void _initialize_list()
			{
				_firstN = _newNode(0, 0, value_type);
				_lastN = _newNode(_firstN, 0, value_type);
				_firstN->next = _lastN;
			};

			void unlinkNode(Node *delN)
			{
				delN->prev->next = delN->next;
				delN->next->prev = delN->prev;
				delete delN;
				_size_value -= 1;
			}
		
		public:
		
			explicit list(const allocator_type &alloc=allocator_type())
				: _firstN(0), _lastN(0), _alloc(alloc), _size_value(0)
			{
				_initialize_list();
			};

			explicit list(size_type n, const value_type &value = value_type(), const allocator_type &alloc=allocator_type())
			: _firstN(0), _lastN(0), _alloc(alloc), _size_value(0)
			{
				_initialize_list();
				assign(n, value);
			};

			template <class InputIterator>
				list(InputIterator first, InputIterator last, const allocator_type &alloc=allocator_type())
					: _firstN(0), _lastN(0), _alloc(alloc), _size_value(0)
				{
					_initialize_list();
					assign(first, last);

				};

			list(const list &cpy)
			: _firstN(0), _lastN(0), _alloc(cpy._alloc), _size_value(0)
			{
				_initialize_list();
				*this = cpy;
			};

			list &operator=(const list &affect)
			{
				clear();
				assign(affect.begin(), affect.end());
				_size_value = affect._size_value;
				return (*this);
			};

			~list()
			{
				clear();
				delete _firstN;
				delete _lastN;
			};

			iterator begin() 						{ return (iterator(_firstN->next)); };
			const_iterator begin() 			const 	{ return (const_iterator(_firstN->next)); };
			iterator end() 							{ return (iterator(_lastN)); };
			const_iterator end() 			const 	{ return (const_iterator(_lastN)); };
			reverse_iterator rbegin() 				{ return (reverse_iterator(_lastN->prev)); };
			const_reverse_iterator rbegin() const 	{ return (const_reverse_iterator(_lastN->prev)); };
			reverse_iterator rend() 				{ return (reverse_iterator(_firstN)); };
			const_reverse_iterator rend() 	const 	{ return (const_reverse_iterator(_firstN)); };

			bool empty() 					const 	{ return (_size_value == 0); };
			size_type size() 				const 	{ return (_size_value); };
			size_type max_size() 			const 	{ return (allocator_type().max_size()); };
			reference front()						{ return (_firstN->next->info); };
			const_reference front() 		const 	{ return (_firstN->next->info); };
			reference back()						{ return (_lastN->prev->info); };
			const_reference back() 			const	{ return (_lastN->prev->info); };
			
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
			};
			void assign(size_type n, const value_type &value)
			{
			};
			void push_front(const value_type &value)
			{
				node pshfnode = _newNode(_firstN, _firstN->next, value);
				_firstN->next->prev = pshfnode;
				_firstN->next = pshfnode;
				_size_value++;
			};
			void pop_front()
			{
				node ppfnode = _firstN->next->next;
				delete _firstN->next;
				_firstN->next = ppfnode;
				ppfnode->prev = _firstN;
				_size_value--;
			};
			void push_back(const value_type &value)
			{
				node pshbnode = _newNode(_lastN->prev, _lastN, value);
				_lastN->prev->next = pshbnode;
				_lastN->prev = pshbnode;
				_size_value++;
			}
			void pop_back()
			{
				node ppbnode = _lastN->prev->prev;
				delete _lastN->prev;
				_lastN->prev = ppbnode;
				ppbnode->next = _lastN;
				_size_value--;
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
			void swap(list &x)
			{
			};
			void resize(size_type n, value_type value = value_type())
			{
			};
			void clear()
			{
				node delN = _firstN;
				while (delN->next != _lastN)
					unlinkNode(delN->next);
				_size_value = 0;
			};
			void splice(iterator position, list &x)
			{
			};
			void splice(iterator position, list &x, iterator i)
			{
			};
			void splice(iterator position, list &x, iterator first, iterator last)
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
			void merge(list &x)
			{
			};
			template <class Compare>
			void merge(list &x, Compare comp)
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
