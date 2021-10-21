/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:03:23 by agachet           #+#    #+#             */
/*   Updated: 2021/10/18 15:10:50 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    std::cout << "----------- TEST DE SWAP ----------" << std::endl;
    int a = 5;
    int b = 10;
    swap(a, b);
    std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
    char c = 'c';
    char d = 'd';
    swap(c, d);
    std::cout << "c: " << c << std::endl << "d: " << d << std::endl;
    std::string un = "chaine numero 1";
    std::string deux = "chaine numero 2";
    swap(un, deux);
    std::cout << "un: " << un << std::endl << "deux: " << deux << std::endl;

    std::cout << "----------- TEST DE MIN ----------" << std::endl;

    int test1 = 50;
    int test11 = 100;
    std::cout << "le plus petit est " << min<int>(test1, test11) << std::endl;
    float test2 = 50.65f;
    float test22 = 49.89f;
    std::cout << "le plus petit est " << min<float>(test2, test22) << std::endl;
    char test3 = 'b';
    char test33 = 'f';
    std::cout << "le plus petit est " << min<char>(test3, test33) << std::endl;

    std::cout << "----------- TEST DE MAX ----------" << std::endl;

    int test4 = 50;
    int test44 = 100;
    std::cout << "le plus grand est " << max<int>(test4, test44) << std::endl;
    float test5 = 50.65f;
    float test55 = 49.89f;
    std::cout << "le plus grand est " << max<float>(test5, test55) << std::endl;
    char test6 = 'b';
    char test66 = 'f';
    std::cout << "le plus grand est " << max<char>(test6, test66) << std::endl;
}
