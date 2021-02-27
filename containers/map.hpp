/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:47:08 by thverney          #+#    #+#             */
/*   Updated: 2021/02/27 19:12:47 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <limits>
# include <utility>
# include "../iterators/map_iterator.hpp"

namespace ft
{
    template <class Key, class T, class Compare=std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
    {
        private:        

            struct B_S_T
            {
                std::pair<Key, T>       set;
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
        
            // map::value_compare nested class
            class value_compare
            {
                friend class map;
                protected:
                    key_compare comp;
                    value_compare(Compare c) : comp(c) {}
                public:
                    typedef bool        result_type;
                    typedef value_type  first_argument_type;
                    typedef value_type  second_argument_type;
                    bool operator()(const value_type& x, const value_type& y) const
                    { return comp(x.first, y.first); }
            };
        /*
               _ _____ _____ ___ ___ ___ _   _ _____ ___ ___ 
              /_\_   _|_   _| _ \_ _| _ ) | | |_   _| __/ __|
             / _ \| |   | | |   /| || _ \ |_| | | | | _|\__ \
            /_/ \_\_|   |_| |_|_\___|___/\___/  |_| |___|___/
        */
        private:

            B_S_T*                  _firstNd;
            B_S_T*                  _afterLast;
            size_type               _size_value;
            allocator_type          _alloc_pair;
            key_compare             _compare;
            std::allocator<B_S_T>   _alloc_node; 

        /*		 ██████╗ ██████╗ ██████╗ ██╗     ██╗███████╗███╗   ██╗    ███████╗ ██████╗ ██████╗ ███╗   ███╗
				██╔════╝██╔═══██╗██╔══██╗██║     ██║██╔════╝████╗  ██║    ██╔════╝██╔═══██╗██╔══██╗████╗ ████║
				██║     ██║   ██║██████╔╝██║     ██║█████╗  ██╔██╗ ██║    █████╗  ██║   ██║██████╔╝██╔████╔██║
				██║     ██║   ██║██╔═══╝ ██║     ██║██╔══╝  ██║╚██╗██║    ██╔══╝  ██║   ██║██╔══██╗██║╚██╔╝██║
				╚██████╗╚██████╔╝██║     ███████╗██║███████╗██║ ╚████║    ██║     ╚██████╔╝██║  ██║██║ ╚═╝ ██║
				 ╚═════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝╚══════╝╚═╝  ╚═══╝    ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝                                                                  
        */
        public:
            explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()) :
                _size_value(0), _alloc_pair(alloc), _compare(comp)
            {
                _afterLast = create_new_bst(std::pair<const key_type, mapped_type>());
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
                _afterLast = createNode(std::pair<const key_type, mapped_type>());
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
                _afterLast = createNode(std::pair<const key_type, mapped_type>());
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
            /*
                 ___ _____ ___ ___    _ _____ ___  ___  ___ 
                |_ _|_   _| __| _ \  /_\_   _/ _ \| _ \/ __|
                 | |  | | | _||   / / _ \| || (_) |   /\__ \
                |___| |_| |___|_|_\/_/ \_\_| \___/|_|_\|___/
            */
            iterator begin()                        { return iterator(_afterLast->right, _afterLast, _compare); }
            const_iterator begin()            const { return const_iterator(_afterLast->right, _afterLast, _compare); }
            iterator end()                          { return iterator(_afterLast, _afterLast, _compare); }
            const_iterator end()              const { return const_iterator(_afterLast, _afterLast, _compare); }
            reverse_iterator rbegin()               { return reverse_iterator(_afterLast->left, _afterLast, _compare); }
            const_reverse_iterator rbegin()   const { return const_reverse_iterator(_afterLast->left, _afterLast, _compare); }
            reverse_iterator rend()                 { return reverse_iterator(_afterLast, _afterLast, _compare); }
            const_reverse_iterator rend()     const { return const_reverse_iterator(_afterLast, _afterLast, _compare); }
            
            /*
                  ___   _   ___  _   ___ ___ _______   __
                 / __| /_\ | _ \/_\ / __|_ _|_   _\ \ / /
                | (__ / _ \|  _/ _ \ (__ | |  | |  \ V / 
                 \___/_/ \_\_|/_/ \_\___|___| |_|   |_|  
            */
            bool empty()                      const { return (_size_value == 0); };
            size_type size()                  const { return (_size_value); };
            size_type max_size() const
            {
                return (std::numeric_limits<size_type>::max() / (sizeof(B_S_T)));
            };
            /*
                 ___ _    ___ __  __ ___ _  _ _____ ___     _   ___ ___ ___ ___ ___ 
                | __| |  | __|  \/  | __| \| |_   _/ __|   /_\ / __/ __| __/ __/ __|
                | _|| |__| _|| |\/| | _|| .` | | | \__ \  / _ \ (_| (__| _|\__ \__ \
                |___|____|___|_|  |_|___|_|\_| |_| |___/ /_/ \_\___\___|___|___/___/
            */
            mapped_type& operator[] (const key_type& k)
            {
                B_S_T* is_in = search(_firstNd, k);
                if (is_in)
                    return (is_in->set.second);
                value_type val = std::make_pair<key_type, mapped_type>(k, mapped_type());
                return (insert_in_tree(_firstNd, val)->set.second);
            };
            /*
                 __  __  ___  ___ ___ ___ ___ ___ ___  ___ 
                |  \/  |/ _ \|   \_ _| __|_ _| __| _ \/ __|
                | |\/| | (_) | |) | || _| | || _||   /\__ \
                |_|  |_|\___/|___/___|_| |___|___|_|_\|___/
            */
            std::pair<iterator,bool> insert (const value_type& val)
            {
                B_S_T* ins = search(_firstNd, val.first);
                if (ins)
                    return (std::pair<iterator, bool>(iterator(ins, _afterLast, _compare), false));
                _size_value++;
                return (std::pair<iterator, bool>(iterator(insert_in_tree(_firstNd, val), _afterLast, _compare), true));
            };
            iterator insert (iterator position, const value_type& val)
            {
                if (position->_ptr > val.key)
                {
                    iterator prev(position);
                    prev--;
                    while (prev != end() && prev->_ptr >= val.key)
                    { position--; prev--; }
                }
                else if (position->_ptr < val.key)
                {
                    iterator next(position);
                    next++;
                    while (next != end() && next->_ptr <= val.key)
                    { position++; next++; }
                }
                if (position != end() && val.key == position->_ptr)
                    return position;
                _size_value++;
                return (iterator(insertNode(position.getNode(), val), _afterLast, _compare));
            };
            template <class InputIterator>
                void insert (InputIterator first, InputIterator last,
					typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type* = 0) :
                {
                    while (first != last)
                    insert(*first++);
                };
            void erase (iterator position)
            {
                delete_in_tree(position.getNode(), position->_ptr);
                _size_value--;
            };
            size_type erase (const key_type& k)
            {
                size_type ret = delete_in_tree(_firstNd, k);
                _size_value -= ret;
                return (ret);
            };
            void erase (iterator first, iterator last)
            {
                while (first != last)
                {
                    iterator tmp(first);
                    first++;
                    erase(tmp);
                }
            };
            void swap (map& x)
            {
                swap(_firstNd, x._firstNd);
                swap(_afterLast, x._afterLast);
                swap(_size_value, x._size_value);
                swap(_compare, x._compare);
                swap(_alloc_pair, x._alloc_pair);
                swap(_alloc_node, x._alloc_node);
            };
            void clear()    { erase(begin(), end()); };
            /*
                  ___  ___ ___ ___ _____   _____ ___  ___ 
                 / _ \| _ ) __| __| _ \ \ / / __| _ \/ __|
                | (_) | _ \__ \ _||   /\ V /| _||   /\__ \
                 \___/|___/___/___|_|_\ \_/ |___|_|_\|___/
            */
            key_compare key_comp()        const { return (_compare); };
            value_compare value_comp()    const { return (value_compare(_compare)); }
            /*
                  ___  ___ ___ ___    _ _____ ___ ___  _  _ ___ 
                 / _ \| _ \ __| _ \  /_\_   _|_ _/ _ \| \| / __|
                | (_) |  _/ _||   / / _ \| |  | | (_) | .` \__ \
                 \___/|_| |___|_|_\/_/ \_\_| |___\___/|_|\_|___/
            */
            iterator find (const key_type& k)
            {
                B_S_T* nd = search(_firstNd, k);
                if (nd)
                    return iterator(nd, _afterLast, _compare);
                return (end());
            };
            const_iterator find (const key_type& k) const
            {
                B_S_T* nd = searchNode(_firstNd, k);
                if (nd)
                    return const_iterator(nd, _afterLast, _compare);
                return (end());
            };
            size_type count (const key_type& k) const
            {
                return (search(_firstNd, k) ? true: false);
            };
            iterator lower_bound (const key_type& k)
            {
                for (iterator lower = begin(); lower != end(); ++lower)
                    if (!_compare(lower->_ptr, k))
                        return (lower);
                return (end());
            };
            const_iterator lower_bound (const key_type& k) const
            {
                for (const_iterator lower = begin(); lower != end(); ++lower)
                    if (!_compare(lower->_ptr, k))
                        return (lower);
                return (end());
            };
            iterator upper_bound (const key_type& k)
            {
                for (iterator upper = begin(); upper != end(); ++upper)
                    if (_compare(k, upper->_ptr))
                        return (upper);  
                return (end());  
            };
            const_iterator upper_bound (const key_type& k) const
            {
                for (const_iterator upper = begin(); upper != end(); ++upper)
                    if (_compare(k, upper->_ptr))
                        return (upper);  
                return (end());  
            };
            std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
            };
            std::pair<iterator,iterator>             equal_range (const key_type& k)
            {
                return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
            };
            allocator_type get_allocator() const {};
        
        /*
                 __  __         ______                _   _                 
                |  \/  |       |  ____|              | | (_)                
                | \  / |_   _  | |__ _   _ _ __   ___| |_ _  ___  _ __  ___ 
                | |\/| | | | | |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
                | |  | | |_| | | |  | |_| | | | | (__| |_| | (_) | | | \__ \
                |_|  |_|\__, | |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
                         __/ |                                              
                        |___/                                               
        */
        private:
            // FIND THE BALANCE OF EACH NODES
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
            //RETURN TOTAL BALANCE
            int  total_factor(B_S_T *first)
            {
                if (!first)
                    return (0);
                return (balance_factor(first->left) - balance_factor(first->right));
            };
            // BALANCE TREE IF B_S_T IS ROOT
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
            // BALANCE TREE UNTIL ROOT
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
            // CREATE A NEW NODE
            B_S_T    *create_new_bst(const value_type& new_bst)
            {
                B_S_T* newNode = _allocNode.allocate(1);
                _alloc_pair.construct(&newNode->set, new_bst);
                newNode->parent = 0;
                newNode->left = 0;
                newNode->right = 0;
                return (newNode);
            };
            // NULL A NODE AND DELETE IT
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
            // FIND THE HIGHEST NODE
            B_S_T    *max_val_node(B_S_T *first)
            {
                if (first->right && first->right != _afterLast)
                    return (max_val_node(first->right));
                return (first);
            };
            // FIND THE LOWEST NODE
            B_S_T    *min_val_node(B_S_T *first)
            {
                if (first->left && first->left != _afterLast)
                    return (min_val_node(first->left));
                return (first);
            };
            // SEARCH FOR A NODE WITH KEY VALUE
            B_S_T    *search(B_S_T *first, key_type key)
            {
                if (!first || first == _afterLast)
                    return (0);
                while (first && first->set.first != search && first != _afterLast)
                {
                    if (first->set.first < search)
                        first = first->right;
                    else
                        first = first->left;
                }
                if (first && first != _afterLast)
                    return (first);
                else
                    return (0);
            }
            // INSERT A NEW ins-NODE IN THE TREE
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
                if (first->set.first > ins.key && first->left && first->left != _afterLast)
                    return (insertNode(first->left, ins));
                else if (first->set.first < ins.key && first->right && first->right != _afterLast)
                    return (insertNode(first->right, ins));
                B_S_T *newNode = create_new_bst(ins);
                if (first->set.first > newNode->set.first && !first->left)
                    first->left = newNode;
                else if (first->set.first < newNode->set.first && !first->right)
                    first->right = newNode;
                else if (first->left && first->set.first > newNode->set.first)
                {
                    newNode->left = _afterLast;
                    _afterLast->right = newNode;
                    first->left = newNode;
                }
                else if (first->right && first->set.first < newNode->set.first)
                {
                    newNode->right = _afterLast;
                    _afterLast->left = newNode;
                    first->right = newNode;
                }
                newNode->parent = first;
                return (balance_tree(newNode));
            };
            // DELETE A NODE IN A TREE WITH KEY
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
                        return (delete_in_tree(tmp->left, maxNode->set.first));
                    }
                }
                else if ((!tmp->left || tmp->left == _afterLast) && (!tmp->right || tmp->right == _afterLast))
                {
                    B_S_T* toparent = 0;
                    if (tmp->left == _afterLast || tmp->right == _afterLast)
                    {
                        toparent = _afterLast;
                        tmp->set.first <= tmp->parent->set.first ? _afterLast->right = tmp->parent : _afterLast->left = tmp->parent;
                    }
                    tmp->set.first <= tmp->parent->set.first ? tmp->parent->left = toparent : tmp->parent->right = toparent;
                }
                else if ((tmp->left && tmp->left != _afterLast) && (!tmp->right || tmp->right == _afterLast))
                {
                    tmp->set.first <= tmp->parent->set.first ? tmp->parent->left = tmp->left : tmp->parent->right = tmp->left;
                    tmp->left->parent = tmp->parent;
                    if (tmp->right == _afterLast) { _afterLast->left = tmp->left; tmp->left->right = _afterLast; }
                }
                else if ((!tmp->left || tmp->left == _afterLast) && tmp->right && tmp->right != _afterLast)
                {
                    tmp->set.first <= tmp->parent->set.first ? tmp->parent->left = tmp->right : tmp->parent->right = tmp->right;
                    tmp->right->parent = tmp->parent;
                    if (tmp->left == _afterLast) { _afterLast->right = tmp->right; tmp->right->left = _afterLast; }
                }
                else
                {
                    B_S_T* maxNode = searchMaxNode(tmp->left);
                    _alloc_pair.destroy(&tmp->set);
                    _alloc_pair.construct(&tmp->set, maxNode->set);
                    return delete_in_tree(tmp->left, maxNode->set.first);
                }
                balance_tree(tmp_parent);
                null_and_del_bst(tmp);
                return true;
            };
            template <typename Utype>
                void swap(Utype& a, Utype& b)
                {
                    Utype tmp = a;
                    a = b;
                    b = tmp;
                }

    };
    template <class Key, class T, class Compare, class Alloc>
	void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    };
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b)
    {
        if (a.size() != b.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it = b.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = a.begin();
		while (it != b.end())
		{
			if (*it != *it2)
				return (false);
			++it2;
			++it;
		}
		return (true);
    };
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b)
    {
        return (!(a == b));
    };
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b)
    {
        if (a.size() > b.size())
			return (true);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it = a.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = b.begin();
		while (it != a.end() && it2 != b.end())
		{
			if (*it > *it2)
				return (true);
			++it2;
			++it;
		}
		return (false);
    };
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b)
    {
        return (!(a > b) && !(a == b));
    };
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b)
    {
        return (!(a < b));
    };
	
    template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &a, const map<Key, T, Compare, Alloc> &b)
    {
        return (!(a > b));
    };

}

#endif