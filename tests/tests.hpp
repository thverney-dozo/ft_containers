/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 05:08:56 by aeoithd           #+#    #+#             */
/*   Updated: 2021/03/03 17:44:17 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_helpers.hpp"

#include <list>
#include <stdlib.h>

/*
 .----------------. .----------------. .----------------. 
| .--------------. | .--------------. | .--------------. |
| | ____    ____ | | |      __      | | |   ______     | |
| ||_   \  /   _|| | |     /  \     | | |  |_   __ \   | |
| |  |   \/   |  | | |    / /\ \    | | |    | |__) |  | |
| |  | |\  /| |  | | |   / ____ \   | | |    |  ___/   | |
| | _| |_\/_| |_ | | | _/ /    \ \_ | | |   _| |_      | |
| ||_____||_____|| | ||____|  |____|| | |  |_____|     | |
| |              | | |              | | |              | |
| '--------------' | '--------------' | '--------------' |
 '----------------' '----------------' '----------------' 
*/

void constructors_map(void)
{
	print_header("Constructors / Copy");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("(default) m1 == m2", (m1 == m2));
	ft::map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	check("(range) m3 == m4", (m3 == m4));
	ft::map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	check("(copy) m5 == m6", (m3 == m4));
	ft::map<int, int> m7;
	std::map<int, int> m8;
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m7[3] = 4;
	m7[4] = 5;
	m7[5] = 6;
	m7[6] = 7;
	m7[7] = 8;
	m7[8] = 9;

	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	m8[3] = 4;
	m8[4] = 5;
	m8[5] = 6;
	m8[6] = 7;
	m8[7] = 8;
	m8[8] = 9;

	check("(copy) m7 == m8", (m7 == m8));
	ft::map<int, int> m9;
	std::map<int, int> m10;
	m9 = m7;
	m10 = m8;
	check("(copy) m9 == m10", (m9 == m10));
	std::string my_map_res;
	std::string real_map_res;
	ft::map<int, int>::iterator it = m7.begin();
	for(size_t i = 0; it != m7.end(); i++)
	{
		my_map_res.insert(i, 1, it->first);
		std::cout << it->first;
		it++;
	}
	std::cout << std::endl;
	std::map<int, int>::iterator it2 = m8.begin();
	for(size_t i = 0; it2 != m8.end(); i++)
	{
		real_map_res.insert(i, 1, it2->first);
		std::cout << it2->first;
		it2++;
	}
	std::cout << std::endl;
	check("(iterator) m9 == m10", (my_map_res == real_map_res));
	my_map_res.clear();
	real_map_res.clear();
	ft::map<int, int>::const_iterator it3 = m7.begin();
	for(size_t i = 0; it3 != m7.end(); i++)
	{
		my_map_res.insert(i, 1, it3->first);
		std::cout << it3->first;
		it3++;
	}
	std::cout << std::endl;
	std::map<int, int>::const_iterator it4 = m8.begin();
	for(size_t i = 0; it4 != m8.end(); i++)
	{
		real_map_res.insert(i, 1, it4->first);
		std::cout << it4->first;
		it4++;
	}
	std::cout << std::endl;
	check("(const_iterator) m9 == m10", (my_map_res == real_map_res));
	my_map_res.clear();
	real_map_res.clear();
	ft::map<int, int>::reverse_iterator it5 = m7.rbegin();
	for(size_t i = 0; it5 != m7.rend(); i++)
	{
		my_map_res.insert(i, 1, it5->first);
		std::cout << it5->first;
		it5++;
	}
	std::cout << std::endl;
	std::map<int, int>::reverse_iterator it6 = m8.rbegin();
	for(size_t i = 0; it6 != m8.rend(); i++)
	{
		real_map_res.insert(i, 1, it6->first);
		std::cout << it6->first;
		it6++;
	}
	std::cout << std::endl;
	check("(reverse_iterator) m9 == m10", (my_map_res == real_map_res));
	my_map_res.clear();
	real_map_res.clear();
	ft::map<int, int>::const_reverse_iterator it7 = m7.rbegin();
	for(size_t i = 0; it7 != m7.rend(); i++)
	{
		my_map_res.insert(i, 1, it7->first);
		std::cout << it7->first;
		it7++;
	}
	std::cout << std::endl;
	std::map<int, int>::const_reverse_iterator it8 = m8.rbegin();
	for(size_t i = 0; it8 != m8.rend(); i++)
	{
		real_map_res.insert(i, 1, it8->first);
		std::cout << it8->first;
		it8++;
	}
	std::cout << std::endl;
	check("(const_reverse_iterator) m9 == m10", (my_map_res == real_map_res));
}

