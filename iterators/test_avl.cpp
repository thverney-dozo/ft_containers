# include "./avl_tree.hpp"
# include <string>

int     main()
{
    ft::B_S_T<int> *first = ft::create_new_bst(30);

    ft::print_tree(first, 0);
    std::cout << "#####################[30 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 20);
    ft::print_tree(first, 0);
    std::cout << "#####################[20 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 10);
    ft::print_tree(first, 0);
    std::cout << "#####################[10 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 50);
    ft::print_tree(first, 0);
    std::cout << "#####################[50 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 35);
    ft::print_tree(first, 0);
    std::cout << "#####################[35 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 9);
    ft::print_tree(first, 0);
    std::cout << "#####################[9 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 8);
    ft::print_tree(first, 0);
    std::cout << "#####################[8 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 7);
    ft::print_tree(first, 0);
    std::cout << "#####################[7 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 6);
    ft::print_tree(first, 0);
    std::cout << "#####################[6 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 5);
    ft::print_tree(first, 0);
    std::cout << "#####################[5 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 4);
    ft::print_tree(first, 0);
    std::cout << "#####################[4 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 3);
    ft::print_tree(first, 0);
    std::cout << "#####################[3 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 2);
    ft::print_tree(first, 0);
    std::cout << "#####################[2 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 1);
    ft::print_tree(first, 0);
    std::cout << "#####################[1 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 0);
    ft::print_tree(first, 0);
    std::cout << "#####################[0 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 51);
    ft::print_tree(first, 0);
    std::cout << "#####################[51 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 52);
    ft::print_tree(first, 0);
    std::cout << "#####################[52 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 53);
    ft::print_tree(first, 0);
    std::cout << "#####################[53 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 54);
    ft::print_tree(first, 0);
    std::cout << "#####################[54 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 55);
    ft::print_tree(first, 0);
    std::cout << "#####################[55 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 56);
    ft::print_tree(first, 0);
    std::cout << "#####################[56 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 57);
    ft::print_tree(first, 0);
    std::cout << "#####################[57 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 58);
    ft::print_tree(first, 0);
    std::cout << "#####################[58 inserted]########################" << std::endl;
    first = ft::insert_in_tree(first, 59);
    ft::print_tree(first, 0);
    std::cout << "#####################[59 inserted]########################" << std::endl;
    first = ft::delete_in_tree(first, 20);
    ft::print_tree(first, 0);
    std::cout << "#####################[20 deleted]########################" << std::endl;
    ft::print_tree(first, 0);

}