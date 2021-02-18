/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 05:08:56 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/18 11:32:02 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_helpers.hpp"

#include <list>
#include <stdlib.h>

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
static void print_list(T &list)
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

static void constructors(void)
{
	print_header("Default constructor");
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	check("(default) l1 == l2", l1 == l2);
	ft::list<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	check("(fill with default value) l3 == l4", l3 == l4);
	ft::list<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	check("(fill) l5 == l6", l5 == l6);
	ft::list<int> l7(test, test + 4);
	std::list<int> l8(test, test + 4);
	check("(iterator) l7 == l8", l7 == l8);
	ft::list<int> l9(l7);
	std::list<int> l10(l8);
	check("(copy) l9 == l10", l9 == l10);
}

static void copy_operator(void)
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

static void max_size(void)
{
	print_header("Max size");
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<std::string> l3;
	std::list<std::string> l4;
	check("l1.max_size() == l2.max_size()", l1.max_size(), l2.max_size());
	check("l3.max_size() == l4.max_size()", l3.max_size(), l4.max_size());
}

static void front_back(void)
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

static void assign(void)
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

static void push(void)
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

static void swap(void)
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

static void resize(void)
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

static void splice(void)
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

static bool even(const int& value) { return (value % 2) == 0; } 

static void remove(void)
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
	l1.remove_if(even);
	l2.remove_if(even);
	check("l1 == l2", l1 == l2);
}

static void erase(void)
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

static bool compare(int a, int b) 
{ 
    return (a >= b); 
} 

static void unique()
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
	l1.unique(compare);
	l2.unique(compare);
	check("l1 == l2", l1 == l2);
}

static bool compare2(int a, int b) 
{ 
    return (a == b); 
} 

static void merge(void)
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
	l1.merge(l3, compare2);
	l2.merge(l4, compare2);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static void reverse(void)
{
	print_header("Reverse");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	check("l1 == l2", l1 == l2);
}

static void operators(void)
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

static void constructors_queue(void)
{
	print_header("Constructor");
	ft::queue<int> q1;
	std::queue<int> q2;
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

static void front_back_queue(void)
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

static void constructors_stack(void)
{
	print_header("Constructor");
	ft::stack<int> q1;
	std::stack<int> q2;
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

static void front_back_stack(void)
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
static void print_vector(T vec, std::string type)
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
static void print_vector_reverse(T vec, std::string type)
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

static void default_constructor_vector(void)
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
}

static void copy_constructor_vector(void)
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

static void max_size_vector(void)
{
	print_header("Max size");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
	v1.push_back("test");
	v2.push_back("test");
	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
}

static void resize_vector(void)
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

static void access_operator_vector(void)
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
		std::cout << "v1.at(100):  " << v1.at(100) << ": " << FAIL << std::endl;
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
		std::cout << "v1.at(-1):  " << v1.at(-1) << ": " << FAIL  << std::endl;
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

static void front_back_vector(void)
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

static void assign_vector(void)
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

static void insert_vector(void)
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

static void erase_vector(void)
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

static void swap_vector(void)
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

static void operators_vector(void)
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

void	test_vector(void)
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
	constructors();
	copy_operator();
	max_size();
	front_back();
	assign();
	push();
	swap();
	resize();
	splice();
	remove();
	erase();
	unique();
	merge();
	reverse();
	operators();
}