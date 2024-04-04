#pragma once

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cstdlib>


class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		RPN(std::string operation);
		void check_valid_operation(std::string operation);
		void reverse_polish_notation();

	private:
		std::stack<int> _numbers;
		std::stack<char> _signs;

};

