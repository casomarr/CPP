#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

void	open_file1(std::ifstream &file1, char *filename)
{
	file1.open(filename, std::ios::in); //in to read content
	if (!file1)
	{
		std::cout << "Failed to open file1" <<std::endl;
		throw std::runtime_error("Failed to open file1");
	}
}

void	open_file2(std::ofstream &file2, std::string filename)
{
	std::string filename2;

	filename2 = filename + ".replace";
	file2.open(filename2.c_str(), std::ios::out); //out to write
	if (!file2)
	{
		std::cout << "Failed to open file2" <<std::endl;
		throw std::runtime_error("Failed to open file2");
	}
}

void copy_and_replace(std::ifstream& file1, std::ofstream& file2, const std::string s1, const std::string s2) {
	std::string line;
	std::string content;

	while (std::getline(file1, line)) {
		content += line;
		content += "\n"; // Preserve newline characters
	}
	size_t pos = 0;
	pos = content.find(s1, pos);
	while (pos != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length(); //pos starts after the newly insterted string
		pos = content.find(s1, pos);
	}
	file2 << content;
}

int	main(int ac, char **av)
{
	std::ifstream	file1; //ifstream = infile
	std::ofstream	file2; //ofstream = outfile
	if (ac != 4 || std::strcmp(av[1], "") == 0 || std::strcmp(av[2], "") == 0 || std::strcmp(av[3], "") == 0)
	{
		std::cout << "Missing parameters : file_name, s1, s2 needed" <<std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		open_file1(file1, av[1]);
		open_file2(file2, std::string(av[1]));
	}
	catch (const std::runtime_error& e) //could use if else instead but this allows to return an error even when the function can only return something specific like a class or an fstream
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	copy_and_replace(file1, file2, std::string(av[2]), std::string(av[3]));
	file1.close();
	file2.close();
	return (EXIT_SUCCESS);
}
