#pragma once

#include <iostream>
#include <string>
#include <cstdlib> //for std::srand
#include <cctype>
#include <cmath>
#include <ctime> //for std::time
// #include <random>

//CHECK if accepted by norm to have all classes in the same .hpp file

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
		A() {}; //CHECK si j'ai le droit de les déclarer ici de la sorte
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