/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:55:47 by paulo             #+#    #+#             */
/*   Updated: 2024/03/16 23:18:32 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void printUppercase(const std::string &str);

const std::string DEFAULT_MESSAGE = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << DEFAULT_MESSAGE << std::endl;
        return (0);
    }
    for (size_t i = 1; i < argc; i++) {
        std::string arg = argv[i];
        printUppercase(arg);
    }
    std::cout << std::endl;
}

static void printUppercase(const std::string &str) {
    for (std::string::const_iterator it = str.cbegin(); it < str.cend(); ++it)
        std::cout << static_cast<char>(std::toupper(*it));
}
