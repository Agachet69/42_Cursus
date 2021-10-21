/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:08 by agachet           #+#    #+#             */
/*   Updated: 2021/10/20 17:17:50 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }

		private:
		int _n;};


		std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o;}

		template< typename T >
		void print( T const & x ) {
			std::cout << x << std::endl; return;
}

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter<int, int>( tab, 5, print);
	iter( tab2, 5, print);

	return 0;
}

//void    hup(std::string &t)
//{
//    t += "oho";
//}

//void p5(int &j)
//{
//    j += 5;
//}

//int main()
//{
//    std::string str[3] = {"coucou", "test1", "test2"};
//    int lenght = 3;
//    iter<std::string, int>(str, lenght, (&hup));
//    int tab[9] = {1,2,3,4,5,6,7,8,9};
//    unsigned long b = 9;
//    iter<int, int>(tab, b, (&p5));
//    for (int i = 0; i < 9; i++)
//        std::cout << tab[i] << std::endl;
//}
