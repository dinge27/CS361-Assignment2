#include "catalog.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

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

void catalog::write_catalog_to_file(std::ofstream& file) {
    file << this->num_characters << std::endl;
    for (int i = 0; i < this->num_characters; i++) {
        this->characters[i].write_character_to_file(file);
        file << std::endl;
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

bool delete_confirmation(std::string name) {
    std::cout << "Are you sure you want to delete " << name << " from the character list? " <<
        "Enter y/n: ";
    std::string input;
    std::cin >> input;

    return input == "y" || input == "yes";
}

void catalog::delete_character(std::string name) {
    for (int i = 0; i < this->num_characters; i++) {
        if (this->characters[i].get_name() == name) {
            if (delete_confirmation(name)) {
                this->characters.erase(this->characters.begin() + i);
                this->num_characters--;
                std::cout << "The character " << name << " has been deleted from the character list." << std::endl;
            } else {
                std::cout << "No character will be deleted." << std::endl;
            }
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "Sorry, this character doesn't exist." << std::endl;
    std::cout << std::endl;
}

std::vector<std::string> get_sorted_names(std::vector<std::string> names) {
    using json = nlohmann::json;

    std::string url = "http://127.0.0.1:5002/alphabetizer";

    json json_names;
    json_names["names"] = names;

    cpr::Response response = cpr::Get(cpr::Url{url},
                               cpr::Parameters{{"names", json_names["names"]}});

    if (response.status_code == 200) {
        json_names = json::parse(response.text);
        names = json_names["names"];
    } else {
        std::cerr << "Error: " << response.status_code << "\nDetails: " << response.text << "\n";
    }

    return names;
}

std::vector<std::string> catalog::sort_characters() {
    // Makes a vector of just the names
    std::vector<std::string> names;
    for (int i = 0; i < this->num_characters; i++) {
        names.push_back(this->characters.at(i).get_name());
    }

    names = get_sorted_names(names);
    return names;
}