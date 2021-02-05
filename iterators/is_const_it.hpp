/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_const_it.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:24:51 by thverney          #+#    #+#             */
/*   Updated: 2021/02/05 15:46:41 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_CONST_IT_HPP
# define IS_CONST_IT_HPP

namespace ft
{
	template <bool is_it_const, typename _not_const, typename _const>
	struct choose_if_const {};

	template <typename _not_const, typename _const>
	struct choose_if_const <false, _not_const, _const>
	{
		typedef _not_const _type;
	};

	template <typename _not_const, typename _const>
	struct choose_if_const <true, _not_const, _const>
	{
		typedef _not_const _type;
	};
}

#endif