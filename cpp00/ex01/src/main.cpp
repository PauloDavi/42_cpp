/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:29:35 by paulo             #+#    #+#             */
/*   Updated: 2024/03/16 23:19:55 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phoneBook;
    std::string input;

    std::cout << BLUE << "---------- Welcome to the PhoneBook! ----------"
              << RESET << std::endl;

    while (true) {
        std::cout << GREEN << "Valid commands: ADD, SEARCH, EXIT" << RESET
                  << std::endl;
        std::cout << YELLOW << "Please enter a command: " << RESET;
        std::cin >> input;

        if (input == "EXIT") {
            std::cout << MAGENTA << "Bye!" << RESET << std::endl;
            return (EXIT_SUCCESS);
        } else if (input == "ADD") {
            phoneBook.addContact();
        } else if (input == "SEARCH") {
            phoneBook.searchContact();
        } else {
            std::cout << RED << "Invalid command, please try again." << RESET
                      << std::endl
                      << std::endl;
        }
    }
    return (EXIT_SUCCESS);
}
