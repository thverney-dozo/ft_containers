/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:37:13 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/09 22:52:09 by aeoithd          ###   ########.fr       */
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

    template <typename T>
	struct is_alphanum { static const bool value = false; };

	template <>
	struct is_alphanum<bool> { static const bool value = true; };
	
	template <>
	struct is_alphanum<char> { static const bool value = true; };

    template <>
    struct is_alphanum<wchar_t> {static const bool value = true; };
    
	template <>
	struct is_alphanum<short> { static const bool value = true; };

	template <>
	struct is_alphanum<int> { static const bool value = true; };

	template <>
	struct is_alphanum<long> { static const bool value = true; };

	template <>
	struct is_alphanum<long long> { static const bool value = true; };

	template <>
	struct is_alphanum<unsigned char> { static const bool value = true; };

	template <>
	struct is_alphanum<unsigned short> { static const bool value = true; };

	template <>
	struct is_alphanum<unsigned int> { static const bool value = true; };

	template <>
	struct is_alphanum<unsigned long> { static const bool value = true; };

	template <>
	struct is_alphanum<unsigned long long> { static const bool value = true; };

    template <>
    struct is_alphanum<float> { static const bool value = true; };

    template <>
    struct is_alphanum<double> { static const bool value = true; };
    
    template <>
    struct is_alphanum<long double> {static const bool value = true; };
}

#endif