/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:34 by thverney          #+#    #+#             */
/*   Updated: 2021/02/08 17:34:01 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "bidirectional_iterator.hpp"


namespace ft
{
	template<typename T, bool B>
	class random_access_iterator : public bidirectional_iterator<T, B>
	{
		public:
            typedef typename ft::bidirectional_iterator<T, B>::difference_type	difference_type;
			typedef typename ft::bidirectional_iterator<T, B>::value_type			value_type;
			typedef typename ft::bidirectional_iterator<T, B>::size_type			size_type;
			
			typedef typename ft::bidirectional_iterator<T, B>::reference			reference;
			typedef typename ft::bidirectional_iterator<T, B>::pointer			pointer;
			typedef typename ft::bidirectional_iterator<T, B>::non_const_pointer	non_const_pointer;
    };
}

#endif