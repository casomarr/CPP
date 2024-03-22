#include "includes/ScalarConverter.hpp"

/* int main(int argc, char **argv) //main à envoyer
{
    int i = 1;
    if (argc < 2)
    {
		std::cout <<"Missing arguments. Enter a literal to convert." <<std::endl;
        return 1;
    }
    while(i < argc)
    {
        ScalarConverter::convert(argv[i]);
        std::cout <<std::endl;
        i++;
    }
    return 0;
} */

int main() //main de tests pour moi
{
    ScalarConverter::convert("c"); //GRAMMAR: pour appeler la fonction d'une classe non instantiable
    std::cout <<std::endl;
    ScalarConverter::convert("4");
    std::cout <<std::endl;
    ScalarConverter::convert("0");
    std::cout <<std::endl;
    ScalarConverter::convert("-42.0f");
    std::cout <<std::endl;
    ScalarConverter::convert("nan");
    std::cout <<std::endl;
    ScalarConverter::convert("inf");
    std::cout <<std::endl;
    ScalarConverter::convert("42*/");
    std::cout <<std::endl;
    //CHECK: Ces deux derniers tests, demander ce que je suis sensée afficher
    // ScalarConverter::convert("");
    // std::cout <<std::endl;
    // ScalarConverter::convert("caro"); //char non displayable, et les autres?
    // std::cout <<std::endl;
    return 0;
}