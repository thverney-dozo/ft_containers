/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:30:01 by thverney          #+#    #+#             */
/*   Updated: 2021/01/19 13:29:22 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
class vector_reverse_iterator
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
			vector_reverse_iterator tmp(*this);
			return (*--tmp);
		}
		const_reference operator*() const
		{
			vector_reverse_iterator tmp(*this);
			return (*--tmp);
		}
		pointer operator->() {
			vector_reverse_iterator tmp(*this);
			return (&*--tmp);
		}
		const_pointer operator->() const
		{
			vector_reverse_iterator tmp(*this);
			return (&*--tmp);
		}
		vector_reverse_iterator operator++(int
		{
			vector_reverse_iterator tmp(*this);
			operator++();
			return (tmp);
		}
		vector_reverse_iterator &operator++()
		{
			return (this->vector_reverse_iterator::operator--());
		}
		vector_reverse_iterator operator--(int)
		{
			vector_reverse_iterator tmp(*this);
			operator--();
			return (tmp);
		}
		vector_reverse_iterator &operator--()
		{
			return (this->vector_reverse_iterator::operator++());
		}
};