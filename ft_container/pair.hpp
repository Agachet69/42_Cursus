/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:46:18 by agachet           #+#    #+#             */
/*   Updated: 2022/01/21 19:30:17 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template <class T1, class T2> struct pair
	class pair {

		public:
			typedef	T1	first_type;
			typedef	T2	second_type;

			first_type	first;
			second_type	second;

		pair() : first(), second() {}

		template<class U, class V>
		pair (const pair<U,V>& pr)  : first(pr.first), second(pr.second) {}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		pair& operator=(pair const& __p)
		{
			first = __p.first;
			second = __p.second;
			return *this;
		}
	};
}
