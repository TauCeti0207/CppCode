/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-22 12:58:02
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-22 13:36:21
 */
#include "vector.hpp"

namespace yzq
{

	// 默认构造函数实现
	template <typename T, typename Alloc>
	Vector<T, Alloc>::Vector(const Alloc &alloc)
		: alloc_(alloc), start_(nullptr), finish_(nullptr), end_of_storage_(nullptr) {}

	// 指定大小的构造函数实现
	template <typename T, typename Alloc>
	Vector<T, Alloc>::Vector(size_type count, const T &value, const Alloc &alloc)
		: alloc_(alloc), start_(nullptr), finish_(nullptr), end_of_storage_(nullptr)
	{
		if (count > 0)
		{
			start_ = allocate_and_construct(count, value);
			finish_ = start_ + count;
			end_of_storage_ = finish_;
		}
	}

	// 拷贝构造函数实现
	template <typename T, typename Alloc>
	Vector<T, Alloc>::Vector(const Vector &other)
		: alloc_(std::allocator_traits<Alloc>::select_on_container_copy_construction(other.alloc_)),
		  start_(nullptr), finish_(nullptr), end_of_storage_(nullptr)
	{
		if (other.size() > 0)
		{
			start_ = allocate_and_construct(other.size());
			std::uninitialized_copy(other.begin(), other.end(), start_);
			finish_ = start_ + other.size();
			end_of_storage_ = finish_;
		}
	}

	// 移动构造函数实现
	template <typename T, typename Alloc>
	Vector<T, Alloc>::Vector(Vector &&other) noexcept
		: alloc_(std::move(other.alloc_)),
		  start_(other.start_),
		  finish_(other.finish_),
		  end_of_storage_(other.end_of_storage_)
	{
		other.start_ = nullptr;
		other.finish_ = nullptr;
		other.end_of_storage_ = nullptr;
	}

	// 初始化列表构造函数实现
	template <typename T, typename Alloc>
	Vector<T, Alloc>::Vector(std::initializer_list<T> init, const Alloc &alloc)
		: alloc_(alloc), start_(nullptr), finish_(nullptr), end_of_storage_(nullptr)
	{
		if (init.size() > 0)
		{
			start_ = allocate_and_construct(init.size());
			std::uninitialized_copy(init.begin(), init.end(), start_);
			finish_ = start_ + init.size();
			end_of_storage_ = finish_;
		}
	}

	// 析构函数实现
	template <typename T, typename Alloc>
	Vector<T, Alloc>::~Vector()
	{
		destroy_and_deallocate();
	}

	// 拷贝赋值运算符实现
	template <typename T, typename Alloc>
	Vector<T, Alloc> &Vector<T, Alloc>::operator=(const Vector &other)
	{
		if (this != &other)
		{
			// 处理自赋值的情况
			if (alloc_ == other.alloc_)
			{
				// 分配器兼容，可以直接复用内存
				if (other.size() <= capacity())
				{
					// 现有容量足够，直接覆盖元素
					std::copy(other.begin(), other.begin() + std::min(size(), other.size()), begin());
					if (other.size() > size())
					{
						// 需要构造更多元素
						std::uninitialized_copy(other.begin() + size(), other.end(), finish_);
					}
					else if (other.size() < size())
					{
						// 需要销毁多余元素
						for (T *p = finish_; p != start_ + other.size();)
						{
							std::allocator_traits<Alloc>::destroy(alloc_, --p);
						}
					}
					finish_ = start_ + other.size();
				}
				else
				{
					// 容量不足，重新分配内存
					destroy_and_deallocate();
					start_ = allocate_and_construct(other.size());
					std::uninitialized_copy(other.begin(), other.end(), start_);
					finish_ = start_ + other.size();
					end_of_storage_ = finish_;
				}
			}
			else
			{
				// 分配器不兼容，需要使用其他分配器
				Vector temp(other, alloc_);
				swap(temp);
			}
		}
		return *this;
	}

	// 移动赋值运算符实现
	template <typename T, typename Alloc>
	Vector<T, Alloc> &Vector<T, Alloc>::operator=(Vector &&other) noexcept
	{
		if (this != &other)
		{
			destroy_and_deallocate();
			alloc_ = std::move(other.alloc_);
			start_ = other.start_;
			finish_ = other.finish_;
			end_of_storage_ = other.end_of_storage_;
			other.start_ = nullptr;
			other.finish_ = nullptr;
			other.end_of_storage_ = nullptr;
		}
		return *this;
	}

	// 初始化列表赋值运算符实现
	template <typename T, typename Alloc>
	Vector<T, Alloc> &Vector<T, Alloc>::operator=(std::initializer_list<T> ilist)
	{
		assign(ilist);
		return *this;
	}

