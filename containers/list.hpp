/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:34:23 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/17 08:14:20 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <algorithm>
# include "../iterators/checkers.hpp"
# include "../iterators/list_iterator.hpp"

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		private:
		
			struct Node
			{
				T info;
				Node *prev;
				Node *next;
			};

		public:
			typedef T 													value_type;
			typedef Alloc 												allocator_type;
			typedef T& 													reference;
			typedef const T& 											const_reference;
			typedef T* 													pointer;
			typedef const T* 											const_pointer;
			typedef unsigned long 										size_type;
			typedef Node*			 									node;
			typedef typename ft::list_iterator<T, Node, false>			iterator;
			typedef typename ft::list_iterator<T, Node, true>			const_iterator;
			typedef typename ft::reverse_list_iterator<T, Node, false>	reverse_iterator;
			typedef typename ft::reverse_list_iterator<T, Node, true> 	const_reverse_iterator;
		
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

			void _unlinkNode(Node *delN)
			{
				delN->prev->next = delN->next;
				delN->next->prev = delN->prev;
				delete delN;
				_size_value -= 1;
			};
			
			template <typename T>
			struct _equal
			{
				bool operator()(const T &a, const T &b) const
				{
					return a == b;
				}
			};

		public:
			// Default constructor
			explicit list(const allocator_type &alloc=allocator_type())
				: _firstN(0), _lastN(0), _alloc(alloc), _size_value(0)
			{
				_initialize_list();
			};
			// Fill constructor
			explicit list(size_type n, const value_type &value = value_type(), const allocator_type &alloc=allocator_type())
			: _firstN(0), _lastN(0), _alloc(alloc), _size_value(0)
			{
				_initialize_list();
				assign(n, value);
			};
			// Range constructor
			template <class InputIterator>
				list(InputIterator first, InputIterator last, const allocator_type &alloc=allocator_type(),
					typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0)
						: _firstN(0), _lastN(0), _alloc(alloc), _size_value(0)
				{
					_initialize_list();
					assign(first, last);
				};
			// copy constructor
			list(const list &cpy)
			: _firstN(0), _lastN(0), _alloc(cpy._alloc), _size_value(0)
			{
				_initialize_list();
				*this = cpy;
			};
			// Destructor
			~list()
			{
				clear();
				delete _firstN;
				delete _lastN;
			};

			list &operator=(const list &affect)
			{
				clear();
				assign(affect.begin(), affect.end());
				_size_value = affect._size_value;
				return (*this);
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
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
				clear();
				while (first != last)
					push_back(*(first++));
			};
			void assign(size_type n, const value_type &val)
			{
				clear();
				while (n--)
					push_back(val);
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
			};
			void pop_back()
			{
				node ppbnode = _lastN->prev->prev;
				delete _lastN->prev;
				_lastN->prev = ppbnode;
				ppbnode->next = _lastN;
				_size_value--;
			};
			//###############################
			iterator insert(iterator position, const value_type &value)
			{
			};
			void insert(iterator position, size_type n, const value_type &value)
			{
			};
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0)
			{
			};
			iterator erase(iterator position)
			{
				if (position == begin())
				{
					pop_front();
					return (begin());
				}
				if (position == end())
				{
					pop_back();
					return (end());
				}
				node tmp = position.getNConstPtr()->next;
				_unlinkNode(position.getNConstPtr());
				return (iterator(tmp));
			};
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
				return (first);
			};
			void swap(list &x)
			{
				ft::swap(x._size_value, _size_value);
				ft::swap(x._firstN, _firstN);
				ft::swap(x._lastN, _lastN);
			};
			void resize(size_type n, value_type value = value_type())
			{
				while (n < _size_value)
					pop_back();
				while (n > _size_value)
					push_back(value);
			};
			void clear()
			{
				node delN = _firstN;
				while (delN->next != _lastN)
					_unlinkNode(delN->next);
				_size_value = 0;
			};
			void splice(iterator position, list &x)
			{
				while (x.size())
					splice(position, x, x.begin());
			};
			void splice(iterator position, list &x, iterator i)
			{
				node i_Node = i.getNConstPtr();
				node pos_Node = position.getNConstPtr()

				i_Node->next->prev = i_Node->prev;
				i_Node->prev->next = i_Node->next;
				i_Node->prev = pos_Node->prev;
				i_Node->next = pos_Node;
				pos_Node->prev->next = i_Node;
				pos_Node->prev = i_Node;
				
				x._size_value--;
				this->_size_value++;
			};
			//############################
			void splice(iterator position, list &x, iterator first, iterator last)
			{
			};
			//############################
			void remove(const value_type &value)
			{
				iterator rem = begin();
				while (rem != end())
				{
					if (*rem == value)
						rem = erase(rem);
					else
						rem++;
				}
			};

			template <class Predicate>
			void remove_if(Predicate pred)
			{
				iterator rem = begin();
				while (rem != end())
				{
					if (pred(*rem))
						rem = erase(rem);
					else
						rem++;
				}
			};
			
			//############################
			void unique()
			{
				unique(_equal<value_type>());

			};
			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				iterator it = begin();
				iterator comp = it;
				while (comp + 1 != end())
				{
					comp++;
					if (binary_pred(*it, *comp))
					{
						erase(comp);
						comp = it;
					}
					else
						it = comp;
				}
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
			//######################################################
			void reverse(void)
			{
				list<value_type> tmp;
				iterator it = begin();
				while (it != end())
					tmp.push_front(*(it++));
				*this = tmp;
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
