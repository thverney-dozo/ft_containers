#include <vector>
#include "containers/vector/vector.hpp"
#include "test.hpp"

#define NB_TESTS 17

static bool equal_operator_test()
{
	ft::vector<int> k(3, 0);
	ft::vector<int> l(5, 0);

	l = k;
	k = ft::vector<int>();

	if (l.size() != 3 || k.size() != 0)
		return (FAILURE);
	return (SUCCESS);
}

static bool begin_end_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		(void)*it;
	return (SUCCESS);
}

static bool rbegin_rend_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);
	for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		(void)*it;
	return (SUCCESS);
}

static bool size_test()
{
	ft::vector<int> v;

	if (v.size())
		return (FAILURE);
	v.push_back(42);
	if (v.size() != 1)
		return (FAILURE);
	for (int i = 0; i < 10; i++)
		v.push_back(42);
	if (v.size() != 11)
		return (FAILURE);
	return (SUCCESS);
}

static bool max_size_test()
{
	std::vector<int> u;
	ft::vector<int> v;

	return (u.max_size() == v.max_size());
}

static bool resize_test()
{
	ft::vector<int> v;

	v.resize(10, 42);
	if (v.size() != 10 || v.back() != 42)
		return (FAILURE);
	v.resize(5, 3);
	if (v.size() != 5 || v.back() != 42)
		return (FAILURE);
	return (SUCCESS);
}

static bool empty_test()
{
	ft::vector<int> v;

	if (!v.empty())
		return (FAILURE);
	v.push_back(1);
	if (v.empty())
		return (FAILURE);
	return (SUCCESS);
}

static bool capacity_reserve_test()
{
	ft::vector<int> v;

	v.reserve(50);
	if (v.size() > 0 || v.capacity() < 50)
		return (FAILURE);
	return (SUCCESS);
}

static bool array_access_operator_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i * 2);
	for (int i = 0; i < 10; i++)
	{
		if (v[i] != i * 2)
			return (FAILURE);
	}
	v[4] = 42;
	if (v[4] != 42)
		return (FAILURE);
	return (SUCCESS);
}

static bool at_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i * 2);
	for (int i = 0; i < 10; i++)
	{
		if (v.at(i) != i * 2)
			return (FAILURE);
	}
	v.at(4) = 42;
	if (v[4] != 42)
		return (FAILURE);
	return (SUCCESS);
}

static bool front_back_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
		if (v.front() != 0 || v.back() != i)
			return (FAILURE);
	}
	return (SUCCESS);
}

static bool assign_test()
{
	ft::vector<int> v;
	ft::vector<int> v2;

	v.assign(5, 7);
	if (v.size() != 5 || v.front() != 7 || v.back() != 7)
		return (FAILURE);
	for (int i = 0; i < 7; i++)
		v2.push_back(i);
	v.assign(v2.begin(), v2.end());
	if (v.size() != 7 || v.front() != 0 || v.back() != 6)
		return (FAILURE);
	return (SUCCESS);
}

static bool push_pop_back_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for (int i = 0; i < 10; i++)
		if (v[i] != i)
			return (FAILURE);
	while (v.size() > 0)
		v.pop_back();
	return (SUCCESS);
}

static bool insert_test()
{
	ft::vector<int> u;
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		u.push_back(i);
	v.insert(v.begin(), u.begin(), u.end());
	if (v.size() != 10 || v.front() != 0 || v.back() != 9)
		return (FAILURE);
	return (SUCCESS);
}

static bool erase_test()
{
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	v.erase(v.begin(), v.end());
	if (v.size())
		return (FAILURE);
	return (SUCCESS);
}

static bool swap_test()
{
	ft::vector<int> u;
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		u.push_back(i);
	for (int i = 10; i < 15; i++)
		v.push_back(i);
	u.swap(v);
	if (u.size() != 5 || v.size() != 10 || u.back() != 14 || v.back() != 9)
		return (FAILURE);
	return (SUCCESS);
}

static bool equal_test()
{
	ft::vector<int> u;
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		u.push_back(i);
	v.insert(v.begin(), u.begin(), u.end());
	if (u != v)
		return (FAILURE);
	u.pop_back();
	if (u == v)
		return (FAILURE);
	return (SUCCESS);
}

static bool less_test()
{
	ft::vector<int> u;
	ft::vector<int> v;

	for (int i = 0; i < 3; i++)
		u.push_back(i);
	for (int i = 0; i < 4; i++)
		v.push_back(i);
	if (u >= v)
		return (FAILURE);
	u[2] = 42;
	if (v >= u)
		return (FAILURE);
	return (SUCCESS);
}

void test_vector()
{
	size_t tot = 0;

	std::cout << "* \033[36mVECTOR TESTS\033[0m\n" << std::endl;

	tot += test(equal_operator_test(), "equal_operator");
	tot += test(begin_end_test(), "being / end");
	tot += test(rbegin_rend_test(), "rbegin / rend");
	tot += test(size_test(), "size");
	tot += test(max_size_test(), "max_size");
	tot += test(resize_test(), "resize");
	tot += test(empty_test(), "empty");
	tot += test(array_access_operator_test(), "array_access_operator");
	tot += test(at_test(), "at");
	tot += test(front_back_test(), "front / back");
	tot += test(assign_test(), "assign");
	tot += test(push_pop_back_test(), "push_back / pop_back");
	tot += test(insert_test(), "insert");
	tot += test(erase_test(), "erase");
	tot += test(swap_test(), "swap");
	tot += test(equal_test(), "equal");
	tot += test(less_test(), "less");

	std::cout << std::endl;

	if (tot != NB_TESTS)
		std::cout << "* \033[31m";
	else
		std::cout << "* \033[36m";
	std::cout << "Score: " << tot << "/" << NB_TESTS << "\033[0m" << std::endl;
}

