# include "./avl_tree.hpp"
# include <string>

int     main()
{
    ft::B_S_T<int> *first = ft::create_new_bst(30);
    
    // ft::print_tree(first, 0);
    std::cout << "#############################################" << std::endl;
    ft::insert_in_tree(first, 20);
    // ft::print_tree(first, 0);
    std::cout << "#############################################" << std::endl;
    ft::insert_in_tree(first, 10);
    ft::print_tree(first, 0);
    std::cout << "#############################################" << std::endl;
    // ft::insert_in_tree(first, 50);
    // ft::insert_in_tree(first, 25);


}