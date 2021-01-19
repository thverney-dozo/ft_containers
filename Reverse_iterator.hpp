/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:30:01 by thverney          #+#    #+#             */
/*   Updated: 2021/01/19 11:30:02 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
class Vector_Reverse_Iterator
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
		reference operator*()
		{
			Vector_Reverse_Iterator tmp(*this);
			return (*--tmp);
		}
		const_reference operator*() const
		{
			Vector_Reverse_Iterator tmp(*this);
			return (*--tmp);
		}
		pointer operator->() {
			Vector_Reverse_Iterator tmp(*this);
			return (&*--tmp);
		}
		const_pointer operator->() const
		{
			Vector_Reverse_Iterator tmp(*this);
			return (&*--tmp);
		}
		Vector_Reverse_Iterator operator++(int
		{
			Vector_Reverse_Iterator tmp(*this);
			operator++();
			return (tmp);
		}
		Vector_Reverse_Iterator &operator++()
		{
			return (this->Vector_Reverse_Iterator::operator--());
		}
		Vector_Reverse_Iterator operator--(int)
		{
			Vector_Reverse_Iterator tmp(*this);
			operator--();
			return (tmp);
		}
		Vector_Reverse_Iterator &operator--()
		{
			return (this->Vector_Reverse_Iterator::operator++());
		}
};