#include "catalog.h"
#include <iostream>

void catalog::populate_catalog_from_file(std::ifstream& file) {
    std::string first_input;
    getline(file, first_input);
    this->num_characters = std::stoi(first_input);

    for (int i = 0; i < this->num_characters; i++) {
        character ch;
        ch.populate_character_from_file(file);
        this->characters.push_back(ch);
    }
}

void catalog::display_all_characters() {
    for (int i = 0; i < this->num_characters; i++) {
        this->characters[i].print_character_info();
        std::cout << std::endl;
    }
}

void catalog::print_searched_character(std::string name) {
    for (int i = 0; i < this->num_characters; i++) {
        std::cout << this->characters[i].get_name() << "8" << std::endl;
        std::cout << name << "8" << std::endl;
        if (this->characters[i].get_name() == name) {
            this->characters[i].print_character_info();
            return;
        }
    }

    std::cout << "Sorry, this character currently doesn't exist." << std::endl;
}

void catalog::add_character(std::string name, std::string gender, std::string age, std::string appearance, std::string description) {
    character new_char(name, gender, age, appearance, description);
    this->characters.push_back(new_char);

    this->num_characters++;
}

void catalog::delete_character(std::string name) {
    for (int i = 0; i < this->num_characters; i++) {
        if (this->characters[i].get_name() == name) {
            this->characters.erase(this->characters.begin() + i);
            return;
        }
    }

    std::cout << "Sorry, this character currently doesn't exist." << std::endl;
}