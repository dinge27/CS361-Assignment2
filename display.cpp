#include <iostream>
#include "display.h"

void print_options() {
    std::cout << "What would you like to do?" << std::endl;
	std::cout << "	1. View entire character list" << std::endl;
	std::cout << "	2. Search by character name" << std::endl;
	std::cout << "	3. Add a character" << std::endl;
	std::cout << "	4. Delete a character" << std::endl;
    std::cout << "  5. Alphabetize the character list" << std::endl;
    std::cout << "	6. Get more info about a name" << std::endl;
    std::cout << "	7. Generate a list of names" << std::endl;
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

std::string prompt_for_gender() {
    std::string gender;
    bool valid = true;

    do {
        std::cout << "What gender would you like the list of names to be? Enter f/m: ";
        std::cin >> gender;
        valid = gender == "f" || gender == "m";
        if (!valid) {
            std::cout << "Not a valid gender! Please try again." << std::endl;
        }
    } while (!valid);

    return gender;
}

std::string prompt_for_number_of_names() {
    std::string number;
    bool valid = true;
    do {
        std::cout << "How many names would you like to generate? Enter a number 1-6: ";
        std::cin >> number;
        valid = number.length() == 1 && (number[0] - '1' >= 0 && number[0] - '1' < 6);
        if (!valid) {
            std::cout << "Not a valid option! Please try again." << std::endl;
        }
    } while (!valid);
    
    return number;
}