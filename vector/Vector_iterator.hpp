/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:56:24 by thverney          #+#    #+#             */
/*   Updated: 2021/02/03 13:42:02 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{

	template<typename T>
	class Vector_iterator
	{
		public:
				typedef T value_type;
				typedef T& reference;
				typedef T* pointer;
		protected:
				pointer _ptr;

		public:
				Vector_iterator()
				{};
				Vector_iterator(const Vector_iterator &other)
				{
					*this = other;
				};
				Vector_iterator(pointer ptr)
				: _ptr(ptr)
				{};
				~Vector_iterator()
				{};
				Vector_iterator &operator=(const Vector_iterator &other)
				{
					_ptr = other._ptr;
					return (*this);
				};
				Vector_iterator &operator++()
				{
					_ptr++;
					return (*this);
				};
				Vector_iterator &operator--()
				{
					_ptr--;
					return (*this);
				};
				Vector_iterator operator++(int)
				{
					Vector_iterator tmp(*this);
					operator++();
					return (tmp);
				};
				Vector_iterator operator--(int)
				{
					Vector_iterator tmp(*this);
					operator--();
					return (tmp);
				};
				bool operator==(const Vector_iterator &other) const
				{
					return (_ptr == other._ptr);
				};
				bool operator!=(const Vector_iterator &other) const
				{
					return (_ptr != other._ptr);
				};
				bool operator>(const Vector_iterator &other) const
				{
					return (_ptr > other._ptr);
				};
				bool operator>=(const Vector_iterator &other) const
				{
					return (_ptr >= other._ptr);
				};
				bool operator<(const Vector_iterator &other) const
				{
					return (_ptr < other._ptr);
				};
				bool operator<=(const Vector_iterator &other) const
				{
					return (_ptr <= other._ptr);
				};
				value_type &operator*(void)
				{
					return (*_ptr);
				};
				value_type *operator->(void)
				{
					return (_ptr);
				};
				Vector_iterator operator+(int n) const
				{
					Vector_iterator tmp(*this);
					tmp += n;
					return (tmp);
				};
				Vector_iterator operator-(int n) const
				{
					Vector_iterator tmp(*this);
					tmp -= n;
					return (tmp);
				};
				Vector_iterator &operator+=(int n)
				{
					while (n < 0)
					{
						(*this)--;
						n++;
					}
					while (n > 0)
					{
						(*this)++;
						n--;
					}
					return (*this);
				};
				Vector_iterator &operator-=(int n)
				{
					while (n > 0)
					{
						operator--();
						n--;
					}
					while (n < 0)
					{
						operator++();
						n++;
					}
					return (*this);
				};
				value_type &operator[](int n) const
				{
					return (*(*this + n));
				}
	};
	template <class T>
	class Reverse_vector_iterator : public Vector_iterator<T>
	{
		public:
				typedef T value_type;
				typedef T& reference;
				typedef T* pointer;
				Reverse_vector_iterator(void)
				{};
				Reverse_vector_iterator(const Reverse_vector_iterator &other)
				{
					*this = other;
				};
				Reverse_vector_iterator(pointer ptr)
				{
					this->_ptr = ptr;
				};
				~Reverse_vector_iterator(void)
				{};
				Reverse_vector_iterator &operator=(const Reverse_vector_iterator &other)
				{
					this->_ptr = other._ptr;
					return (*this);
				};
				Reverse_vector_iterator &operator++(void)
				{
					this->_ptr--;
					return (*this);
				};
				Reverse_vector_iterator operator++(int)
				{
					Reverse_vector_iterator tmp(*this);
					this->_ptr--;
					return (tmp);
				};
				Reverse_vector_iterator &operator--(void)
				{
					this->_ptr++;
					return (*this);
				};
				Reverse_vector_iterator operator--(int)
				{
					Reverse_vector_iterator tmp(*this);
					tmp._ptr++;
					rteurn (tmp);
				};
				Reverse_vector_iterator operator+=(int n)
				{
					while (n > 0)
					{
						operator++();
						n--;
					}
					while (n < 0)
					{
						operator--();
						n++;
					}
					return (*this);
				};
				Reverse_vector_iterator operator-=(int n)
				{
					while (n > 0)
					{
						operator--();
						n--;
					}
					while (n < 0)
					{
						operator++();
						n++;
					}
					return (*this);
				};
				bool operator==(const Reverse_vector_iterator &other) const
				{
					return (this->_ptr == other._ptr);
				};
				bool operator!=(const Reverse_vector_iterator &other) const
				{
					return (this->_ptr != other._ptr);
				};
				bool operator>(const Reverse_vector_iterator &other) const
				{
					return (this->_ptr > other._ptr);
				};
				bool operator>=(const Reverse_vector_iterator &other) const
				{
					return (this->_ptr >= other._ptr);
				};
				bool operator<(const Reverse_vector_iterator &other) const
				{
					return (this->_ptr < other._ptr);
				};
				bool operator<=(const Reverse_vector_iterator &other) const
				{
					return (this->_ptr <= other._ptr);
				};
				value_type &operator*(void)
				{
					return (*this->_ptr);
				};
				value_type *operator->(void)
				{
					return (this->_ptr);
				};
				Reverse_vector_iterator operator+(int n) const
				{
					Reverse_vector_iterator tmp(*this);
					tmp += n;
					return (tmp);
				};
				Reverse_vector_iterator operator-(int n) const
				{
					Reverse_vector_iterator tmp(*this);
					tmp -= n;
					return (tmp);
				};
				value_type &operator[](int n) const
				{
					std::cout << "eeeeee" << std::endl;
					return (*(*this - n));
				};
	};
	template <class T>
	class Const_vector_iterator : public Vector_iterator<T>
	{
		public:
				typedef T value_type;
				typedef T& reference;
				typedef T* pointer;
				Const_vector_iterator(void)
				{};
				Const_vector_iterator(pointer ptr)
				{
					this->_ptr = ptr;
				};
				Const_vector_iterator(const Const_vector_iterator &other)
				{
					*this = other;
				};
				~Const_vector_iterator(void)
				{};
				Const_vector_iterator &operator=(const Const_vector_iterator &other)
				{
					this->_ptr = other._ptr;
					return (*this);
				};
				const value_type &operator*(void)
				{
					return (*this->_ptr);
				};
				const value_type &operator[](int n) const
				{
					return (*(*this + n));
				}
	};
	template <class T>
	class Const_reverse_vector_iterator : public Reverse_vector_iterator<T>
	{
		public:
				typedef T value_type;
				typedef T& reference;
				typedef T* pointer;
				Const_reverse_vector_iterator(void)
				{};
				Const_reverse_vector_iterator(pointer ptr)
				{
					this->_ptr = ptr;
				};
				Const_reverse_vector_iterator(const Const_reverse_vector_iterator &other)
				{
					*this = other;
				};
				~Const_reverse_vector_iterator(void)
				{};
				Const_reverse_vector_iterator &operator=(const Const_reverse_vector_iterator &other)
				{
					this->_ptr = other._ptr;
					return (*this);
				};
				const value_type &operator*(void)
				{
					return (*this->_ptr);
				};
				const value_type &operator[](int n) const
				{
					return (*(*this - n));
				}
	};
};


#endif