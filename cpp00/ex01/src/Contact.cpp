/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:21:24 by paulo             #+#    #+#             */
/*   Updated: 2024/03/16 23:23:08 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static std::string truncateText(const std::string& text);

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
    return;
}

Contact::Contact(void) { return; }

Contact::~Contact(void) { return; }

void Contact::displayContactRow(size_t index) {
    std::cout << "|" << std::setw(10) << index << "|" << std::setw(10)
              << truncateText(firstName) << "|" << std::setw(10)
              << truncateText(lastName) << "|" << std::setw(10)
              << truncateText(nickname) << "|" << std::endl;
}

void Contact::displayContact(void) {
    std::cout << BLUE << std::endl
              << "First name: " << RESET << firstName << std::endl;
    std::cout << BLUE << "Last name: " << RESET << lastName << std::endl;
    std::cout << BLUE << "Nickname: " << RESET << nickname << std::endl;
    std::cout << BLUE << "Phone number: " << RESET << phoneNumber << std::endl;
    std::cout << BLUE << "Darkest secret: " << RESET << darkestSecret
              << std::endl
              << std::endl;
}

static std::string truncateText(const std::string& text) {
    if (text.length() > 10) {
        return text.substr(0, 9) + ".";
    } else {
        return text;
    }
}
