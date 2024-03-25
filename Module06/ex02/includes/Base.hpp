#pragma once

#include <iostream>
#include <string>
#include <cstdlib> //for std::srand
#include <cctype>
#include <cmath>
#include <ctime> //for std::time

class Base
{
	public:
		virtual ~Base();
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

class A : public Base
{
	public:
		A() {};
};

class B : public Base
{
	public:
		B() {};
};

class C : public Base
{
	public:
		C() {};
};
