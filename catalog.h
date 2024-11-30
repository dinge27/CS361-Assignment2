#ifndef CATALOG_H
#define CATALOG_H

#include "character.h"
#include <iostream> 
#include <vector>
#include <fstream>

class catalog {
private:
    int num_characters;
    std::vector<character> characters;

public:
    /*
     * This function populates the vector from the given file
     */
    void populate_catalog_from_file(std::ifstream& file);

    void write_catalog_to_file(std::ofstream& file);

    /*
     * This function displays all characters in the catalog as a list
     */
    void display_all_characters();

    /*
     * This function prints the details of the character with the given name
     */
    void print_searched_character(std::string name);

    /*
     * This function adds a character to the vector of characters
     */
    void add_character(std::string name, std::string gender, std::string age, std::string appearance, std::string description);

    void delete_character(std::string name);

    void sort_characters();
};

#endif