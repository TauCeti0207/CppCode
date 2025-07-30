/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-06 21:35:13
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-06 21:36:21
 */
// person.h
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>

class Person
{
public:
	// 构造函数
	Person(const char *name = "", const char *sex = "", int age = 0);
	// 拷贝构造函数
	Person(const Person &other);
	// 赋值运算符重载
	Person &operator=(const Person &other);
	// 析构函数
	~Person();
	// 显示信息
	void show();

private:
	char *_name;
	char *_sex;
	int _age;
};

#endif // PERSON_H