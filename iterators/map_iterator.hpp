/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:31:53 by aeoithd           #+#    #+#             */
/*   Updated: 2021/03/01 14:25:01 by thverney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

# include <utility>
#include "../iterators/is_const_it.hpp"


namespace ft
{
    template <class Key, class T, class Compare, typename B_S_T, bool B>
    class map_iterator
    {
        public:
        
            typedef Key                                                                     key_type;
            typedef Compare                                                                 key_compare;
            typedef T                                                                       mapped_type;
            typedef std::pair<Key, T>                                                       value_type;
            typedef long int                                                                difference_type;
            typedef size_t                                                                  size_type;
            typedef typename choose_if_const<B, value_type&, const value_type&>::_type       reference;
            typedef typename choose_if_const<B, value_type*, const value_type*>::_type       pointer;
            typedef B_S_T*                                                                  nodeptr;
            
        protected:
            nodeptr     _ptr;
            nodeptr     _lastptr;
            key_compare _comp;

        public:
            map_iterator(nodeptr node = 0, nodeptr last = 0, const key_compare& comp = key_compare()) :
                _ptr(node), _lastptr(last), _comp(comp) {}
            map_iterator(const map_iterator<Key, T, Compare, B_S_T, false>& cpy)
            {
                _ptr = cpy.getNode();
                _lastptr = cpy.getlast();
                _comp = cpy.getCompare();
            }
            ~map_iterator() {}
            map_iterator& operator=(const map_iterator& affect)
            {
                if (this != &affect)
                {
                    _ptr = affect._ptr;
                    _lastptr = affect._lastptr;
                    _comp = affect._comp;
                }
                return (*this);
            }
            nodeptr getNode()           const { return (_ptr); }
            nodeptr getlast()           const { return (_lastptr); }
            key_compare getCompare()    const { return (_comp); }
            reference operator*()       const { return (_ptr->set); }
            pointer operator->()        const { return (&_ptr->set); }
            map_iterator& operator++()
            {
                nodeptr prev = _ptr;
                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->right;
                    return (*this);
                }
                while (_ptr != _lastptr && !_comp(prev->set.first, _ptr->set.first))
                {
                    if (_ptr->right && (_ptr->right == _lastptr || 
                            _comp(prev->set.first, _ptr->right->set.first)))
                    {
                        _ptr = _ptr->right;
                        
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMin(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (*this);
            }
            map_iterator operator++(int)
            {
                map_iterator res(*this);

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->right;
                    return (res);
                }
                while (_ptr != _lastptr && !_comp(res->first, _ptr->set.first))
                {
                    if (_ptr->right && (_ptr->right == _lastptr || 
                            _comp(res->first, _ptr->right->set.first)))
                    {
                        _ptr = _ptr->right;
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMin(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (res);
            }
            map_iterator& operator--()
            {
                nodeptr prev = _ptr;

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->left;
                    return (*this);
                }
                while (_ptr != _lastptr && !_comp(_ptr->set.first, prev->set.first))
                {
                    if (_ptr->left && (_ptr->left == _lastptr || 
                            _comp(_ptr->left->set.first, prev->set.first)))
                    {
                        _ptr = _ptr->left;
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMax(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (*this);
            }
            map_iterator operator--(int)
            {
                map_iterator res(*this);

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->left;
                    return (res);
                }
                while (_ptr != _lastptr && !_comp(_ptr->set.first, res->first))
                {
                    if (_ptr->left && (_ptr->left == _lastptr || 
                            _comp(_ptr->left->set.first, res->first)))
                    {
                        _ptr = _ptr->left;
                        
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMax(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (res);
            }
            bool operator==(const map_iterator& it) const   { return (it._ptr == _ptr); }
            bool operator!=(const map_iterator& it) const   { return (it._ptr != _ptr); }
        
        private:
            B_S_T* searchMax(B_S_T *first)
            {
                if (first && first != _lastptr && first->right && first->right != _lastptr)
                    return searchMax(first->right);
                return first;
            }
            B_S_T* searchMin(B_S_T *first)
            {
                if (first && first != _lastptr && first->left && first->left != _lastptr)
                    return searchMin(first->left);
                return first;
            }
    };
    
    template <class Key, class T, class Compare, typename B_S_T, bool B>
    class reverse_map_iterator
    {
        public:
            typedef Key                                                                 key_type;
            typedef Compare                                                             key_compare;
            typedef T                                                                   mapped_type;
            typedef std::pair<Key, T>                                                   value_type;
            typedef long int                                                            difference_type;
            typedef size_t                                                              size_type;
            typedef typename choose_if_const<B, value_type&, const value_type&>::_type  reference;
            typedef typename choose_if_const<B, value_type*, const value_type*>::_type  pointer;
            typedef B_S_T*                                                              nodeptr;
            
        private:

            nodeptr         _ptr;
            nodeptr         _lastptr;
            key_compare     _comp;

        public:

            reverse_map_iterator(nodeptr node = 0, nodeptr last = 0, const key_compare& comp = key_compare()) :
                _ptr(node), _lastptr(last), _comp(comp) {}
            reverse_map_iterator(const reverse_map_iterator<Key, T, Compare, B_S_T, false>& cpy)
            {
                _ptr = cpy.getNonConstNode();
                _lastptr = cpy.getNonConstlast();
                _comp = cpy.getCompare();
            }
            explicit reverse_map_iterator(map_iterator<Key, T, Compare, B_S_T, false> cpy)
            {
                cpy--;
                _ptr = cpy.getNonConstNode();
                _lastptr = cpy.getNonConstlast();
                _comp = cpy.getCompare();
            }
            ~reverse_map_iterator() {}
            reverse_map_iterator& operator=(const reverse_map_iterator& assign)
            {
                if (this != &assign)
                {
                    _ptr = assign._ptr;
                    _lastptr = assign._lastptr;
                    _comp = assign._comp;
                }
                return (*this);
            }
            nodeptr getNonConstNode()   const           { return (_ptr); }
            nodeptr getNonConstlast()   const           { return (_lastptr); }
            key_compare getCompare()    const           { return (_comp); }
            reference operator*()       const           { return (_ptr->set); }
            pointer operator->()        const           { return (&_ptr->set); }
            reverse_map_iterator& operator++()
            {
                nodeptr prev = _ptr;

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->left;
                    return (*this);
                }
                while (_ptr != _lastptr && !_comp(_ptr->set.first, prev->set.first))
                {
                    if (_ptr->left && (_ptr->left == _lastptr || 
                            _comp(_ptr->left->set.first, prev->set.first)))
                    {
                        _ptr = _ptr->left;
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMax(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (*this);
            }
            reverse_map_iterator operator++(int)
            {
                reverse_map_iterator res(*this);

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->left;
                    return (res);
                }
                while (_ptr != _lastptr && !_comp(_ptr->set.first, res->first))
                {
                    if (_ptr->left && (_ptr->left == _lastptr || 
                            _comp(_ptr->left->set.first, res->first)))
                    {
                        _ptr = _ptr->left;
                        
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMax(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (res);
            }
            reverse_map_iterator& operator--()
            {
                nodeptr prev = _ptr;

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->right;
                    return (*this);
                }
                while (_ptr != _lastptr && !_comp(prev->set.first, _ptr->set.first))
                {
                    if (_ptr->right && (_ptr->right == _lastptr || 
                            _comp(prev->set.first, _ptr->right->set.first)))
                    {
                        _ptr = _ptr->right;
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMin(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (*this);
            }
            reverse_map_iterator operator--(int)
            {
                reverse_map_iterator res(*this);

                if (_ptr == _lastptr)
                {
                    _ptr = _lastptr->right;
                    return (res);
                }
                while (_ptr != _lastptr && !_comp(res->first, _ptr->set.first))
                {
                    if (_ptr->right && (_ptr->right == _lastptr || 
                            _comp(res->first, _ptr->right->set.first)))
                    {
                        _ptr = _ptr->right;
                        
                        nodeptr tmp = 0;
                        if (_ptr != _lastptr && (tmp = searchMin(_ptr)))
                            _ptr = tmp;
                    }
                    else
                        _ptr = _ptr->parent;
                }
                return (res);
            }
            bool operator==(const reverse_map_iterator& it) const   { return (it._ptr == _ptr); }
            bool operator!=(const reverse_map_iterator& it) const   { return (it._ptr != _ptr); }
        private:
            B_S_T* searchMax(B_S_T *first)
            {
                if (first && first != _lastptr && first->right && first->right != _lastptr)
                    return searchMax(first->right);
                return (first);
            }
            B_S_T* searchMin(B_S_T *first)
            {
                if (first && first != _lastptr && first->left && first->left != _lastptr)
                    return searchMin(first->left);
                return (first);
            }
    };
    
    template <class T>
    class allocator
    {
        public:
            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;
            typedef const T*    const_pointer;
            typedef const T&    const_reference;
            typedef size_t      size_type;
            typedef long int    difference_type;
            allocator() throw() {};
            allocator(const allocator&) throw() {};
            template <class U>
                allocator(const allocator<U>&) throw() {};
            ~allocator() throw() {};
            pointer address(reference x) const              { return &x; }
            const_pointer address(const_reference x) const  { return &x; }
            pointer allocate(size_type n)
            {
                pointer ret;
                size_t size = n * sizeof(value_type);
                try { ret = reinterpret_cast<pointer>(::operator new(size)); }
                catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
                return ret;
            }
            void deallocate (pointer p, size_type n)
            {
                (void)n;
                ::operator delete(p);
            }
            void construct(pointer p, const T& v) { new((void*)p)T(v); }
            void destroy(pointer p) { p->~T(); }
    };
};

#endif