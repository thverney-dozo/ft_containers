#include "test.hpp"
#include <iomanip>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "-------------------------------" << std::endl;
		test_vector();
		std::cout << "-------------------------------" << std::endl;
	}
	else if (ac == 2)
	{
		switch (*av[1])
		{
			case 'v': test_vector(); break;
			default: std::cout << "Error: Invalid container: " << av[1] << std::endl; break;
		}
	}
	else
	{
		std::cout << "Usage: ./tester [container]" << std::endl;
	}
	return (0);
}

bool test(bool result, std::string const& test_name)
{
	size_t padding = 38 - test_name.length();

	std::cout << "> " << "\033[93m" << test_name << "\033[0m";
	if (result)
	{
		std::cout << std::setw(padding) << "\033[32m[ok]\033[0m" << std::endl;
		return (SUCCESS);
	}
	else
	{
		std::cout << std::setw(padding) << "\033[31m[ko]\033[0m" << std::endl;
		return (FAILURE);
	}
}

