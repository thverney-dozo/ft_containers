/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 06:58:47 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/17 00:20:05 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <utility>

namespace ft
{
    template <class Key, class T>
        struct Node
        {
            std::pair<Key, T> pair;
            Node *left;
            Node *right;
            Node *parent;
            bool end;
        };
}

#endif