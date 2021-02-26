/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 06:26:24 by aeoithd           #+#    #+#             */
/*   Updated: 2021/02/26 17:27:10 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP 

# include <cstdlib>
# include <iostream>

namespace ft
{

template <typename V1, typename V2>
    class pair
    {
        public:
            pair() : key(), mapped() {};
            pair(const V1& a, const V2& b) : key(a), mapped(b) {};
            pair(const pair<V1, V2>& copy) : key(copy.key), mapped(copy.mapped) {};
            template <typename U, typename V>
                pair(const pair<U, V>& copy) : key(copy.key), mapped(copy.mapped) {};
            ~pair() {};
            pair& operator=(const pair& assign)
            {
                if (this != &assign)
                {
                    key = assign.key;
                    mapped = assign.mapped;
                }
                return (*this);
            }
            V1 key;
            V2 mapped;
    };

template<typename V>
    struct B_S_T
    {
        V       value;
        ft::pair<const V, T>  set;
        B_S_T*  parent;
        B_S_T*  left;
        B_S_T*  right;
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
        std::cout << root->value << std::endl;
        print_tree(root->left, space);
    };

template<typename V>
int   balance_factor(B_S_T<V> *first)
{
    if (first == NULL)
        return -1;
    else 
    {
        int left_Depth = balance_factor(first->left);
        int right_Depth = balance_factor(first->right);

        if (left_Depth > right_Depth)
            return (left_Depth + 1);
        else
            return (right_Depth + 1);
    }
};

template<typename V>
    int  total_factor(B_S_T<V> *first)
    {
        if (!first)
            return (0);
        return (balance_factor(first->left) - balance_factor(first->right));
    };

template<typename V>
    B_S_T<V>    *balance_tree_root(B_S_T<V> *root) // stops at highest node
    {
        if (root == NULL)
            return (0);
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
        if (!last)
            return (0);
        if (!last->parent)
            return (last);
        B_S_T<V> *old;
        old = last->parent;
        B_S_T<V> *A = old;
        if (total_factor(old) > 1)
        {
            B_S_T<V> *B = old->left;
            if (total_factor(B) >= 0) // LL
            {
                B->parent = A->parent;
                if (B->parent)
                {
                    if (B->parent->right == A)
                        B->parent->right = B;
                    else
                        B->parent->left = B;
                }
                A->parent = B;
                A->left = B->right;
                B->right = A;
                if (A->left)
                    A->left->parent = A;
                return (balance_tree(B));
            }
            else                            //LR
            {
                B_S_T<V> *C = old->left->right;
                if (A->parent->left)
                    A->parent->left = C;
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
        else if (total_factor(old) < -1)
        {
            B_S_T<V> *B = old->right;
            if (total_factor(old->right) <= 0) // RR
            {
                B->parent = A->parent;
                if (B->parent)
                {
                    if (B->parent->right == A)
                        B->parent->right = B;
                    else
                        B->parent->left = B;

                }   
                A->parent = B;
                A->right = B->left;
                B->left = A;
                if (A->right)
                    A->right->parent = A;
                return (balance_tree(B));
            }
            else                                //RL
            {
                B_S_T<V> *C = old->right->left;
                if (A->parent->right)
                    A->parent->right = C;
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
    B_S_T<V>    *create_new_bst(V value)
    {
        B_S_T<V>* newNode = new B_S_T<V>;

        newNode->value = value;
        newNode->parent = 0;
        newNode->left = 0;
        newNode->right = 0;
        return newNode;
    };

template<typename V>
    void    null_and_del_bst(B_S_T<V>* node)
    {
        if (node->parent)
            node->parent = 0;
        if (node->left)
            node->left = 0;
        if (node->right)
            node->right = 0;
        delete node;
    };

template<typename V>
    B_S_T<V>    *max_val_node(B_S_T<V> *first)
    {
        if (first->right)
            return (max_val_node(first->right));
        return (first);
    };

template<typename V>
    B_S_T<V>    *min_val_node(B_S_T<V> *first)
    {
        if (first->left)
            return (min_val_node(first->left));
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
        if (first)
            return (first);
        else
            return (0);
    }

template<typename V>
    B_S_T<V>    *insert_in_tree(B_S_T<V> *first, V ins)
    {
        if (!first)
            return (create_new_bst(ins));
        if (search(first, ins))
            return (first);
        B_S_T<V> *tmp;
        while (first)
        {
            tmp = first;
            if (ins > first->value)
                first = first->right;
            else
                first = first->left;
        }
        B_S_T<V> *newNode = create_new_bst(ins);
        if (ins > tmp->value)
            tmp->right = newNode;
        else
            tmp->left = newNode;
        newNode->parent = tmp;
        return (balance_tree(ins > tmp->value ? tmp->right : tmp->left));
    };

template<typename V>
    B_S_T<V>    *delete_in_tree(B_S_T<V> *first, V ins)
    {
        B_S_T<V> *tmp = search(first, ins);
        if (!tmp)
            return (first);
        
        B_S_T<V> *tmp_left = tmp->left;
        B_S_T<V> *tmp_right = tmp->right;
        if (!tmp->parent)
        {
            if (!tmp_left && !tmp_right)
            {
                null_and_del_bst(tmp);
                return (0);
            }
            else if (tmp_left && !tmp_right)
            {
                tmp_left->parent = 0;
                null_and_del_bst(tmp);
                return (balance_tree_root(tmp_left));
            }
            else if (!tmp_left && tmp_right)
            {
                tmp_right->parent = 0;
                null_and_del_bst(tmp);
                return (balance_tree_root(tmp_right));
            }
            else
            {
                B_S_T<V> *max_node = max_val_node(tmp->left);
                tmp->value = max_node->value;
                if (max_node->parent && max_node->parent->right == max_node)
                {
                    if (max_node->left)
                    {
                        max_node->left->parent = max_node->parent->right;
                        max_node->parent->right = max_node->left;
                    }
                    else
                        max_node->parent->right = 0;
                }    
                null_and_del_bst(max_node);
                return (balance_tree_root(tmp));
            }
        }
        else if (!tmp_left && !tmp_right)
        {
            B_S_T<V> *tmp_parent = tmp->parent;
            if (tmp_parent->left == tmp)
                tmp_parent->left = 0;
            else if (tmp_parent->right == tmp)
                tmp_parent->right = 0;
            null_and_del_bst(tmp);
            if (tmp_parent->parent)
            {
                if (tmp_parent->right)
                    return (balance_tree(tmp_parent->right));
                else if (tmp_parent->left)
                    return (balance_tree(tmp_parent->left));
                else
                    return (balance_tree(tmp_parent));
            }
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
            null_and_del_bst(tmp);
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
            null_and_del_bst(tmp);
            if (tmp_parent->parent)
                return (balance_tree(tmp_parent));
            else
                return (balance_tree_root(tmp_parent));
        }
        else
        {
            B_S_T<V> *max_node = max_val_node(tmp->left);
            if (max_node->parent)
            {
                if (max_node->parent->left == max_node)
                        max_node->parent->left = 0;
                else if (max_node->parent->right == max_node)
                    max_node->parent->right = 0;
                max_node->parent = 0;
            }   
            tmp->value = max_node->value;
            null_and_del_bst(max_node);
            return (balance_tree(tmp));
        }
    };

};

#endif