	// assign方法实现
	template <typename T, typename Alloc>
	template <typename Alloc2>
	void Vector<T, Alloc>::assign(size_type count, const T &value, const Alloc2 &alloc)
	{
		if (count > capacity())
		{
			// 容量不足，重新分配
			destroy_and_deallocate();
			start_ = allocate_and_construct(count, value);
			finish_ = start_ + count;
			end_of_storage_ = finish_;
		}
		else if (count > size())
		{
			// 现有容量足够，但需要更多元素
			std::fill(begin(), end(), value);
			std::uninitialized_fill_n(finish_, count - size(), value);
			finish_ = start_ + count;
		}
		else
		{
			// 现有容量足够，且有多余元素
			std::fill(begin(), begin() + count, value);
			for (T *p = finish_; p != start_ + count;)
			{
				std::allocator_traits<Alloc>::destroy(alloc_, --p);
			}
			finish_ = start_ + count;
		}
	}

	// 初始化列表assign方法实现
	template <typename T, typename Alloc>
	void Vector<T, Alloc>::assign(std::initializer_list<T> ilist)
	{
		if (ilist.size() > capacity())
		{
			// 容量不足，重新分配
			destroy_and_deallocate();
			start_ = allocate_and_construct(ilist.size());
			std::uninitialized_copy(ilist.begin(), ilist.end(), start_);
			finish_ = start_ + ilist.size();
			end_of_storage_ = finish_;
		}
		else if (ilist.size() > size())
		{
			// 现有容量足够，但需要更多元素
			std::copy(ilist.begin(), ilist.begin() + size(), begin());
			std::uninitialized_copy(ilist.begin() + size(), ilist.end(), finish_);
			finish_ = start_ + ilist.size();
		}
		else
		{
			// 现有容量足够，且有多余元素
			std::copy(ilist.begin(), ilist.end(), begin());
			for (T *p = finish_; p != start_ + ilist.size();)
			{
				std::allocator_traits<Alloc>::destroy(alloc_, --p);
			}
			finish_ = start_ + ilist.size();
		}
	}

	// 获取分配器实现
	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::allocator_type Vector<T, Alloc>::get_allocator() const noexcept
	{
		return alloc_;
	}

