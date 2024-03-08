#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    std::string cmd;
    PhoneBook Phonebook;

    while (cmd != "EXIT")
    {
        std::cout << "enter command (ADD/SEARCH/EXIT) : ";
        std::getline(std::cin, cmd);
        if (std::cin.eof() || std::cin.fail())
            break;
        if (cmd == "ADD"){
            Phonebook.setContact();
        } else if (cmd == "SEARCH") {
            Phonebook.show();
            Phonebook.searchContact();
        }
    }
}
