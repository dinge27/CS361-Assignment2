#ifndef DISPLAY_H
#define DISPLAY_H

void print_options();

int prompt_for_option(int num_options);

std::string prompt_for_character_appearance();

std::string prompt_for_character_description();

std::string prompt_for_character_info(std::string detail);

std::string prompt_for_name();

std::string prompt_for_gender();

std::string prompt_for_number_of_names();

#endif