	// at方法实现
	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::at(size_type pos)
	{
		if (pos >= size())
		{
			throw std::out_of_range("Vector<T>::at: pos >= size()");
		}
		return (*this)[pos];
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::at(size_type pos) const
	{
		if (pos >= size())
		{
			throw std::out_of_range("Vector<T>::at: pos >= size()");
		}
		return (*this)[pos];
	}

	// 重载[]运算符实现
	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::operator[](size_type pos)
	{
		return start_[pos];
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::operator[](size_type pos) const
	{
		return start_[pos];
	}

	// front方法实现
	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::front()
	{
		return *begin();
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::front() const
	{
		return *begin();
	}

	// back方法实现
	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::reference Vector<T, Alloc>::back()
	{
		return *(end() - 1);
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reference Vector<T, Alloc>::back() const
	{
		return *(end() - 1);
	}

	// data方法实现
	template <typename T, typename Alloc>
	T *Vector<T, Alloc>::data() noexcept
	{
		return start_;
	}

	template <typename T, typename Alloc>
	const T *Vector<T, Alloc>::data() const noexcept
	{
		return start_;
	}

	// 迭代器方法实现
	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::begin() noexcept
	{
		return start_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::begin() const noexcept
	{
		return start_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::cbegin() const noexcept
	{
		return start_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::end() noexcept
	{
		return finish_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::end() const noexcept
	{
		return finish_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::cend() const noexcept
	{
		return finish_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rbegin() noexcept
	{
		return reverse_iterator(end());
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::rbegin() const noexcept
	{
		return const_reverse_iterator(end());
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::crbegin() const noexcept
	{
		return const_reverse_iterator(end());
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rend() noexcept
	{
		return reverse_iterator(begin());
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::rend() const noexcept
	{
		return const_reverse_iterator(begin());
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator Vector<T, Alloc>::crend() const noexcept
	{
		return const_reverse_iterator(begin());
	}

	// 容量相关方法实现
	template <typename T, typename Alloc>
	bool Vector<T, Alloc>::empty() const noexcept
	{
		return begin() == end();
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::size() const noexcept
	{
		return finish_ - start_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::max_size() const noexcept
	{
		return std::allocator_traits<Alloc>::max_size(alloc_);
	}

	template <typename T, typename Alloc>
	void Vector<T, Alloc>::reserve(size_type new_cap)
	{
		if (new_cap > max_size())
		{
			throw std::length_error("Vector<T>::reserve: new_cap > max_size()");
		}
		if (new_cap > capacity())
		{
			reallocate(new_cap);
		}
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::size_type Vector<T, Alloc>::capacity() const noexcept
	{
		return end_of_storage_ - start_;
	}

	template <typename T, typename Alloc>
	void Vector<T, Alloc>::shrink_to_fit()
	{
		if (size() < capacity())
		{
			reallocate(size());
		}
	}

	// 修改器方法实现
	template <typename T, typename Alloc>
	void Vector<T, Alloc>::clear() noexcept
	{
		for (T *p = finish_; p != start_;)
		{
			std::allocator_traits<Alloc>::destroy(alloc_, --p);
		}
		finish_ = start_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(const_iterator pos, const T &value)
	{
		const size_type index = pos - cbegin();
		if (pos == cend() || size() == 0)
		{
			push_back(value);
			return begin() + index;
		}
		else
		{
			ensure_capacity();
			// 移动元素为新元素腾出空间
			const size_type elements_after = finish_ - pos;
			T *new_pos = start_ + index;
			std::uninitialized_copy_backward(pos, cend(), finish_ + 1);
			// 构造新元素
			std::allocator_traits<Alloc>::construct(alloc_, new_pos, value);
			++finish_;
			return new_pos;
		}
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(const_iterator pos, T &&value)
	{
		const size_type index = pos - cbegin();
		if (pos == cend() || size() == 0)
		{
			push_back(std::move(value));
			return begin() + index;
		}
		else
		{
			ensure_capacity();
			// 移动元素为新元素腾出空间
			const size_type elements_after = finish_ - pos;
			T *new_pos = start_ + index;
			std::uninitialized_copy_backward(pos, cend(), finish_ + 1);
			// 构造新元素
			std::allocator_traits<Alloc>::construct(alloc_, new_pos, std::move(value));
			++finish_;
			return new_pos;
		}
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(const_iterator pos, size_type count, const T &value)
	{
		if (count == 0)
			return const_cast<iterator>(pos);

		const size_type index = pos - cbegin();
		if (count > capacity() - size())
		{
			// 需要重新分配内存
			const size_type new_size = size() + count;
			reallocate(std::max(new_size, capacity() * 2));
		}

		T *new_pos = start_ + index;
		const size_type elements_after = finish_ - new_pos;

		if (elements_after > count)
		{
			// 有足够空间移动元素
			std::uninitialized_copy_backward(new_pos, finish_, finish_ + count);
			std::fill_n(new_pos, count, value);
		}
		else
		{
			// 空间不足，需要部分构造
			std::uninitialized_fill_n(finish_, count - elements_after, value);
			std::uninitialized_copy(new_pos, finish_, finish_ + count - elements_after);
			std::fill_n(new_pos, elements_after, value);
		}

		finish_ += count;
		return new_pos;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(const_iterator pos, const_iterator first, const_iterator last)
	{
		if (first == last)
			return const_cast<iterator>(pos);

		const size_type count = last - first;
		const size_type index = pos - cbegin();

		if (count > capacity() - size())
		{
			// 需要重新分配内存
			const size_type new_size = size() + count;
			reallocate(std::max(new_size, capacity() * 2));
		}

		T *new_pos = start_ + index;
		const size_type elements_after = finish_ - new_pos;

		if (elements_after > count)
		{
			// 有足够空间移动元素
			std::uninitialized_copy_backward(new_pos, finish_, finish_ + count);
			std::copy(first, last, new_pos);
		}
		else
		{
			// 空间不足，需要部分构造
			const_iterator mid = first + (count - elements_after);
			std::uninitialized_copy(mid, last, finish_);
			std::uninitialized_copy(new_pos, finish_, finish_ + (count - elements_after));
			std::copy(first, mid, new_pos);
		}

		finish_ += count;
		return new_pos;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::insert(const_iterator pos, std::initializer_list<T> ilist)
	{
		return insert(pos, ilist.begin(), ilist.end());
	}

	template <typename T, typename Alloc>
	template <typename... Args>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::emplace(const_iterator pos, Args &&...args)
	{
		const size_type index = pos - cbegin();
		if (pos == cend() || size() == 0)
		{
			emplace_back(std::forward<Args>(args)...);
			return begin() + index;
		}
		else
		{
			ensure_capacity();
			// 移动元素为新元素腾出空间
			const size_type elements_after = finish_ - pos;
			T *new_pos = start_ + index;
			std::uninitialized_copy_backward(pos, cend(), finish_ + 1);
			// 构造新元素
			std::allocator_traits<Alloc>::construct(alloc_, new_pos, std::forward<Args>(args)...);
			++finish_;
			return new_pos;
		}
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(const_iterator pos)
	{
		if (pos == cend())
			return end();

		T *new_pos = const_cast<iterator>(pos);
		// 销毁当前元素
		std::allocator_traits<Alloc>::destroy(alloc_, new_pos);
		// 移动后面的元素填补空缺
		std::copy(new_pos + 1, finish_, new_pos);
		--finish_;
		return new_pos;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(const_iterator first, const_iterator last)
	{
		if (first == last)
			return const_cast<iterator>(first);

		T *new_first = const_cast<iterator>(first);
		T *new_last = const_cast<iterator>(last);

		// 销毁要删除的元素
		for (T *p = new_first; p != new_last; ++p)
		{
			std::allocator_traits<Alloc>::destroy(alloc_, p);
		}

		// 移动后面的元素填补空缺
		const size_type elements_moved = finish_ - new_last;
		std::copy(new_last, finish_, new_first);

		// 更新finish_
		finish_ -= (new_last - new_first);
		return new_first;
	}
}