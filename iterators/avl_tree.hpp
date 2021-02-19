/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 06:26:24 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/19 15:47:38 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP 

# include <cstdlib>
# include <iostream>

namespace ft
{

template<typename V>
    struct B_S_T
    {
        V       value;
        B_S_T*  parent;
        B_S_T*  left;
        B_S_T*  right;
    };

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
    B_S_T<V>    *balance_tree_root(B_S_T<V> *root) // stops at highest node
    {
        if (root == NULL)
            return (NULL);
        B_S_T<V> *old;
        old = root;
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
                return (B);
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
                return (C);
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
                return (B);
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
                return (C);
            }
        }
        return (old);
    };

template<typename V>
    B_S_T<V>    *balance_tree(B_S_T<V> *last) // stops at highest node
    {
        if (last->parent == NULL || last == NULL)
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

        newNode->value = value;
        newNode->parent = parent;
        newNode->left = left;
        newNode->right = right;
        return newNode;
    };

template<typename V>
    B_S_T<V>    *max_val_node(B_S_T<V> *first)
    {
        if (first->right)
            max_val_node(first->right);
        return (first);
    };

template<typename V>
    B_S_T<V>    *min_val_node(B_S_T<V> *first)
    {
        if (first->left)
            min_val_node(first->left);
        return (first);
    };

template<typename V>
    B_S_T<V>    *search(B_S_T<V> *first, V  search)
    {
        while (first && first->value != search)
        {
            if (first->value < search)
                first = first->right;
            else
                first = first->left;
        }
        if (first == NULL)
            return (NULL);
        else
            return (first);
    }

template<typename V>
    B_S_T<V>    *insert_in_tree(B_S_T<V> *first, V ins)
    {
        if (!first)
            return (create_new_bst(NULL, NULL, NULL, ins));
        if (search(first, ins))
            return (NULL);
        B_S_T<V> *tmp;
        while (first)
        {
            tmp = first;
            if (ins > first->value)
                first = first->right;
            else
                first = first->left;
        }
        if (ins > tmp->value)
            tmp->right = create_new_bst(NULL, NULL, tmp, ins);
        else
            tmp->left = create_new_bst(NULL, NULL, tmp, ins);
        return (balance_tree(tmp));
    };

template<typename V>
    B_S_T<V>    *delete_in_tree(B_S_T<V> *first, V ins)
    {
        B_S_T<V> *tmp = search(first, ins);
        if (!tmp)
            return (NULL);
        
        B_S_T<V> *tmp_left = tmp->left;
        B_S_T<V> *tmp_right = tmp->right;
        if (!tmp->parent)
        {
            if (!tmp_left && !tmp_right)
            {
                delete tmp;
                return (NULL);
            }
            else if (tmp_left && !tmp_right)
            {
                delete tmp;
                tmp_left->parent = NULL;
                return (balance_tree_root(tmp_left));
            }
            else if (!tmp_left && tmp_right)
            {
                delete tmp;
                tmp_right->parent = NULL;
                return (balance_tree_root(tmp_right));
            }
            else
            {
                B_S_T<V> *max_node = max_val_node(tmp->left)
                tmp->value = max_node->value;
                delete max_node;
                return (balance_tree_root(tmp));
            }
        }
        else if (!tmp_left && !tmp_right)
        {
            B_S_T<V> *tmp_parent = tmp->parent;
            delete tmp;
            if (tmp_parent->parent)
                return (balance_tree(tmp_parent));
            else
                return (balance_tree_root(tmp_parent));
        }
        else if (tmp_left && !tmp_right)
        {
            B_S_T<V> *tmp_parent = tmp->parent;
            if (tmp->value < tmp->parent->value)
                tmp->parent->left = tmp->left;
            else
                tmp->parent->right = tmp->left;
            delete tmp;
            if (tmp_parent->parent)
                return (balance_tree(tmp_parent));
            else
                return (balance_tree_root(tmp_parent));
        }
        else if (!tmp_left && tmp_right)
        {
            B_S_T<V> *tmp_parent = tmp->parent;
            if (tmp->value < tmp->parent->value)
                tmp->parent->left = tmp->right;
            else
                tmp->parent->right = tmp->right;
            delete tmp;
            if (tmp_parent->parent)
                return (balance_tree(tmp_parent));
            else
                return (balance_tree_root(tmp_parent));
        }
        else
        {
            B_S_T<V> *max_node = max_val_node(tmp->left)
            tmp->value = max_node->value;
            delete max_node;
            return (balance_tree(tmp));
        }
    };

template<typename V>
    void print_tree(B_S_T<V> *root, int space)// root, space == 0
    {
        if (root == NULL)
            return;
        space += 10;
        print_tree(root->right, space);
        std::cout << std::endl;
        for (int i = 10; i < space; i++)
            std::cout << " ";
        std::cout << root->data << std::endl;
        print_tree(root->left, space);
    };

};

#endif