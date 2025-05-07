/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-07 00:50:38
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-07 12:20:57
 */
// Date.h
#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
	int _year; // 这里只是声明
	int _month;
	int _day;

	// 判断是否为闰年
	bool isLeapYear(int y) const;
	// 获取指定月份的天数
	int getDaysInMonth(int y, int m) const;

public:
	// 构造函数
	Date(int y = 1900, int m = 1, int d = 1);
	// 拷贝构造函数
	Date(const Date &other);
	// 赋值运算符重载
	Date &operator=(const Date &other);
	// 析构函数
	~Date();

	// 获取日期信息
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	// 设置日期信息
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);

	// 日期合法性检查
	bool isValidDate() const;

	// 日期比较运算符重载
	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator<(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator>=(const Date &other) const;

	// 日期自增自减运算符重载
	Date &operator++();	  // 前置自增
	Date operator++(int); // 后置自增
	Date &operator--();	  // 前置自减
	Date operator--(int); // 后置自减

	// 日期加减天数运算符重载
	Date operator+(int days) const;
	Date operator-(int days) const;
	int operator-(const Date &other) const;

	// 输出日期
	friend std::ostream &operator<<(std::ostream &os, const Date &date);
	// 输入日期
	friend std::istream &operator>>(std::istream &is, Date &date);
};

#endif // DATE_H