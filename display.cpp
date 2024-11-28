#include <iostream>
#include "display.h"

void print_options() {
    std::cout << "What would you like to do?" << std::endl;
	std::cout << "	1. View entire character list" << std::endl;
	std::cout << "	2. Search by character name" << std::endl;
	std::cout << "	3. Add a character" << std::endl;
	std::cout << "	4. Delete a character" << std::endl;
    std::cout << "  5. Alphabetize the list of characters" << std::endl;
    std::cout << "	6. Get more info about a name" << std::endl;
    std::cout << "	7. Generate a name" << std::endl;
	std::cout << "	8. Quit" << std::endl;
}

int prompt_for_option(int num_options) {
    std::string input;
    bool valid = true;
    do {
        std::cout << "Enter a number corresponding to an option: ";
        std::cin >> input;
        valid = input.length() == 1 && (input[0] - '1' >= 0 && input[0] - '1' < num_options);
        if (!valid) {
            std::cout << "Not a valid option! Please try again." << std::endl;
        }
    } while (!valid);

    std::cout << std::endl;
    return std::stoi(input);
}

std::string prompt_for_character_appearance() {
    std::cout << "Enter the appearance of the character: " << std::endl;
    std::string appearance;
    getline(std::cin, appearance);

    return appearance;
}

std::string prompt_for_character_description() {
    std::cout << "Enter the description of the character: " << std::endl;
    std::string description;
    getline(std::cin, description);

    return description;
}

std::string prompt_for_character_info(std::string detail) {
    std::cout << "Enter the " << detail << " of the character: ";
    std::string info;
    std::cin >> info;

    return info;
}

std::string prompt_for_name() {
    std::cout << "Enter the name (one word): ";
    std::string name;
    std::cin >> name;
    return name;
}