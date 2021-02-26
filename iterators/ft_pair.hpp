/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:48:13 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/26 17:49:01 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

namespace ft
{

template <typename V1, typename V2>
    class pair
    {
        public:
            pair() : key(), mapped() {};
            pair(const V1& a, const V2& b) : key(a), mapped(b) {};
            pair(const pair<V1, V2>& copy) : key(copy.key), mapped(copy.mapped) {};
            template <typename U, typename V>
                pair(const pair<U, V>& copy) : key(copy.key), mapped(copy.mapped) {};
            ~pair() {};
            pair& operator=(const pair& assign)
            {
                if (this != &assign)
                {
                    key = assign.key;
                    mapped = assign.mapped;
                }
                return (*this);
            }
            V1 key;
            V2 mapped;
    };
};

#endif