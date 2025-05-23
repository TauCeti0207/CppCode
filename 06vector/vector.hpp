// yzq命名空间下的Vector类实现
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>			// for std::allocator
#include <stdexcept>		// for std::out_of_range
#include <utility>			// for std::move, std::swap
#include <algorithm>		// for std::copy, std::fill, std::equal, std::lexicographical_compare
#include <initializer_list> // for std::initializer_list

namespace yzq
{

	template <typename T, typename Alloc = std::allocator<T>>
	class Vector
	{
	public:
		// 类型别名定义
		using value_type = T;
		using allocator_type = Alloc;
		using reference = value_type &;
		using const_reference = const value_type &;
		using pointer = typename std::allocator_traits<Alloc>::pointer;
		using const_pointer = typename std::allocator_traits<Alloc>::const_pointer;
		using iterator = pointer;
		using const_iterator = const_pointer;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
		using difference_type = typename std::allocator_traits<Alloc>::difference_type;
		using size_type = typename std::allocator_traits<Alloc>::size_type;

		// 默认构造函数
		explicit Vector(const Alloc &alloc = Alloc());

		// 构造指定大小的vector，并用默认值填充
		explicit Vector(size_type count, const T &value = T(), const Alloc &alloc = Alloc());

		// 拷贝构造函数
		Vector(const Vector &other);

		// 移动构造函数
		Vector(Vector &&other) noexcept;

		// 初始化列表构造函数
		Vector(std::initializer_list<T> init, const Alloc &alloc = Alloc());

		// 析构函数
		~Vector();

		// 拷贝赋值运算符
		Vector &operator=(const Vector &other);

		// 移动赋值运算符
		Vector &operator=(Vector &&other) noexcept;

		// 初始化列表赋值运算符
		Vector &operator=(std::initializer_list<T> ilist);

		// 使用指定分配器的拷贝赋值
		template <typename Alloc2>
		void assign(size_type count, const T &value, const Alloc2 &alloc = Alloc2());

		// 使用初始化列表赋值
		void assign(std::initializer_list<T> ilist);

		// 获取分配器
		allocator_type get_allocator() const noexcept;

		// 元素访问
		reference at(size_type pos);
		const_reference at(size_type pos) const;

		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		T *data() noexcept;
		const T *data() const noexcept;

		// 迭代器
		iterator begin() noexcept;
		const_iterator begin() const noexcept;
		const_iterator cbegin() const noexcept;

		iterator end() noexcept;
		const_iterator end() const noexcept;
		const_iterator cend() const noexcept;

		reverse_iterator rbegin() noexcept;
		const_reverse_iterator rbegin() const noexcept;
		const_reverse_iterator crbegin() const noexcept;

		reverse_iterator rend() noexcept;
		const_reverse_iterator rend() const noexcept;
		const_reverse_iterator crend() const noexcept;

		// 容量相关
		bool empty() const noexcept;
		size_type size() const noexcept;
		size_type max_size() const noexcept;
		void reserve(size_type new_cap);
		size_type capacity() const noexcept;
		void shrink_to_fit();

		// 修改器
		void clear() noexcept;

		iterator insert(const_iterator pos, const T &value);
		iterator insert(const_iterator pos, T &&value);
		iterator insert(const_iterator pos, size_type count, const T &value);
		iterator insert(const_iterator pos, const_iterator first, const_iterator last);
		iterator insert(const_iterator pos, std::initializer_list<T> ilist);

		template <typename... Args>
		iterator emplace(const_iterator pos, Args &&...args);

		iterator erase(const_iterator pos);
		iterator erase(const_iterator first, const_iterator last);

		void push_back(const T &value);
		void push_back(T &&value);

		template <typename... Args>
		reference emplace_back(Args &&...args);

		void pop_back();

		void resize(size_type count);
		void resize(size_type count, const value_type &value);

		void swap(Vector &other) noexcept;

	private:
		Alloc alloc_;		// 分配器实例
		T *start_;			// 指向内存起始位置的指针
		T *finish_;			// 指向最后一个元素之后位置的指针
		T *end_of_storage_; // 指向已分配内存末尾的指针

		// 辅助函数：销毁所有元素并释放内存
		void destroy_and_deallocate();

		// 辅助函数：分配内存并构造元素
		T *allocate_and_construct(size_type count, const T &value = T());

		// 辅助函数：重新分配更大的内存并移动元素
		void reallocate(size_type new_cap);

		// 辅助函数：扩展容量以容纳至少一个元素
		void ensure_capacity();
	};

	// 比较运算符重载
	template <typename T, typename Alloc>
	bool operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

	template <typename T, typename Alloc>
	bool operator!=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

	template <typename T, typename Alloc>
	bool operator<(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

	template <typename T, typename Alloc>
	bool operator<=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

	template <typename T, typename Alloc>
	bool operator>(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

	template <typename T, typename Alloc>
	bool operator>=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs);

	// 交换函数
	template <typename T, typename Alloc>
	void swap(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs) noexcept;

} // namespace yzq

#endif // VECTOR_HPP