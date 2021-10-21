/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:06:21 by agachet           #+#    #+#             */
/*   Updated: 2021/10/15 20:06:44 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP


class Base
{
	public:
		virtual ~Base();
};

Base::~Base() {}

class A: public Base {};
class B: public Base {};
class C: public Base {};

#endif
