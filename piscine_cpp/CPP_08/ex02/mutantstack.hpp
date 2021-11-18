/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:31:10 by agachet           #+#    #+#             */
/*   Updated: 2021/11/02 18:58:40 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{

	public:
		MutantStack(): std::stack<T, Container>() {}
		~MutantStack() {}
		MutantStack<T, Container>(MutantStack<T, Container> const & src) {*this = src;}
		MutantStack<T, Container> & operator=(MutantStack<T, Container> const & rhs)
		{
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
		}

	using std::stack<T>::push;
	using std::stack<T>::top;
	using std::stack<T>::pop;
	using std::stack<T>::size;

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}
	const_iterator begin() const {return this->c.begin();}
	const_iterator end() const {return this->c.end();}
	reverse_iterator rbegin() {return this->c.rbegin();}
	reverse_iterator rend() {return this->c.rend();}
	const_reverse_iterator rbegin() const {return this->c.rbegin();}
	const_reverse_iterator rend() const {return this->c.rend();}
};
#endif
