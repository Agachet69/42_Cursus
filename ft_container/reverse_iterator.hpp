#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iterator>

namespace ft {

template< typename Iterator >
class reverse_iterator
{
	public:

		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

	private:

		iterator_type _p;

	public:

		reverse_iterator(): _p()
		{

		}

		reverse_iterator(iterator_type const it): _p(it)
		{

		}

		template <typename Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it): _p(rev_it.base())
		{

		}

		iterator_type base() const
		{
			return (this->_p);
		}

		reference operator*() const
		{
			iterator_type tmp = this->_p;
			--tmp;
			return (*tmp);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(this->_p - n));
		}

		reverse_iterator& operator++()
		{
			--this->_p;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--this->_p;
			return (tmp);
		}

		reverse_iterator& operator+=(difference_type n)
		{
			this->_p = this->_p - n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(this->_p + n));
		}

		reverse_iterator& operator--()
		{
			++this->_p;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++this->_p;
			return (tmp);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			this->_p = this->_p + n;
			return (*this);
		}

		pointer operator->() const
		{
			iterator_type tmp = this->_p;
			--tmp;
			return &(*tmp);
		}

		reference operator[](difference_type n) const
		{
			return *(this->_p + n);
		}
};

template <typename Iterator>
bool operator== (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	if (cpy_1.base() == cpy_2.base())
		return (1);
	return (0);
}

template <typename Iterator>
bool operator!= (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	if (cpy_1.base() != cpy_2.base())
		return (1);
	return (0);
}

template <typename Iterator>
bool operator< (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	if (cpy_1.base() < cpy_2.base())
		return (1);
	return (0);
}

template <typename Iterator>
bool operator<= (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	if (cpy_1.base() <= cpy_2.base())
		return (1);
	return (0);
}

template <typename Iterator>
bool operator> (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	if (cpy_1.base() > cpy_2.base())
		return (1);
	return (0);
}

template <typename Iterator>
bool operator>= (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	if (cpy_1.base() >= cpy_2.base())
		return (1);
	return (0);
}

template <typename Iterator>
reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& cpy)
{
	return (reverse_iterator<Iterator>(cpy.base() - n));
}

template <typename Iterator>
typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& cpy_1, const reverse_iterator<Iterator>& cpy_2)
{
	return (cpy_1.base() - cpy_2.base());
}
};

#endif
