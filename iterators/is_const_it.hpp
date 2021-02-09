/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_const_it.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:24:51 by thverney          #+#    #+#             */
/*   Updated: 2021/02/09 00:08:29 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 0

#ifndef IS_CONST_IT_HPP
# define IS_CONST_IT_HPP

namespace ft
{
	template <bool is_it_const, typename not_const, typename is_const>
	struct choose_if_const {};

	template <typename not_const, typename is_const>
	struct choose_if_const <false, not_const, is_const>
	{
		typedef is_const _type;
	};

	template <typename not_const, typename is_const>
	struct choose_if_const <true, not_const, is_const>
	{
		typedef not_const _type;
	};
}

#endif