void max_size_map(void)
{
	print_header("Size");
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("m1.max_size() == m2.max_size()", m1.max_size(), m2.max_size());
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	check("m3.max_size() == m4.max_size()", m3.max_size(), m4.max_size());
	ft::map<std::string, int> m5;
	std::map<std::string, int> m6;
	check("m5.max_size() == m6.max_size()", m5.max_size(), m6.max_size());
	ft::map<std::string, int> m7;
	std::map<std::string, int> m8;
	check("m7.max_size() == m8.max_size()", m7.max_size(), m8.max_size());
}

void access_operator_map(void)
{
	print_header("[] operator");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m1["d"] = 11;
	m1["test"] = 100;
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	check("m1 == m2", m1 == m2);
	check("m1['a'] == m2['a']", m1["a"], m2["a"]);
	check("m1['d'] == m2['d']", m1["d"], m2["d"]);
	check("m1['test'] == m2['test']", m1["test"], m2["test"]);
	check("m1['z'] == m2['z']", m1["z"], m2["z"]);
}

void insert_map(void)
{
	print_header("Insert");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);
	m1.insert(++m1.begin(), std::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));
	check("m1 == m2", m1 == m2);
	m1.insert(std::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(std::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));
	check("m1 == m2", m1 == m2);
}

void erase_map(void)
{
	print_header("Erase");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["test"] = 1;
	m1["a"] = 2;
	m1["b"] = 3;
	m1["c"] = 4;
	m1["d"] = 6;
	m1["e"] = 8;
	m2["test"] = 1;
	m2["a"] = 2;
	m2["b"] = 3;
	m2["c"] = 4;
	m2["d"] = 6;
	m2["e"] = 8;
	check("m1 == m2", m1 == m2);
	m1.erase(++m1.begin());
	m2.erase(++m2.begin());
	check("m1 == m2", m1 == m2);
	m1.erase(++m1.begin(), --m1.end());
	m2.erase(++m2.begin(), --m2.end());
	check("m1 == m2", m1 == m2);
	m1.erase("a");
	m2.erase("a");
	check("m1 == m2", m1 == m2);
}

void swap_map(void)
{
	print_header("Swap");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;
	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;
	m3["a"] = 42;
	m3["b"] = 21;
	m4["a"] = 42;
	m4["b"] = 21;
	m1.swap(m3);
	m2.swap(m4);
	check("m1 == m2", m1 == m2);
	check("m3 == m4", m3 == m4);
}

void clear_map(void)
{
	print_header("Clear");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m1.clear();
	m2.clear();
	check("m1 == m2", m1 == m2);
}

void find_map(void)
{
	print_header("Find");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	check("m1.find('a') == m2.find('a')", m1.find("a")->second, m2.find("a")->second);
	check("m1.find('z') == m2.find('z')", m1.find("a")->second, m2.find("a")->second);
}

void count_map(void)
{
	print_header("Count");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	check("m1.count('a') == m2.count('a')", m1.count("a"), m2.count("a"));
	check("m1.count('b') == m2.count('b')", m1.count("b"), m2.count("b"));
	check("m1.count('z') == m2.count('z')", m1.count("z"), m2.count("z"));
}

