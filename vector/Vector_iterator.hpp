/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:56:24 by thverney          #+#    #+#             */
/*   Updated: 2021/02/03 11:29:21 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template<typename T>
class vector_iterator
{
	protected:
		T *p;

	public:
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type const * const_pointer;
		typedef value_type& reference;
		typedef value_type const & const_reference;
		typedef std::ptrdiff_t difference_type;

	private:

	public:
			vector_iterator()
			{};
			 vector_iterator(const vector_iterator &other)
			{
				*this = other;
			};
			 vector_iterator(pointer ptr)
			: _ptr(ptr)
			{};
			 ~vector_iterator()
			{};
			vector_iterator &operator=(const vector_iterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			vector_iterator &operator++()
			{
				_ptr++;
				return (*this);
			};
			vector_iterator &operator--()
			{
				_ptr--;
				return (*this);
			};
			vector_iterator operator++(int)
			{
				vector_iterator tmp(*this);
				operator++();
				return (tmp);
			};
			vector_iterator operator--(int)
			{
				vector_iterator tmp(*this);
				operator--();
				return (tmp);
			};
};

}