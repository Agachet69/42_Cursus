/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:40:33 by agachet           #+#    #+#             */
/*   Updated: 2022/01/20 17:03:38 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <memory>
#include <iostream>
#include <string>
#include "reverse_iterator.hpp"



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
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;
			typedef Allocator									allocator_type;

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

			vector (iterator first, iterator last, const allocator_type& alloc = allocator_type())
			{
				size_type	pos_f = first - _tab;
				size_type	pos_l = last - _tab;
				this->_capacity = pos_l - pos_f - 1;
				this->_taille = this->_capacity;
				this->_tab = _alloc.allocate(this->_capacity);
				for (int i = 0; first != last; ++first)
					this->_tab[i++] = *first;
			}

			vector (const vector& x)
			{
				this->_taille = x._taille;
				this->_capacity = x._capacity;
				this->_alloc = x._alloc;
				this->_tab = _alloc.allocate(this->_capacity);
				for (int i = 0; i < this->_taille; i++)
					this->_tab[i] = x._tab[i];
			}

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

			const_iterator begin() const
			{
				return (this->_tab);
			}

			iterator end()
			{
				return (this->_tab + this->_taille);
			}

			const_iterator end() const
			{
				return (this->_tab);
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}

			reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
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

			const_reference operator[] (size_type n) const
			{
				return (this->_tab[n]);
			}

			reference at (size_type n)
			{
				if (n < 0 || n >= this->_taille)
					throw std::out_of_range ("out");
				return (this->_tab[n]);
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n >= this->_taille)
					throw std::out_of_range ("out");
				return (this->_tab[n]);
			}

			reference front()
			{
				return (this->_tab[0]);
			}

			const_reference front() const
			{
				return (this->_tab[0]);
			}

			reference back()
			{
				return (this->_tab[this->_taille - 1]);
			}

			const_reference back() const
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

  			void assign (iterator first, iterator last)
			{
				size_type	pos_f = first - _tab;
				size_type	pos_l = last - _tab;
				size_type	size = pos_l - pos_f;

				_alloc.deallocate(_tab, this->_capacity);
				if (this->_capacity < size)
					this->_capacity = (size);
				this->_tab = get_allocator().allocate(_capacity);
				for (int i = 0; first != last; first++)
					this->_tab[i++] = *first;
				this->_taille = (size);
			}

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

			void insert (iterator position, iterator first, iterator last)
			{
				size_type	size = (last - _tab) - (first - _tab);
				size_type	prev_capa = this->_capacity;
				value_type	*tmp = this->_tab;
				size_type	pos = position - tmp;
				int			i;

				if (size > this->_capacity - this->_taille)
				{
					this->_tab = _alloc.allocate(_capacity * 2);
					this->_capacity *= 2;
				}
				else
					this->_tab = _alloc.allocate(_capacity);
				for (i = -1; pos != i; i++)
					this->_tab[i] = tmp[i];
				while (first != last)
				{
					this->_tab[i++] = *first;
					first++;
				}
				while (pos < this->_taille)
				{
					this->_tab[pos + size] = tmp[pos];
					pos++;
				}
				if (size > this->_capacity - this->_taille)
					_alloc.deallocate(tmp, prev_capa);
				this->_taille += size;
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
	};

			//..................................... Relational Operators ................................

			template <class T, class Alloc>
			bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				if (lhs.size() != rhs.size())
					return (0);
				for (size_t i = 0; i < lhs.size(); i++)
				{
					if (lhs[i] != rhs[i])
						return (0);
				}
				return (1);
			}

			template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				if (lhs.size() != rhs.size())
					return (1);
				for (size_t i = 0; i < lhs.size(); i++)
				{
					if (lhs[i] != rhs[i])
						return (1);
				}
				return (0);
			}

			template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

			template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return ((lhs < rhs) || (lhs == rhs));
			}

			template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return (!(lhs < rhs) && lhs != rhs);
			}

			template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			{
				return ((lhs > rhs) || (lhs == rhs));
			}

			//..................................... Swap ...............................................
			template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
			{
				size_t tmp_capa = x._capacity;
				size_t tmp_taille = x._taille;
				T *tmp = x._tab;
				Alloc tmp_alloc =  x._alloc;

				x._capacity = y.capacity;
				x._taille = y._taille;
				x._tab = y._tab;
				x._alloc = y._alloc;

				y._capacity = tmp_capa;
				y._taille = tmp_taille;
				y._tab = tmp;
				y._alloc = tmp_alloc;
			}
}


#endif