void bounds_map()
{
	print_header("Bounds");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("a")->first, m2.lower_bound("a")->first);
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("c")->first, m2.lower_bound("c")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("a")->first, m2.upper_bound("a")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("c")->first, m2.upper_bound("c")->first);
}

void range_map(void)
{
	print_header("Equal range");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	std::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	check("a.first->first == b.first->first", a.first->first, b.first->first);
	check("a.first->second == b.first->second", a.first->second, b.first->second);
	check("a.second->first == b.second->first", a.second->first, b.second->first);
	check("a.second->second == b.second->second", a.second->second, b.second->second);
}

void operators_comp_map(void)
{
	print_header("Operators");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m3 = m1;
	m4 = m2;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m1["e"] = 1;
	m2["e"] = 1;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m3["e"] = 3;
	m4["e"] = 3;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
}

/*
 .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. |
| |   _____      | || |     _____    | || |    _______   | || |  _________   | |
| |  |_   _|     | || |    |_   _|   | || |   /  ___  |  | || | |  _   _  |  | |
| |    | |       | || |      | |     | || |  |  (__ \_|  | || | |_/ | | \_|  | |
| |    | |   _   | || |      | |     | || |   '.___`-.   | || |     | |      | |
| |   _| |__/ |  | || |     _| |_    | || |  |`\____) |  | || |    _| |_     | |
| |  |________|  | || |    |_____|   | || |  |_______.'  | || |   |_____|    | |
| |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------' 
*/
template <class T>
void print_list(T &list)
{
	typename T::iterator it = list.begin();
	typename T::iterator it2;
	std::cout << "Size " << list.size() << " : ";
	while (it != list.end())
	{
		std::cout << *it;
		it2 = it;
		it2++;
		if (it2 != list.end())
			std::cout << " - ";
		it++;
	}
	std::cout << std::endl;
}

struct Greater {
    bool operator()(const int &a, const int &b) {return a < b;}
};

