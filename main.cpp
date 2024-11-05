#include <iostream>
#include <fstream>
#include "catalog.h"

void print_options() {
    std::cout << "What would you like to do?" << std::endl;
	std::cout << "	1. View entire character list" << std::endl;
	std::cout << "	2. Search by a character" << std::endl;
	std::cout << "	3. Add a character" << std::endl;
	std::cout << "	4. Delete a character" << std::endl;
    std::cout << "	5. Get more info about a name" << std::endl;
    std::cout << "	6. Generate a name" << std::endl;
	std::cout << "	7. Quit" << std::endl;
}

int prompt_for_option(int num_options) {
    std::string input;
    bool valid = true;
    do {
        std::cout << "Select an option: ";
        std::cin >> input;
        valid = input.length() == 1 && (input[0] - '1' >= 0 && input[0] - '1' < num_options);
        if (!valid) {
            std::cout << "Not a valid option! Please try again." << std::endl;
        }
    } while (!valid);

    return std::stoi(input);
}

std::string prompt_for_character_name() {
    std::cout << "Enter the name of the character: ";
    std::string character_name;
    std::cin >> character_name;

    return character_name;
}

std::string prompt_for_character_gender() {
    std::cout << "Enter the gender of the character: ";
    std::string gender;
    std::cin >> gender;

    return gender;
}

std::string prompt_for_character_age() {
    std::cout << "Enter the age of the character: ";
    std::string age;
    std::cin >> age;

    return age;
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

void execute_option(catalog& c, int option) {
    if (option == 1) {
        c.display_all_characters();

    } else if (option == 2) {
        std::string name = prompt_for_character_name();
        c.print_searched_character(name);
        std::cout << std::endl;

    } else if (option == 3) {
        std::string name = prompt_for_character_name();
        std::string gender = prompt_for_character_gender();
        std::string age = prompt_for_character_age();
        std::cin.ignore();
        std::string appearance = prompt_for_character_appearance();
        std::string description = prompt_for_character_description();
        c.add_character(name, gender, age, appearance, description);

    } else if (option == 4) {
        std::string name = prompt_for_character_name();
        c.delete_character(name);

    } else if (option == 5) {

    } else {

    }
}

int main() {
    std::cout << "Welcome to the Character Catalog!" << std::endl;
    std::cout << "Organize your story's characters here. Record their name, ages, appearances, and descriptions for easy viewing." << std::endl;

    std::ifstream if_file;
    if_file.open("characters.txt");

    catalog c;
    c.populate_catalog_from_file(if_file);

    int option;

    do {
        print_options();
        option = prompt_for_option(7);

        execute_option(c, option);  

    } while (option != 7);
}