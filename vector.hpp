#include <iostream>

namespace ftc {

template<typename T>
class Vector_Iterator
{
	protected:
		T *p;
	public:
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type const * const_pointer;
		typedef value_type& reference;
		typedef value_type const & const_reference;
		typedef std::ptrdiff_t difference_type;
	private:
};

template<typename T>
class Vector_Reverse_Iterator
{
	protected:
		T *p;
	public:
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type const * const_pointer;
		typedef value_type& reference;
		typedef value_type const & const_reference;
		typedef std::ptrdiff_t difference_type;
	private:
};


template <class T, class Alloc = std::allocator<T> >
class Vector
{
	public:
		Vector();
		~Vector();	
		Vector& operator=(Vector const&);
	
	private:
		T* array;

	public:
		typedef T value_type;	
		typedef T& reference;
		typedef T const &reference;
		typedef T* pointer;
		typedef T const *pointer;
		typedef Vector_Iterator<value_type> iterator;
		typedef Vector_Iterator<value_type const> const_iterator;
		typedef Vector_Reverse_Iterator<value_type> reverse_iterator;
		typedef Vector_Reverse_Iterator<value_type const> const_reverse_iterator;
	    typedef std::ptrdiff_t difference_type;
		typedef unsigned int size_type;
	
	public:
    	iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		void assign(const_iterator first, const_iterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
    	void insert (iterator position, size_type n, const value_type& val);
		void insert(iterator position, iterator first, iterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

	protected:

};

}