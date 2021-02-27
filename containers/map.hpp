/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:47:08 by thverney          #+#    #+#             */
/*   Updated: 2021/02/27 15:13:32 by aeoithd          ###   ########.fr       */
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

            B_S_T*                  _firstNd;
            B_S_T*                  _afterLast;
            size_type               _size_value;
            allocator_type          _alloc_pair;
            key_compare             _compare;
            std::allocator<B_S_T>   _alloc_node; 
    
        
        public:
            explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()) :
                _size_value(0), _alloc_pair(alloc), _compare(comp)
            {
                _afterLast = create_new_bst(ft::pair<const key_type, mapped_type>());
                _firstNd = _afterLast;
                _afterLast->left = _afterLast;
                _afterLast->right = _afterLast;
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0) :
                    _size_value(0), _alloc_pair(alloc), _compare(comp)
            {
                _afterLast = createNode(ft::pair<const key_type, mapped_type>());
                _firstNd = _afterLast;
                _afterLast->left = _afterLast;
                _afterLast->right = _afterLast;
                while (first != last)
                {
                    first++;
                    insert(*first);
                }
            };
            
            map (const map& x) :
                _size_value(0), _alloc_pair(x._alloc_pair), _compare(x._compare), _alloc_node(x._alloc_node)
            {
                _afterLast = createNode(ft::pair<const key_type, mapped_type>());
                _firstNd = _afterLast;
                _afterLast->left = _afterLast;
                _afterLast->right = _afterLast;
                for (iterator it = x.begin(); it != x.end(); ++it)
                    insert(*it);
            }
            map& operator=(const map& x)
            {
                map tmp(x);
                this->swap(tmp);
                return *this;
            };
            ~map()
            {
                clear();
                null_and_del_bst(_afterLast);
            };
            iterator begin()                        { return iterator(_afterLast->right, _afterLast, _compare); }
            const_iterator begin() const            { return const_iterator(_afterLast->right, _afterLast, _compare); }
            iterator end()                          { return iterator(_afterLast, _afterLast, _compare); }
            const_iterator end() const              { return const_iterator(_afterLast, _afterLast, _compare); }
            reverse_iterator rbegin()               { return reverse_iterator(_afterLast->left, _afterLast, _compare); }
            const_reverse_iterator rbegin() const   { return const_reverse_iterator(_afterLast->left, _afterLast, _compare); }
            reverse_iterator rend()                 { return reverse_iterator(_afterLast, _afterLast, _compare); }
            const_reverse_iterator rend() const     { return const_reverse_iterator(_afterLast, _afterLast, _compare); }
            
            bool empty() const {};
            size_type size() const {};
            size_type max_size() const {};
            mapped_type& operator[] (const key_type& k) {};
            pair<iterator,bool> insert (const value_type& val)
            {
                B_S_T* ins = search(_firstNd, val.first);
                if (ins)
                    return ft::pair<iterator, bool>(iterator(ins, _afterLast, _compare), false);
                _size_value++;
                return ft::pair<iterator, bool>(iterator(insert_in_tree(_firstNd, val), _afterLast, _compare), true);
            };
            iterator insert (iterator position, const value_type& val)
            {
                if (position->_ptr > val.key)
                {
                    iterator prev(position);
                    prev--;
                    while (prev != end() && prev->_ptr >= val.key)
                    {
                        position--;
                        prev--;
                    }
                }
                else if (position->_ptr < val.key)
                {
                    iterator next(position);
                    next++;
                    while (next != end() && next->_ptr <= val.key)
                    {
                        position++;
                        next++;
                    }
                }
                if (position != end() && val.key == position->_ptr)
                    return position;
                _size_value++;
                return iterator(insertNode(position.getNode(), val), _afterLast, _compare);
            };
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
                if (first == NULL || first == _afterLast)
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

            B_S_T    *create_new_bst(const value_type& new_bst)
            {
                B_S_T* newNode = _allocNode.allocate(1);
                _alloc_pair.construct(&newNode->set, new_bst);
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
                if (first->right && first->right != _afterLast)
                    return (max_val_node(first->right));
                return (first);
            };

            B_S_T    *min_val_node(B_S_T *first)
            {
                if (first->left && first->left != _afterLast)
                    return (min_val_node(first->left));
                return (first);
            };

            B_S_T    *search(B_S_T *first, key_type key)
            {
                if (!first || first == _afterLast)
                    return (0);
                while (first && first->set.key != search && first != _afterLast)
                {
                    if (first->set.key < search)
                        first = first->right;
                    else
                        first = first->left;
                }
                if (first && first != _afterLast)
                    return (first);
                else
                    return (0);
            }

            B_S_T    *insert_in_tree(B_S_T *first, const value_type& ins)
            {
                if (_firstNd == _afterLast)
                {
                    _firstNd = createNode(ins);
                    _firstNd->left = _afterLast;
                    _firstNd->right = _afterLast;
                    _afterLast->left = _firstNd;
                    _afterLast->right = _firstNd;
                    return (_firstNd);
                }
                if (search(first, ins))
                    return (first);
                if (first->set.key > ins.key && first->left && first->left != _afterLast)
                    return (insertNode(first->left, ins));
                else if (first->set.key < ins.key && first->right && first->right != _afterLast)
                    return (insertNode(first->right, ins));
                B_S_T *newNode = create_new_bst(ins);
                if (first->set.key > newNode->set.key && !first->left)
                    first->left = newNode;
                else if (first->set.key < newNode->set.key && !first->right)
                    first->right = newNode;
                else if (first->left && first->set.key > newNode->set.key)
                {
                    newNode->left = _afterLast;
                    _afterLast->right = newNode;
                    first->left = newNode;
                }
                else if (first->right && first->set.key < newNode->set.key)
                {
                    newNode->right = _afterLast;
                    _afterLast->left = newNode;
                    first->right = newNode;
                }
                newNode->parent = first;
                return (balance_tree(newNode));
            };

            bool    delete_in_tree(B_S_T *first, key_type key)
            {
                B_S_T *tmp = search(first, key);
                if (!tmp)
                    return (false);
                B_S_T *tmp_parent = tmp->parent;
                if (!tmp->parent)
                {
                    if (tmp->left == _afterLast && tmp->right == _afterLast)
                    {
                        _firstNd = _afterLast;
                        _afterLast->left = _afterLast;
                        _afterLast->right = _afterLast;
                    }
                    else if (tmp->left && tmp->right == _afterLast)
                    {
                        _firstNd = tmp->left;
                        tmp->left->parent = 0;
                        _afterLast->left = tmp->left;
                        tmp->left->right = _afterLast;
                    }
                    else if (tmp->left == _afterLast && tmp->right)
                    {
                        _firstNd = tmp->right;
                        tmp->right->parent = 0;
                        _afterLast->right = tmp->right;
                        tmp->right->left = _afterLast;
                    }
                    else
                    {
                        B_S_T* maxNode = searchMaxNode(tmp->left);
                        _alloc_pair.destroy(&tmp->set);
                        _alloc_pair.construct(&tmp->set, maxNode->set);
                        return (delete_in_tree(tmp->left, maxNode->set.key));
                    }
                }
                else if ((!tmp->left || tmp->left == _afterLast) && (!tmp->right || tmp->right == _afterLast))
                {
                    B_S_T* toparent = 0;
                    if (tmp->left == _afterLast || tmp->right == _afterLast)
                    {
                        toparent = _afterLast;
                        tmp->set.key <= tmp->parent->set.key ? _afterLast->right = tmp->parent : _afterLast->left = tmp->parent;
                    }
                    tmp->set.key <= tmp->parent->set.key ? tmp->parent->left = toparent : tmp->parent->right = toparent;
                }
                else if ((tmp->left && tmp->left != _afterLast) && (!tmp->right || tmp->right == _afterLast))
                {
                    tmp->set.key <= tmp->parent->set.key ? tmp->parent->left = tmp->left : tmp->parent->right = tmp->left;
                    tmp->left->parent = tmp->parent;
                    if (tmp->right == _afterLast) { _afterLast->left = tmp->left; tmp->left->right = _afterLast; }
                }
                else if ((!tmp->left || tmp->left == _afterLast) && tmp->right && tmp->right != _afterLast)
                {
                    tmp->set.key <= tmp->parent->set.key ? tmp->parent->left = tmp->right : tmp->parent->right = tmp->right;
                    tmp->right->parent = tmp->parent;
                    if (tmp->left == _afterLast) { _afterLast->right = tmp->right; tmp->right->left = _afterLast; }
                }
                else
                {
                    B_S_T* maxNode = searchMaxNode(tmp->left);
                    _alloc_pair.destroy(&tmp->set);
                    _alloc_pair.construct(&tmp->set, maxNode->set);
                    return delete_in_tree(tmp->left, maxNode->set.key);
                }
                balance_tree(tmp_parent);
                null_and_del_bst(tmp);
                return true;
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