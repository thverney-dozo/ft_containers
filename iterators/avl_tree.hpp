/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 06:26:24 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/19 11:19:59 by aeoithd          ###   ########.fr       */
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
    B_S_T<V>    *balance_tree(B_S_T<V> *last) // stops at highest node
    {
        if (last->parent == NULL)
            return (last);
        B_S_T<V> *old;
        old = last->parent;
        B_S_T<V> *A = old;
        if (total_factor(old) > 1)
        {
            B_S_T<V> *B = old->left;
            if (total_factor(old->left) >= 0) // LL
            {
                B->parent = A->parent;
                A->parent = B;
                A->left = B->right;
                B->right = A;
                return (balance_tree(B));
            }
            else                            //LR
            {
                B_S_T<V> *C = old->left->right;
                B->parent = C;
                C->parent = A->parent;
                A->parent = C;
                A->left = C->right;
                B->right = C->left;
                C->left = B;
                C->right = A;
                return (balance_tree(C));
            }
        }
        if (total_factor(old) < -1)
        {
            B_S_T<V> *B = old->right;
            if (total_factor(old->right) >= 0) // RR
            {
                B->parent = A->parent;
                A->parent = B;
                A->right = B->left;
                B->left = A;
                return (balance_tree(B));
            }
            else                                //RL
            {
                B_S_T<V> *C = old->right->left;
                C->parent = A->parent;
                A->parent = C;
                B->parent = C;
                A->right = C->left;
                B->left = C->right;
                C->right = B;
                C->left = A;
                return (balance_tree(C));
            }
        }
        return (balance_tree(old));
    };

template<typename V>
    B_S_T<V>    *create_new_bst(B_S_T<V> *left, B_S_T<V> *right, B_S_T<V> *parent, V value)
    {
        B_S_T<V>* newNode = new B_S_T<V>;

        newNode->data = value;
        newNode->parent = parent;
        newNode->left = left;
        newNode->right = right;
        return newNode;
    };

template<typename V>
    B_S_T<V>    *max_val_node(B_S_T<V> *first)
    {
        while (first->right)
            first = first->right;
        return (first);
    };

template<typename V>
    B_S_T<V>    *min_val_node(B_S_T<V> *first)
    {
        while (first->left)
            first = first->left;
        return (first);
    };


// template<typename V>
//     B_S_T<V>    *insert_in_tree(B_S_T<V> *first, B_S_T<V> *insertion) {};

};

#endif