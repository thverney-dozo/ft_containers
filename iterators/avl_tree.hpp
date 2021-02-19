/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 06:26:24 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/19 07:55:52 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP 

# include <cstdlib>

namespace ft
{


template<typename V>
    struct B_S_T
    {
        V     value;
        size_t  depth;
        B_S_T*   parent;
        B_S_T*   left;
        B_S_T*   right;
    };


template<typename V>
void    print_tree(B_S_T<V> *first) {};

template<typename V>
size_t  balance_factor(B_S_T<V> *first)
{
    if (first == NULL)
        return -1;
    else 
    {
        size_t left_Depth = balance_factor(first->left);
        size_t right_Depth = balance_factor(first->right);

        if (left_Depth > right_Depth)
            return (left_Depth + 1);
        else
            return (right_Depth + 1);
    }
};

template<typename V>
    size_t  total_factor(B_S_T<V> *first)
    {
        return (balance_factor(first->left) - balance_factor(first->right));
    };

template<typename V>
    B_S_T<V>    *balance_tree(B_S_T<V> *first)
    {
        
    };

// template<typename V>
//     B_S_T<V>    *create_new_bst(...) {};

// template<typename V>
//     B_S_T<V>    *insert_in_tree(B_S_T<V> *first, B_S_T<V> *insertion) {};

};

#endif