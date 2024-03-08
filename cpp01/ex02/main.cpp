#include <string>
#include <iostream>

void    printStringRef(std::string& str)
{
    std::cout << "test for string reference" << std::endl;
    std::cout << "address : " << &str << std::endl;
}

void    printStringPtr(std::string* str)
{
    std::cout << "test for string pointer" << std::endl;
    std::cout << "address : " << &str << std::endl;
}

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    std::cout << brain << std::endl << std::endl;
    
    std::cout << "address for original string" << std::endl << &brain << std::endl;;

    std::cout << "address of stringPTR at main" << std::endl << &stringPTR << std::endl;

    std::cout << "sddress of stringREF at main" << std::endl << &stringREF << std::endl;

    printStringPtr(stringPTR);
    printStringRef(stringREF);
}