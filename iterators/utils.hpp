/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 06:58:47 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/17 03:32:25 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <utility>

namespace ft
{
    template <class T>
	struct Node
	{
		T info;
		Node *prev;
		Node *next;
	};
}

#endif