void constructors_list(void)
{
	print_header("Default constructor");
	int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft::list<int> l1;
	std::list<int> l2;
	check("(default) l1 == l2", l1 == l2);
	ft::list<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	check("(fill with default value) l3 == l4", l3 == l4);
	ft::list<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	check("(fill) l5 == l6", l5 == l6);
	ft::list<int> l7(test, test + 7);
	std::list<int> l8(test, test + 7);
	check("(iterator) l7 == l8", l7 == l8);
	ft::list<int> l9(l7);
	std::list<int> l10(l8);
	check("(copy) l9 == l10", l9 == l10);
	std::string my_list_res;
	std::string real_list_res;
	ft::list<int>::iterator it = l7.begin();
	for(size_t i = 0; it != l7.end(); i++)
	{
		my_list_res.insert(i, 1, *it);
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
	std::list<int>::iterator it2 = l8.begin();
	for(size_t i = 0; it2 != l8.end(); i++)
	{
		real_list_res.insert(i, 1, *it2);
		std::cout << *it2;
		it2++;
	}
	std::cout << std::endl;
	check("(iterator) l7 == l8", (my_list_res == real_list_res));
	my_list_res.clear();
	real_list_res.clear();
	ft::list<int>::const_iterator it3 = l7.begin();
	for(size_t i = 0; it3 != l7.end(); i++)
	{
		my_list_res.insert(i, 1, *it3);
		std::cout << *it3;
		it3++;
	}
	std::cout << std::endl;
	std::list<int>::const_iterator it4 = l8.begin();
	for(size_t i = 0; it4 != l8.end(); i++)
	{
		real_list_res.insert(i, 1, *it4);
		std::cout << *it4;
		it4++;
	}
	std::cout << std::endl;
	check("(const_iterator) l7 == l8", (my_list_res == real_list_res));
	my_list_res.clear();
	real_list_res.clear();
	ft::list<int>::reverse_iterator it5 = l7.rbegin();
	for(size_t i = 0; it5 != l7.rend(); i++)
	{
		my_list_res.insert(i, 1, *it5);
		std::cout << *it5;
		it5++;
	}
	std::cout << std::endl;
	std::list<int>::reverse_iterator it6 = l8.rbegin();
	for(size_t i = 0; it6 != l8.rend(); i++)
	{
		real_list_res.insert(i, 1, *it6);
		std::cout << *it6;
		it6++;
	}
	std::cout << std::endl;
	check("(reverse_iterator) l7 == l8", (my_list_res == real_list_res));
	my_list_res.clear();
	real_list_res.clear();
	ft::list<int>::const_reverse_iterator it7 = l7.rbegin();
	for(size_t i = 0; it7 != l7.rend(); i++)
	{
		my_list_res.insert(i, 1, *it7);
		std::cout << *it7;
		it7++;
	}
	std::cout << std::endl;
	std::list<int>::const_reverse_iterator it8 = l8.rbegin();
	for(size_t i = 0; it8 != l8.rend(); i++)
	{
		real_list_res.insert(i, 1, *it8);
		std::cout << *it8;
		it8++;
	}
	std::cout << std::endl;
	check("(const_reverse_iterator) l7 == l8", (my_list_res == real_list_res));
}

void copy_operator_list(void)
{
	print_header("Operator =");
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1(test, test + 4);
	std::list<int> l2(test, test + 4);
	ft::list<int> l3;
	std::list<int> l4;
	l3 = l1;
	l4 = l2;
	check("l1 == l3", l1 == l3);
	check("l2 == l4", l2 == l4);
	l1.push_back(1);
	l2.push_back(1);
	check("l1 != l3", l1 != l3);
	check("l2 != l4", l2 != l4);
}

void max_size_list(void)
{
	print_header("Max size");
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<std::string> l3;
	std::list<std::string> l4;
	ft::list<std::string> l5;
	std::list<std::string> l6;
	check("l1.max_size() == l2.max_size()", l1.max_size(), l2.max_size());
	check("l3.max_size() == l4.max_size()", l3.max_size(), l4.max_size());
	check("l5.max_size() == l6.max_size()", l5.max_size(), l6.max_size());
}

void front_back_list(void)
{
	print_header("Front / Back");
	ft::list<int> l1;
	std::list<int> l2;
	check("front == back", l1.front() == l1.back());
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	check("l1.front() == l2.front()", l1.front(), l2.front());
	check("l1.back() == l2.back()", l1.back(), l2.back());
}

void assign_list(void)
{
	print_header("Assign");
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	l1.assign(test, test + 4);
	l2.assign(test, test + 4);
	check("l1 == l2", l1 == l2);
	l1.assign((size_t)10, 42);
	l2.assign((size_t)10, 42);
	check("l1 == l2", l1 == l2);
}

void push_list(void)
{
	print_header("Push front/back");
	ft::list<int> l1;
	std::list<int> l2;
	for (int _ = 0; _ < 100; _++)
	{
		if (rand() % 2)
		{
			int n = rand() % 100;
			l1.push_front(n);
			l2.push_front(n);
		}
		else
		{
			int n = rand() % 100;
			l1.push_back(n);
			l2.push_back(n);
		}
	}
	check("l1 == l2", l1 == l2);
}

void swap_list(void)
{
	print_header("Swap");
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<int> l3;
	std::list<int> l4;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l2.push_front(1);
	l2.push_front(2);
	l2.push_front(3);
	l3.push_front(42);
	l4.push_front(42);
	l1.swap(l3);
	l2.swap(l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

void resize_list(void)
{
	print_header("Resize / Clear");
	ft::list<int> l1;
	std::list<int> l2;
	l1.resize(10, 42);
	l2.resize(10, 42);
	check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l2.resize(2, 42);
	check("l1 == l2", l1 == l2);
	l1.resize(0, 0);
	l2.resize(0, 0);
	check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l1.clear();
	l2.resize(2, 42);
	l2.clear();
	check("l1 == l2", l1 == l2);
}

void splice_list(void)
{
	print_header("Splice");
	ft::list<int> l1((size_t)10, 5);
	std::list<int> l2((size_t)10, 5);
	ft::list<int> l3((size_t)3, 0);
	std::list<int> l4((size_t)3, 0);
	l1.splice(++l1.begin(), l3);
	l2.splice(++l2.begin(), l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin());
	l2.splice(l2.begin(), l4, ++l4.begin());
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin(), --l3.end());
	l2.splice(l2.begin(), l4, ++l4.begin(), --l4.end());
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

bool even_list(const int& value) { return (value % 2) == 0; } 

void remove_list(void)
{
	print_header("Remove / Remove if");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.remove(0);
	l1.remove(5);
	l2.remove(0);
	l2.remove(5);
	check("l1 == l2", l1 == l2);
	l1.remove_if(even_list);
	l2.remove_if(even_list);
	check("l1 == l2", l1 == l2);
}

void erase_list(void)
{
	print_header("Erase");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.erase(l1.begin());
	l1.erase(--l1.end());
	l1.erase(--l1.end());
	l2.erase(l2.begin());
	l2.erase(--l2.end());
	l2.erase(--l2.end());
	check("l1 == l2", l1 == l2);
	l1.erase(++l1.begin(), --l1.end());
	l2.erase(++l2.begin(), --l2.end());
	check("l1 == l2", l1 == l2);
}

bool compare_list(int a, int b) 
{ 
    return (a >= b); 
} 

void unique_list()
{
	print_header("Unique");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.unique();
	l2.unique();
	check("l1 == l2", l1 == l2);
	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	l1.unique(compare_list);
	l2.unique(compare_list);
	check("l1 == l2", l1 == l2);
}

bool compare2_list(int a, int b) 
{ 
    return (a == b); 
} 

void merge_list(void)
{
	print_header("Merge");
	int test[] = {1, 2, 3};
	int test2[] = {42, 43, 44};
	ft::list<int> l1(test, test + 3);
	std::list<int> l2(test, test + 3);
	ft::list<int> l3(test2, test2 + 3);
	std::list<int> l4(test2, test2 + 3);
	l1.merge(l3);
	l2.merge(l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign(test, test + 3);
	l2.assign(test, test + 3);
	l3.assign(test2, test2 + 3);
	l4.assign(test2, test2 + 3);
	l1.merge(l3, compare2_list);
	l2.merge(l4, compare2_list);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

void reverse_list(void)
{
	print_header("Reverse");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	check("l1 == l2", l1 == l2);
}

void operators_list(void)
{
	print_header("Operators");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	ft::list<int> l3(l1);
	std::list<int> l4(l2);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l1.push_back(42);
	l2.push_back(42);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l3.push_back(43);
	l4.push_back(43);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
}

/*
 .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |    ___       | || | _____  _____ | || |  _________   | || | _____  _____ | || |  _________   | |
| |  .'   '.     | || ||_   _||_   _|| || | |_   ___  |  | || ||_   _||_   _|| || | |_   ___  |  | |
| | /  .-.  \    | || |  | |    | |  | || |   | |_  \_|  | || |  | |    | |  | || |   | |_  \_|  | |
| | | |   | |    | || |  | '    ' |  | || |   |  _|  _   | || |  | '    ' |  | || |   |  _|  _   | |
| | \  `-'  \_   | || |   \ `--' /   | || |  _| |___/ |  | || |   \ `--' /   | || |  _| |___/ |  | |
| |  `.___.\__|  | || |    `.__.'    | || | |_________|  | || |    `.__.'    | || | |_________|  | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
*/

void constructors_queue(void)
{
	print_header("Constructor");
	ft::queue<int> q1;
	std::queue<int> q2;
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

void front_back_queue(void)
{
	print_header("Front / Back / Push / Pop");
	ft::queue<int> q1;
	std::queue<int> q2;
	q1.push(0);
	q1.push(1);
	q1.push(2);
	q2.push(0);
	q2.push(1);
	q2.push(2);
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
	check("q1.front() == q2.front()", q1.front(), q2.front());
	check("q1.back() == q2.back()", q1.back(), q2.back());
	q1.pop();
	q2.pop();
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.front() == q2.front()", q1.front(), q2.front());
	check("q1.back() == q2.back()", q1.back(), q2.back());
}

/*
 .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |    _______   | || |  _________   | || |      __      | || |     ______   | || |  ___  ____   | |
| |   /  ___  |  | || | |  _   _  |  | || |     /  \     | || |   .' ___  |  | || | |_  ||_  _|  | |
| |  |  (__ \_|  | || | |_/ | | \_|  | || |    / /\ \    | || |  / .'   \_|  | || |   | |_/ /    | |
| |   '.___`-.   | || |     | |      | || |   / ____ \   | || |  | |         | || |   |  __'.    | |
| |  |`\____) |  | || |    _| |_     | || | _/ /    \ \_ | || |  \ `.___.'\  | || |  _| |  \ \_  | |
| |  |_______.'  | || |   |_____|    | || ||____|  |____|| || |   `._____.'  | || | |____||____| | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
*/

void constructors_stack(void)
{
	print_header("Constructor");
	ft::stack<int> q1;
	std::stack<int> q2;
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

void front_back_stack(void)
{
	print_header("Front / Back / Push / Pop");
	ft::stack<int> q1;
	std::stack<int> q2;
	q1.push(0);
	q1.push(1);
	q1.push(2);
	q2.push(0);
	q2.push(1);
	q2.push(2);
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
	check("q1.top() == q2.top()", q1.top(), q2.top());
	q1.pop();
	q2.pop();
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.top() == q2.top()", q1.top(), q2.top());
}

/*
 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| | ____   ____  | || |  _________   | || |     ______   | || |  _________   | || |     ____     | || |  _______     | |
| ||_  _| |_  _| | || | |_   ___  |  | || |   .' ___  |  | || | |  _   _  |  | || |   .'    `.   | || | |_   __ \    | |
| |  \ \   / /   | || |   | |_  \_|  | || |  / .'   \_|  | || | |_/ | | \_|  | || |  /  .--.  \  | || |   | |__) |   | |
| |   \ \ / /    | || |   |  _|  _   | || |  | |         | || |     | |      | || |  | |    | |  | || |   |  __ /    | |
| |    \ ' /     | || |  _| |___/ |  | || |  \ `.___.'\  | || |    _| |_     | || |  \  `--'  /  | || |  _| |  \ \_  | |
| |     \_/      | || | |_________|  | || |   `._____.'  | || |   |_____|    | || |   `.____.'   | || | |____| |___| | |
| |              | || |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
*/
template <typename T>
void print_vector(T vec, std::string type)
{
	typename T::iterator it;

	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
	it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
void print_vector_reverse(T vec, std::string type)
{
	typename T::iterator it;

	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
	it = vec.rbegin();
	while (it != vec.rend())
	{
		std::cout << *it;
		if (it + 1 != vec.rend())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

void default_constructor_vector(void)
{
	print_header("Default constructor");
	ft::vector<int> v1;
	std::vector<int> v2;
	check("v1 == v2", v1 == v2);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("v1 == v2", v1 == v2);
	int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft::vector<int> v7(test, test + 7);
	std::vector<int> v8(test, test + 7);
	check("(iterator constructor) v7 == v8", v7 == v8);
	std::string my_list_res;
	std::string real_list_res;
	ft::vector<int>::iterator it = v7.begin();
	for(size_t i = 0; it != v7.end(); i++)
	{
		my_list_res.insert(i, 1, *it);
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
	std::vector<int>::iterator it2 = v8.begin();
	for(size_t i = 0; it2 != v8.end(); i++)
	{
		real_list_res.insert(i, 1, *it2);
		std::cout << *it2;
		it2++;
	}
	std::cout << std::endl;
	check("(iterator) v7 == v8", (my_list_res == real_list_res));
	my_list_res.clear();
	real_list_res.clear();
	ft::vector<int>::const_iterator it3 = v7.begin();
	for(size_t i = 0; it3 != v7.end(); i++)
	{
		my_list_res.insert(i, 1, *it3);
		std::cout << *it3;
		it3++;
	}
	std::cout << std::endl;
	std::vector<int>::const_iterator it4 = v8.begin();
	for(size_t i = 0; it4 != v8.end(); i++)
	{
		real_list_res.insert(i, 1, *it4);
		std::cout << *it4;
		it4++;
	}
	std::cout << std::endl;
	check("(const_iterator) v7 == v8", (my_list_res == real_list_res));
	my_list_res.clear();
	real_list_res.clear();
	ft::vector<int>::reverse_iterator it5 = v7.rbegin();
	for(size_t i = 0; it5 != v7.rend(); i++)
	{
		my_list_res.insert(i, 1, *it5);
		std::cout << *it5;
		it5++;
	}
	std::cout << std::endl;
	std::vector<int>::reverse_iterator it6 = v8.rbegin();
	for(size_t i = 0; it6 != v8.rend(); i++)
	{
		real_list_res.insert(i, 1, *it6);
		std::cout << *it6;
		it6++;
	}
	std::cout << std::endl;
	check("(reverse_iterator) v7 == v8", (my_list_res == real_list_res));
	my_list_res.clear();
	real_list_res.clear();
	ft::vector<int>::const_reverse_iterator it7 = v7.rbegin();
	for(size_t i = 0; it7 != v7.rend(); i++)
	{
		my_list_res.insert(i, 1, *it7);
		std::cout << *it7;
		it7++;
	}
	std::cout << std::endl;
	std::vector<int>::const_reverse_iterator it8 = v8.rbegin();
	for(size_t i = 0; it8 != v8.rend(); i++)
	{
		real_list_res.insert(i, 1, *it8);
		std::cout << *it8;
		it8++;
	}
	std::cout << std::endl;
	check("(const_reverse_iterator) v7 == v8", (my_list_res == real_list_res));
}

void copy_constructor_vector(void)
{
	print_header("Copy");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	v1.push_back(42);
	v2.push_back(42);
	check("v1 == v2", (v1 == v2));
	check("v3 == v4", (v3 == v4));
	check("v1 != v3", (v1 != v3));
	check("v2 != v4", (v2 != v4));
}

void max_size_vector(void)
{
	print_header("Max size");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
	v1.push_back("test");
	v2.push_back("test");
	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
}

void resize_vector(void)
{
	print_header("Resize");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.resize(10, "test");
	v2.resize(10, "test");
	check("v1 == v2", (v1 == v2));
	v1.resize(2, "42");
	v2.resize(2, "42");
	check("v1 == v2", (v1 == v2));
}

void access_operator_vector(void)
{
	print_header("[] operator, at()");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("v1[0] == v2[0]", v1[0], v2[0]);
	check("v1[1] == v2[1]", v1[1], v2[1]);
	check("v1[2] == v2[2]", v1[2], v2[2]);
	try
	{
		std::cout << "v1.at(100): " << v1.at(100) << ": " << FAIL << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(7, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "v2.at(100): " << v2.at(100) << ": " << FAIL  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(20, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "v1.at(-1): " << v1.at(-1) << ": " << FAIL  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(8, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "v2.at(-1): " << v2.at(-1) << ": " << FAIL  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(21, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
}

void front_back_vector(void)
{
	print_header("Front / Back");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("v1.front() == v2.front()", v1.front(), v2.front());
	check("v1.back() == v2.back()", v1.back(), v2.back());
}

void assign_vector(void)
{
	print_header("Assign");
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	check("v1 == v2", v1 == v2);
	v1.assign(10, "?");
	v2.assign(10, "?");
	check("v1 == v2", v1 == v2);
}

void insert_vector(void)
{
	print_header("Insert");
	int test[] = {1, 2, 3};
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.insert(v1.begin(), 42);
	v2.insert(v2.begin(), 42);
	check("v1 == v2 part 1", v1 == v2);
	v1.insert(v1.end(), 21);
	v2.insert(v2.end(), 21);
	check("v1 == v2 part 2", v1 == v2);
	v1.insert(v1.begin(), 10);
	v2.insert(v2.begin(), 10);
	check("v1 == v2 part 3", v1 == v2);
	v1.insert(v1.begin() + 1, 11);
	v2.insert(v2.begin() + 1, 11);
	check("v1 == v2 part 4", v1 == v2);
	v1.insert(v1.begin() + 2, (size_t)3, 0);
	v2.insert(v2.begin() + 2, (size_t)3, 0);
	check("v1 == v2 part 5", v1 == v2);
	v1.insert(v1.begin() + 1, test, test + 3);
	v2.insert(v2.begin() + 1, test, test + 3);
	check("v1 == v2 part 6", v1 == v2);
}

void erase_vector(void)
{
	print_header("Erase / Clear");
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	check("v1 == v2", v1 == v2);
	v1.clear();
	v2.clear();
	check("v1 == v2", v1 == v2);
}

void swap_vector(void)
{
	print_header("Swap");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(42);
	v3.push_back(43);
	v4.push_back(42);
	v4.push_back(43);
	v1.swap(v3);
	v2.swap(v4);
	check("v1 == v2", v1 == v2);
	check("v3 == v4", v3 == v4);
}

void operators_vector(void)
{
	print_header("Operators");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3 = v1;
	v4 = v2;
	check("v1 == v2", (v1 == v3), (v2 == v4));
	check("v1 != v2", (v1 != v3), (v2 != v4));
	check("v1 > v2", (v1 > v3), (v2 > v4));
	check("v1 < v2", (v1 < v3), (v2 < v4));
	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
	v1.push_back(42);
	v2.push_back(42);
	check("v1 == v2", (v1 == v3), (v2 == v4));
	check("v1 != v2", (v1 != v3), (v2 != v4));
	check("v1 > v2", (v1 > v3), (v2 > v4));
	check("v1 < v2", (v1 < v3), (v2 < v4));
	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
	v3.push_back(43);
	v4.push_back(43);
	check("v1 == v2", (v1 == v3), (v2 == v4));
	check("v1 != v2", (v1 != v3), (v2 != v4));
	check("v1 > v2", (v1 > v3), (v2 > v4));
	check("v1 < v2", (v1 < v3), (v2 < v4));
	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
}

void	test_all(void)
{
	
	// QUEUE
	print_header_container("Queue");
	constructors_queue();
	front_back_queue();

	//STACK
	print_header_container("Stack");
	constructors_stack();
	front_back_stack();

	// VECTOR
	print_header_container("Vector");
	default_constructor_vector();
	copy_constructor_vector();
	max_size_vector();
	resize_vector();
	access_operator_vector();
	front_back_vector();
	assign_vector();
	insert_vector();
	erase_vector();
	swap_vector();
	operators_vector();
	
	// LIST
	std::srand(time(0));
	print_header_container("List");
	constructors_list();
	copy_operator_list();
	max_size_list();
	front_back_list();
	assign_list();
	push_list();
	swap_list();
	resize_list();
	splice_list();
	remove_list();
	erase_list();
	unique_list();
	merge_list();
	reverse_list();
	operators_list();
	
	// MAP
	print_header_container("Map");
	constructors_map();
	max_size_map();
	access_operator_map();
	insert_map();
	erase_map();
	swap_map();
	clear_map();
	find_map();
	count_map();
	bounds_map();
	range_map();
	operators_comp_map();
}