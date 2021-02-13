/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 22:37:13 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/13 01:41:17 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_HPP
# define CHECKERS_HPP
namespace ft
{
    template <class InputIT>
    size_t distance(InputIT start, InputIT end)
    {
        size_t i = 0;
        
        while (start != end)
        {
            i++;
            start++;
        }
        return (i);
    }

    //      ENABLE_IF 
    
    template <bool B, class T = void>
    struct enable_if {} ;
    
    template <class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <typename T>
	struct is_not_it { static const bool value = false; };

	template <>
	struct is_not_it<bool> { static const bool value = true; };
	
	template <>
	struct is_not_it<char> { static const bool value = true; };

    template <>
    struct is_not_it<wchar_t> {static const bool value = true; };
    
	template <>
	struct is_not_it<short> { static const bool value = true; };

	template <>
	struct is_not_it<int> { static const bool value = true; };

	template <>
	struct is_not_it<long> { static const bool value = true; };

	template <>
	struct is_not_it<long long> { static const bool value = true; };

	template <>
	struct is_not_it<unsigned char> { static const bool value = true; };

	template <>
	struct is_not_it<unsigned short> { static const bool value = true; };

	template <>
	struct is_not_it<unsigned int> { static const bool value = true; };

	template <>
	struct is_not_it<unsigned long> { static const bool value = true; };

	template <>
	struct is_not_it<unsigned long long> { static const bool value = true; };

    template <>
    struct is_not_it<float> { static const bool value = true; };

    template <>
    struct is_not_it<double> { static const bool value = true; };
    
    template <>
    struct is_not_it<long double> {static const bool value = true; };

    template <typename T, typename U>
    struct is_pair { static const bool value = false; };

    template <typename T>
    struct is_pair<T,T> { static const bool value = true; };

    template <class T = void, bool B = !ft::is_not_it<T>::value >
    struct is_input_iterator{};
    // { static const bool value = false; };

    template <class T>
    struct is_input_iterator<T, true> {
        static const bool value =ft::is_pair<typename T::iterator_category, std::input_iterator_tag>::value ||
                            ft::is_pair<typename T::iterator_category, std::forward_iterator_tag>::value ||
                            ft::is_pair<typename T::iterator_category, std::bidirectional_iterator_tag>::value ||
                            ft::is_pair<typename T::iterator_category, std::random_access_iterator_tag>::value;
    };
    template <class T>
    struct is_input_iterator<T*, true>
    { static const bool value = true; };


}

#endif