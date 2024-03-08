#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class   Contact
{
    private :
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;
        std::string nickName;
        std::string secret;

    public :
        Contact();
        ~Contact();
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getPhoneNumber(void) const;
        std::string getNickName(void) const;
        std::string getSecret(void) const;


        void        setFirstName(std::string firstName);
        void        setLastName(std::string lastName);
        void        setPhoneNumber(std::string phoneNumber);
        void        setNickName(std::string nickName);
        void        setSecret(std::string secret);
};
#endif
