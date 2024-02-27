#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iomanip>

#define FULL 0
#define TRUNCATED 1

#define INPUT_ERROR "Error : Empty field or invalid format"

void	print_error();
bool	is_digits(const std::string str);
int		ask_index();
bool	isValidString(std::string buffer);
