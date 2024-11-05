#include "character.h"

character::character() {}

character::character(std::string name, std::string gender, std::string age, std::string appearance, std::string description):
    name(name), gender(gender), age(age), appearance(appearance), description(description) {

}

std::string character::get_name() {
    return this->name;
}

void character::print_character_info() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Gender: " << this->gender << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Appearance: " << this->appearance << std::endl;
    std::cout << "Description: " << this->description << std::endl;
}

void character::populate_character_from_file(std::ifstream& file) {
    getline(file, this->name);
    getline(file, this->gender);
    getline(file, this->age);
    getline(file, this->appearance);
    getline(file, this->description);

    std::string temp;
    getline(file, temp);
}