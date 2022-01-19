/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:32:39 by agachet           #+#    #+#             */
/*   Updated: 2022/01/19 18:25:26 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{

		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

// .............................................. Member Functions ..........................................

		explicit stack (const container_type& ctnr = container_type()) {}

		bool empty() const
		{
			return (c.empty());
		}

		size_type size() const
		{
			return (c.size());
		}

		value_type& top()
		{
			return (c.back());
		}

		const value_type& top() const
		{
			return (c.back());
		}

		void push (const value_type& val)
		{
			c.push_back(val);
		}

		void pop()
		{
			c.pop_back();
		}

		template <class T1, class C1>
		friend bool operator== (const stack<T1,C1>&, const stack<T1,C1>& );

		template <class T1, class C1>
		friend bool operator!= (const stack<T1,C1>&, const stack<T1,C1>& );

		template <class T1, class C1>
		friend bool operator< (const stack<T1,C1>&, const stack<T1,C1>& );

		template <class T1, class C1>
		friend bool operator<= (const stack<T1,C1>&, const stack<T1,C1>& );

		template <class T1, class C1>
		friend bool operator> (const stack<T1,C1>&, const stack<T1,C1>& );

		template <class T1, class C1>
		friend bool operator>= (const stack<T1,C1>&, const stack<T1,C1>& );

		protected:
			container_type c;
	};

// .......................................... Non-member function overloads ..........................................

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
	    return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		 return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}
