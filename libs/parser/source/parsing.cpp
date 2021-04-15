#include <iostream>
#include <vector>
#include <fstream>

#include "parsing.hpp"

void foo(const char *fileXml)
{
    std::cout << "\nParsing my students data (sample.xml)....." << std::endl;

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node = NULL;

    // Read the sample.xml file
    std::ifstream theFile (fileXml);
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer
    doc.parse<0>(&buffer[0]);

    // Find out the root node
    root_node = doc.first_node("departments");

    // Iterate over the student nodes
    for (rapidxml::xml_node<> * department_node = root_node->first_node("department"); department_node; department_node = department_node->next_sibling()) {
        std::cout << "\nDepartament =   " << department_node->first_attribute("name=")->value();
        std::cout << std::endl;



        for (rapidxml::xml_node<> * employment_node = department_node->first_node("employment"); employment_node; employment_node = employment_node->next_sibling()) {


            for (rapidxml::xml_node<> *person_node = employment_node->first_node(
                    "employment"); person_node; person_node = person_node->next_sibling()) {
                std::cout << "\nEmployment =   " << person_node->first_attribute("surname")->value();
                std::cout << "\nEmployment =   " << person_node->first_attribute("name")->value();
                std::cout << "\nEmployment =   " << person_node->first_attribute("middleName")->value();
                std::cout << "\nEmployment =   " << person_node->first_attribute("function")->value();
                std::cout << "\nEmployment =   " << person_node->first_attribute("salary")->value();

                std::cout << std::endl;

            }
            std::cout << std::endl;
        }
    }
}
