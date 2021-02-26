/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:47:08 by thverney          #+#    #+#             */
/*   Updated: 2021/02/26 19:12:46 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <limits>
# include <utility>
# include "../iterators/ft_pair.hpp"
# include "../iterators/map_iterator.hpp"

namespace ft
{
    template <class Key, class T, class Compare=std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
    {
        private:        

            struct B_S_T
            {
                ft::pair<const Key, T>  set;
                B_S_T*                  parent;
                B_S_T*                  left;
                B_S_T*                  right;
            };

        public:
            typedef Key                                                                 key_type;
			typedef T                                                                   mapped_type;
			typedef std::pair<const key_type, mapped_type>                              value_type;
			typedef Compare                                                             key_compare;
			typedef Alloc                                                               allocator_type;
			typedef T&                                                                  reference;
			typedef const T&                                                            const_reference;
			typedef T*                                                                  pointer;
			typedef const T*                                                            const_pointer;
			typedef unsigned long                                                       size_type;
			typedef typename ft::map_iterator<Key, T, Compare, B_S_T, false>            iterator;
            typedef typename ft::map_iterator<Key, T, Compare, B_S_T, true>             const_iterator;
			typedef typename ft::reverse_map_iterator<Key, T, Compare, B_S_T, false>    reverse_iterator;
            typedef typename ft::reverse_map_iterator<Key, T, Compare, B_S_T, true>     const_reverse_iterator;
        
        private:

            B_S_T*                   _firstNd;          // Pointer to the first element of the tree (root)
            B_S_T*                   _lastNd;      // Pointer to the last elem of the tree
            size_type               _size_value;          // Number of T values inside the map
            allocator_type          _alloc_pair;     // Copy of allocator_type object
            key_compare             _compare;          // Copy of comp key_compare predicate
            std::allocator<B_S_T>   _alloc_node;     
        
        public:
            explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()){};
                    
            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()){};
            
            map (const map& x){};
            map& operator= (const map& x){};
            ~map(){};
            iterator begin(void) {};
			const_iterator begin(void) const {};
			iterator end(void) {};
			const_iterator end(void) const {};
			reverse_iterator rbegin(void) {};
			const_reverse_iterator rbegin(void) const {};
			reverse_iterator rend(void) {};
			const_reverse_iterator rend(void) const {};
            bool empty() const {};
            size_type size() const {};
            size_type max_size() const {};
            mapped_type& operator[] (const key_type& k) {};
            pair<iterator,bool> insert (const value_type& val) {};
            iterator insert (iterator position, const value_type& val) {};
            template <class InputIterator>
                void insert (InputIterator first, InputIterator last) {};
            void erase (iterator position) {};
            size_type erase (const key_type& k) {};
            void erase (iterator first, iterator last) {};
            void swap (map& x) {};
            void clear() {};
            key_compare key_comp() const {};
            value_compare value_comp() const {};
            iterator find (const key_type& k) {};
            const_iterator find (const key_type& k) const {};
            size_type count (const key_type& k) const {};
            iterator lower_bound (const key_type& k) {};
            const_iterator lower_bound (const key_type& k) const {};
            iterator upper_bound (const key_type& k) {};
            const_iterator upper_bound (const key_type& k) const {};
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const {};
            pair<iterator,iterator>             equal_range (const key_type& k) {};
            allocator_type get_allocator() const {};
        private:
            
            int   balance_factor(B_S_T *first)
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

            int  total_factor(B_S_T *first)
            {
                if (!first)
                    return (0);
                return (balance_factor(first->left) - balance_factor(first->right));
            };

            B_S_T    *balance_tree_root(B_S_T *root) // stops at highest node
            {
                if (root == NULL)
                    return (0);
                B_S_T *old;
                old = root;
                B_S_T *A = old;
                if (total_factor(old) > 1)
                {
                    B_S_T *B = old->left;
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
                        B_S_T *C = old->left->right;
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
                if (total_factor(old) < -1)
                {
                    B_S_T *B = old->right;
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
                        B_S_T *C = old->right->left;
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
                return (old);
            };

            B_S_T    *balance_tree(B_S_T *last) // stops at highest node
            {
                if (!last)
                    return (0);
                if (!last->parent)
                    return (last);
                B_S_T *old;
                old = last->parent;
                B_S_T *A = old;
                if (total_factor(old) > 1)
                {
                    B_S_T *B = old->left;
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
                        B_S_T *C = old->left->right;
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
                    B_S_T *B = old->right;
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
                        B_S_T *C = old->right->left;
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

            B_S_T    *create_new_bst(const value_type& pair)
            {
                B_S_T* newNode = _allocNode.allocate(1);
                _allocPair.construct(&newNode->set, pair);
                newNode->parent = 0;
                newNode->left = 0;
                newNode->right = 0;
                return (newNode);
            };

            void    null_and_del_bst(B_S_T* node)
            {
                if (node->parent)
                    node->parent = 0;
                if (node->left)
                    node->left = 0;
                if (node->right)
                    node->right = 0;
                _alloc_pair.destroy(&node->set);
                _alloc_node.deallocate(node, 1);
            };

            B_S_T    *max_val_node(B_S_T *first)
            {
                if (first->right)
                    return (max_val_node(first->right));
                return (first);
            };

            B_S_T    *min_val_node(B_S_T *first)
            {
                if (first->left)
                    return (min_val_node(first->left));
                return (first);
            };

            B_S_T    *search(B_S_T *first, key_type key)
            {
                if (!first || first == _lastNd)
                    return (0);
                while (first && first->set.key != search)
                {
                    if (first->set.key < search)
                        first = first->right;
                    else
                        first = first->left;
                }
                if (first)
                    return (first);
                else
                    return (0);
            }

            B_S_T    *insert_in_tree(B_S_T *first, const value_type& ins)
            {
                if (!first)
                    return (create_new_bst(ins));
                if (search(first, ins))
                    return (first);
                B_S_T *tmp;
                while (first)
                {
                    tmp = first;
                    if (ins.key > first->set.key)
                        first = first->right;
                    else
                        first = first->left;
                }
                B_S_T *newNode = create_new_bst(ins);
                if (ins.key > tmp->set.key)
                    tmp->right = newNode;
                else
                    tmp->left = newNode;
                newNode->parent = tmp;
                return (balance_tree(ins.key > tmp->set.key ? tmp->right : tmp->left));
            };

            B_S_T    *delete_in_tree(B_S_T *first, key_type key)
            {
                B_S_T *tmp = search(first, key);
                if (!tmp)
                    return (first);
                B_S_T *tmp_left = tmp->left;
                    B_S_T *tmp_right = tmp->right;
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
                            B_S_T *max_node = max_val_node(tmp->left);
                            tmp->set.key = max_node->set.key;
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
                        B_S_T *tmp_parent = tmp->parent;
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
                        B_S_T *tmp_parent = tmp->parent;
                        if (tmp->set.key < tmp->parent->set.key)
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
                        B_S_T *tmp_parent = tmp->parent;
                        if (tmp->set.key < tmp->parent->set.key)
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
                        B_S_T *max_node = max_val_node(tmp->left);
                        if (max_node->parent)
                        {
                            if (max_node->parent->left == max_node)
                                    max_node->parent->left = 0;
                            else if (max_node->parent->right == max_node)
                                max_node->parent->right = 0;
                            max_node->parent = 0;
                        }   
                        tmp->set.key = max_node->set.key;
                        null_and_del_bst(max_node);
                        return (balance_tree(tmp));
                    }
                };

    };
    template <class Key, class T, class Compare, class Alloc>
	void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y) {};
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b) {};
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b) {};
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b) {};
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b) {};
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b) {};
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b) {};

}

#endif