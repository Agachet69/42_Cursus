/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:40:33 by agachet           #+#    #+#             */
/*   Updated: 2021/12/23 19:13:15 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{

		public:
			typedef T											value_type;
			typedef value_type*									pointer;
			typedef value_type*									iterator;
			typedef const value_type*							const_iterator;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;
			typedef Allocator									allocator_type;
			//typedef typename allocator_type::reference			reference;
			//typedef typename allocator_type::const_reference	const_reference;
			//typedef typename allocator_type::size_type			size_type;
			//typedef typename allocator_type::difference_type	difference_type;
			//typedef typename allocator_type::pointer			pointer;
			//typedef typename allocator_type::const_pointer		const_pointer;

			explicit vector (const allocator_type &alloc = allocator_type()): _alloc(alloc)
			{
				_taille = 0;
				_capacity = 0;
				_tab = _alloc.allocate(1);
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type &alloc = allocator_type()): _alloc(alloc)
			{
				int i = -1;
				_capacity = n;
				_taille = n;
				_tab = _alloc.allocate(n);
				while (++i < n)
					_tab[i] = val;
			}

			//vector (const vector& x)
			//{
			//	int i = -1;

			//	this->_taille = x._taille;
			//	this->_tab = new value_type(x._taille);
			//	while (++i < this->_taille)
			//		this->_tab[i] = x._tab[i];
			//}

			//vector (InputIterator first, InputIterator last/*, const allocator_type& alloc = allocator_type()*/)
			//{
			//	int i = 0;
			//	//while
			//}

			~vector()
			{
				delete [] this->_tab;
			}

			vector& operator= (const vector& x)
			{
				int i = -1;

				get_allocator().deallocate(this->_tab, this->_capacity);
				this->_tab = get_allocator().allocate(x._capacity);
				while (++i < x._taille)
					this->_tab[i] = x._tab[i];
				this->_capacity = x._capacity;
				this->_taille = x._taille;
				return (*this);
			}

			//..................................... Iterators ........................................

			iterator begin()
			{
				return (this->_tab);
			}

			iterator end()
			{
				return (this->_tab + this->_taille);
			}

			//..................................... Capacity .........................................

			size_type size() const
			{
				return ((unsigned int)this->_taille);
			}

			size_type max_size() const
			{
				if (this->_alloc.max_size() > 9223372036854775807)
					return (9223372036854775807);
				return (this->_alloc.max_size());
			}

			void resize (size_type n, value_type val = value_type())
			{
				int i = 0;

				value_type *tmp;
				tmp = this->_tab;
				this->_tab = this->_alloc.allocate(n);
				for (i = 0; i < _taille && i < n; i++)
					this->_tab[i] = tmp[i];
				while (i < n)
				{
					this->_tab[i] = val;
					i++;
				}
				for (int i = 0; i < _taille && i < n; i++)
					_alloc.destroy(&tmp[i]);
				_alloc.deallocate(tmp, this->_capacity);
				if (n > this->_capacity)
					this->_capacity = n;
				this->_taille = n;
			}

			size_type capacity() const
			{
				return (this->_capacity);
			}

			bool	empty() const
			{
				if (_taille == 0)
					return (true);
				else
					return (false);
			}

			void	reserve(size_type n)
			{
				if (n > this->_capacity)
				{
					value_type *tmp;
					tmp = this->_tab;
					this->_tab = this->_alloc.allocate(n);
					for (int i = 0; i < _taille && i < n; i++)
						this->_tab[i] = tmp[i];
					for (int i = 0; i < _taille && i < n; i++)
						_alloc.destroy(&tmp[i]);
					_alloc.deallocate(tmp, this->_capacity);
					this->_capacity = n;
				}
			}

			//..................................... Element access ...................................

			reference operator[] (size_type n)
			{
				return (this->_tab[n]);
			}

			reference at (size_type n)
			{
				if (n < 0 || n >= this->_taille)
					throw std::out_of_range ("out");
				return (this->_tab[n]);
			}

			reference front()
			{
				return (this->_tab[0]);
			}

			reference back()
			{
				return (this->_tab[this->_taille - 1]);
			}

			//..................................... Modifiers ........................................

			void assign (size_type n, const value_type& val)
			{
				value_type *tmp;
				tmp = this->_tab;
				if (n > this->_capacity)
				{
					this->_tab = get_allocator().allocate(n);
					this->_capacity = n;
				}
				this->_tab = get_allocator().allocate(this->_capacity);
				for (int i = 0; i < n; i++)
					this->_tab[i] = val;
				for (int i = 0; i < _taille; i++)
					_alloc.destroy(&tmp[i]);
				_alloc.deallocate(tmp, this->_capacity);
				if (n > this->_capacity)
					this->_capacity = n;
				this->_taille = n;
			}

			//template <class InputIterator>
  			//void assign (InputIterator first, InputIterator last)
			//{

			//	// comment tester
			//}
			//void	ft_space_free()
			//{
			//	//for (int i = 0; i < _taille; i++)
			//	//	_alloc.destroy(&tmp[i]);
			//	_alloc.deallocate(tmp, this->_capacity);
			//}

			void push_back (const value_type& val)
			{
				if ((this->_taille + 1) > this->_capacity)
					ft_realoc((this->_capacity * 2), val);
				else
					this->_tab[this->_taille] = val;
				this->_taille++;
			}

			void pop_back()
			{
				if (this->_taille <= 0)
					return ;
				get_allocator().destroy(&_tab[this->_taille - 1]);
				this->_taille--;
			}

			//template <class InputIterator>
			//void insert (iterator position, InputIterator first, InputIterator last)
			//{

			//}

			void	insert_not_alloc(iterator position, const value_type& val)
			{
				int			k;
				int			i = -1;
				size_type	tmp = position - _tab;
				size_type	tab[this->_taille + 1];

				while (++i < tmp)
					tab[i] = this->_tab[i];
				k = i;
				tab[i++] = val;
				while (i < (this->_taille + 1))
					tab[i++] = this->_tab[k++];
				i = -1;
				while (++i < (this->_taille + 1))
					this->_tab[i] = tab[i];
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type	tmp = position - _tab;
				iterator	ret = position;
				value_type	*tab_tmp = this->_tab;
				int			last_capa = this->_capacity;
				int			i = -1;
				int			k = -1;

				if (this->_taille + 1 > this->_capacity)
				{
					if (this->_capacity == 0)
						this->_tab = get_allocator().allocate(this->_capacity += 1);
					else
						this->_tab = get_allocator().allocate(this->_capacity *= 2);
					while (++i <= this->_taille)
					{
						if (i == tmp)
							this->_tab[i++] = val;
						this->_tab[i] = tab_tmp[++k];
					}
					get_allocator().deallocate(tab_tmp, last_capa);
				}
				else
					insert_not_alloc(position, val);
				this->_taille++;
				return (ret);
			}

			void	insertn_not_alloc(iterator position, const value_type& val, size_type n)
			{
				int			k;
				int			i = -1;
				size_type	tmp = position - _tab;
				size_type	tab[n + this->_taille];

				while (++i < tmp)
					tab[i] = this->_tab[i];
				k = i;
				while ((i - tmp) < n)
					tab[i++] = val;
				while (i < (this->_taille + n))
					tab[i++] = this->_tab[k++];
				i = -1;
				while (++i < (this->_taille + n))
					this->_tab[i] = tab[i];
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type	tmp = position - _tab;
				value_type	*tab_tmp = this->_tab;
				int			last_capa = this->_capacity;
				int			all = 0;
				int			i = -1;
				int			k = 0;

				while (this->_taille + n > this->_capacity)
				{
					if (this->_capacity == 0)
						this->_tab = get_allocator().allocate(this->_capacity += 1);
					else if (all == 0)
						this->_tab = get_allocator().allocate(this->_capacity *= 2);
					else
					{
						get_allocator().deallocate(this->_tab, 0);
						this->_tab = get_allocator().allocate(this->_capacity = last_capa + n);
					}
					all = 1;
				}
				if (all == 1)
				{
					while (++i < this->_taille + n)
					{
						if (tmp == i)
						{
							while (i - k < n)
								this->_tab[i++] = val;
						}
						this->_tab[i] = tab_tmp[k++];
					}
					get_allocator().deallocate(tab_tmp, 0);
				}
				else
					insertn_not_alloc(position, val, n);
				this->_taille += n;
			}

			iterator erase (iterator position)
			{
				size_type	pos = position - _tab;
				value_type	*tmp = this->_tab;
				int			i = -1;
				int			k = 0;

				this->_taille--;
				this->_tab = get_allocator().allocate(this->_capacity);
				while (++i < pos)
					this->_tab[i] = tmp[k++];
				get_allocator().destroy(&tmp[k]);
				k++;
				while (i < this->_taille)
					this->_tab[i++] = tmp[k++];
				get_allocator().deallocate(tmp, this->_capacity);
				iterator ret = begin();
				while ((ret - _tab) < pos && (ret - _tab) < this->_taille - 1)
					ret++;
				return (ret);
			}

			iterator erase (iterator first, iterator last)
			{
				size_type	first_ = first - _tab;
				size_type	last_ = last - _tab;
				value_type	*tmp = this->_tab;
				int			i = -1;
				int			k = 0;

				this->_taille -= (last_ - first_);
				this->_tab = get_allocator().allocate(this->_capacity);
				while (++i < first_)
					this->_tab[i] = tmp[k++];
				while ((k - i) < (last_ - first_))
					k++;
				while (i < this->_taille)
					this->_tab[i++] = tmp[k++];
				get_allocator().deallocate(tmp, this->_capacity);
				iterator ret = begin();

				while ((ret - _tab) < first_ && (ret - _tab) < this->_taille - 1)
					ret++;
				return (ret);
			}

			void swap (vector& x)
			{
				value_type	*tmp;
				int			capa_tmp;
				int			size_tmp;

				tmp = x._tab;
				capa_tmp = x._capacity;
				size_tmp = x._taille;

				x._tab = this->_tab;
				x._capacity = this->_capacity;
				x._taille = this->_taille;

				this->_tab = tmp;
				this->_capacity = capa_tmp;
				this->_taille = size_tmp;
			}

			void clear()
			{
				int i = -1;

				while (++i < this->_taille)
					get_allocator().destroy(&_tab[i]);
				this->_taille = 0;
			}

			//..................................... Allocator ........................................

			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}

			//..................................... Utils ............................................

			void	ft_realoc(int new_capa, const value_type& val)
			{
				value_type *tmp = this->_tab;
				int i = -1;

				this->_tab = get_allocator().allocate(new_capa);
				while (++i < this->_taille)
					this->_tab[i] = tmp[i];
				this->_tab[i] = val;
				for (int i = 0; i < _taille; i++)
					_alloc.destroy(&tmp[i]);
				_alloc.deallocate(tmp, this->_capacity);
				this->_capacity = new_capa;
			}


		private:
			value_type		*_tab;
			size_type		_taille;
			size_type		_capacity;
			allocator_type	_alloc;
	};
}


#endif
