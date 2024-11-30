#include <iostream>
#include <fstream>
#include <cpr/cpr.h>
#include "catalog.h"
#include "display.h"

void lookup_name(std::string name) {
    std::string url = "http://127.0.0.1:5001";

    cpr::Response response = cpr::Get(cpr::Url{url + "/name-info"},
                               cpr::Parameters{{"name", name}});

    if (response.status_code == 200) {
        std::cout << "\n" << response.text << "\n";
    } else {
        std::cerr << "Error: " << response.status_code << "\nDetails: " << response.text << "\n";
    }
}

void lookup_list_of_names(std::string gender, std::string number) {
    std::string url = "http://127.0.0.1:5002/name_generator";

    cpr::Response response = cpr::Get(cpr::Url{url},
                             cpr::Parameters{{"gender", gender}, {"number", number}});
    
    if (response.status_code == 200) {
        std::cout << "\n" << response.text << "\n";
    } else {
        std::cerr << "Error: " << response.status_code << "\nDetails: " << response.text << "\n";
    }
}

void execute_option(catalog& c, int option) {
    if (option == 1) {
        c.display_all_characters();

    } else if (option == 2) {
        std::string name = prompt_for_character_info("name");
        std::cout << std::endl;
        c.print_searched_character(name);
        std::cout << std::endl;

    } else if (option == 3) {
        std::string name = prompt_for_character_info("name");
        std::string gender = prompt_for_character_info("gender");
        std::string age = prompt_for_character_info("age");
        std::cin.ignore();
        std::string appearance = prompt_for_character_appearance();
        std::string description = prompt_for_character_description();
        c.add_character(name, gender, age, appearance, description);

    } else if (option == 4) {
        std::string name = prompt_for_character_info("name");
        c.delete_character(name);

    } else if (option == 5) {
        c.sort_characters();

        // std::cout << "Here is the list of characters in alphabetical order: " << std::endl;
        // for (int i = 0; i < sorted_names.size(); i++) {
        //     std::cout << sorted_names.at(i) << std::endl;
        // }

        std::cout << std::endl;

    } else if (option == 6) {
        std::string name = prompt_for_name();
        lookup_name(name);
        std::cout << std::endl;

    } else if (option == 7) {
        std::string gender = prompt_for_gender();
        std::string number = prompt_for_number_of_names();

        lookup_list_of_names(gender, number);

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
        option = prompt_for_option(8);

        execute_option(c, option);  

    } while (option != 8);

    std::cout << "Do you want to save your work to characters.txt? This will overwrite the file's existing information. Enter y/n: ";
    std::string input;
    std::cin >> input;

    if (input == "y" || input == "yes") {
        std::ofstream of_file;
        of_file.open("characters.txt");
        c.write_catalog_to_file(of_file);

        std::cout << "Your work has been saved. Exiting program..." << std::endl;
    } else {
        std::cout << "Your work was not saved. Exiting program..." << std::endl;
    }
}