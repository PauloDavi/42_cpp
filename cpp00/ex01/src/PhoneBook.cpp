/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:22:01 by paulo             #+#    #+#             */
/*   Updated: 2024/03/16 23:23:08 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void printTableHead(void);
static Contact createNewContact(void);

PhoneBook::PhoneBook(void) {
    contactCount = 0;
    return;
}

PhoneBook::~PhoneBook(void) { return; }

void PhoneBook::addContact(void) {
    Contact newContact = createNewContact();
    if (contactCount < MAX_CONTACTS) {
        contacts[contactCount++] = newContact;
    } else {
        for (size_t i = 0; i < MAX_CONTACTS - 1; i++)
            contacts[i] = contacts[i + 1];
        contacts[MAX_CONTACTS - 1] = newContact;
    }
}

void PhoneBook::searchContact(void) {
    size_t index;

    if (contactCount == 0) {
        std::cout << RED << "No contacts to display." << RESET << std::endl
                  << std::endl;
        return;
    }

    printTableHead();
    for (size_t i = 0; i < contactCount; i++) contacts[i].displayContactRow(i);
    std::cout << DASH << std::endl;

    std::cout << YELLOW
              << "Enter the index of the contact you want to display: "
              << RESET;
    std::cin >> index;
    if (index < contactCount) {
        contacts[index].displayContact();
    } else {
        std::cout << RED << "Invalid index." << RESET << std::endl << std::endl;
    }
}

static Contact createNewContact(void) {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << std::endl << MAGENTA << "Add a contact" << RESET << std::endl;
    std::cout << YELLOW << "First name: " << RESET;
    std::cin >> firstName;
    std::cout << YELLOW << "Last name: " << RESET;
    std::cin >> lastName;
    std::cout << YELLOW << "Nickname: " << RESET;
    std::cin >> nickname;
    std::cout << YELLOW << "Phone number: " << RESET;
    std::cin >> phoneNumber;
    std::cout << YELLOW << "Darkest secret: " << RESET;
    std::cin >> darkestSecret;
    std::cout << std::endl;

    return (Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
}

static void printTableHead(void) {
    std::cout << std::endl << DASH << std::endl;
    std::cout << "|" << BLUE << std::setw(10) << "Index" << RESET << "|" << BLUE
              << std::setw(10) << "First name" << RESET << "|" << BLUE
              << std::setw(10) << "Last name" << RESET << "|" << BLUE
              << std::setw(10) << "Nickname" << RESET << "|" << std::endl;
    std::cout << DASH << std::endl;
}
