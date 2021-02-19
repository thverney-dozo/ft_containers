/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_helpers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 05:06:48 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/19 15:24:45 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>
# include <iostream>
# include "../containers/vector.hpp"
# include "../containers/stack.hpp"
# include "../containers/queue.hpp"
# include "../containers/list.hpp"
# include "../iterators/avl_tree.hpp"

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
#  define RED  "\x1B[31m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define RED  "\x1B[31m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# define GOOD "✓"
# define FAIL "❌"

void	test_vector(void);

inline void print_header(std::string str)
{
	int margin = (40 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << BLUE << std::endl;
	std::cout << std::string(width - (str.length() % 2 == 0 ? 1 : 0), '*') << std::endl;
	std::cout << "*" << std::string(margin - (str.length() % 2 == 0 ? 1 : 0), ' ')\
				<< str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width - (str.length() % 2 == 0 ? 1 : 0), '*') << std::endl;
	std::cout << RESET;
};

inline void print_header_container(std::string str)
{
	int margin = (40 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << GREEN << std::endl;
	std::cout << std::string(width - (str.length() % 2 == 0 ? 1 : 0), '@') << std::endl;
	std::cout << "@" << std::string(margin - (str.length() % 2 == 0 ? 1 : 0), ' ') << str \
		<< std::string(margin, ' ') << "@" << std::endl;
	std::cout << std::string(width - (str.length() % 2 == 0 ? 1 : 0), '@') << std::endl;
	std::cout << RESET;
};

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(38 - name.length(), ' ');
	if (a == b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(38 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

template <typename T>
bool operator==(ft::list<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::list<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

#endif