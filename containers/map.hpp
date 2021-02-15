/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:47:08 by thverney          #+#    #+#             */
/*   Updated: 2021/02/16 00:21:25 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <limits>
# include <utility>

namespace ft
{
    template <class Key, class T, class Compare=std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
    {
        private:

        	template <class Key, class T>
                struct Node
                {
                    std::pair<Key, T> pair;
                    Node *parent;
                    Node *left;
                    Node *right;
                    bool end;
                };
        public:
            typedef Key                                                 key_type;
			typedef T                                                   mapped_type;
			typedef std::pair<const key_type, mapped_type>              value_type;
			typedef Compare                                             key_compare;
			typedef Alloc                                               allocator_type;
			typedef T& reference;
			typedef const T&                                            const_reference;
			typedef T* pointer;
			typedef const T*                                            const_pointer;
			typedef unsigned long                                       size_type;
			typedef Node<key_type, mapped_type>*                       node;
			typedef MapIterator<key_type, mapped_type>                  iterator;
			typedef ReverseMapIterator<key_type, mapped_type>           reverse_iterator;
			typedef ConstMapIterator<key_type, mapped_type>             const_iterator;
			typedef ConstReverseMapIterator<key_type, mapped_type>      const_reverse_iterator;
            
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

    };

}

#endif