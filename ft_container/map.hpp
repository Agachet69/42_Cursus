/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:14:36 by agachet           #+#    #+#             */
/*   Updated: 2022/01/19 20:27:77 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template < class Key, class T, class Compare = less<Key>/* map::key_compare*/, class Alloc = allocator<pair<const Key,T> >>
	class map;
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const key_type,mapped_type>	value_type;
			typedef Compare								key_compare;
			typedef	Alloc								allocator_type;
			typedef allocator_type::reference			reference;
			typedef allocator_type::const_reference		const_reference;
			typedef allocator_type::pointer				pointer;
			typedef allocator_type::const_pointer		const_pointer;
			//typedef									iterator;
			//typedef									const_iterator;
			//typedef									reverse_iterator;
			//typedef									const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(size)
			{

			}

			/*template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			constructeur pour iterator*/

			//map (const map& x); constructeur par copie

			private:
			template < class Key, class T >
			typedef struct {
				value_type	data;
				Tree	*parent;
				Tree	*left;
				Tree	*right;
			}	Tree;

				value_type
				allocator_type	_alloc;
				size_type		_size;

	};
}
