#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>

class character {
private:
    std::string name;
    std::string gender;
    std::string age;
    std::string appearance;
    std::string description;

public:
    character();

    character(std::string name, std::string gender, std::string age, std::string appearance, std::string description);

    std::string get_name();

    void print_character_info();

    // Reads one character from a given file
    void populate_character_from_file(std::ifstream& file);
};

#endif