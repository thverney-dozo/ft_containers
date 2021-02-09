/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:37:13 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/09 22:39:36 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_HPP
# define CHECKERS_HPP
namespace ft
{
    template <bool B>
    struct enable_if {};

    template <>
    struct enable_if<true> {
        typedef int type;
    };
}

#endif