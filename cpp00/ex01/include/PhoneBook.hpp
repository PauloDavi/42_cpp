
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
   private:
    static const size_t MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    size_t contactCount;

   public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact();
};

#endif
