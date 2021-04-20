
#include "parsing.hpp"

void foo(const char *fileXml, Component *tree) {
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> *root_node = NULL;

    // Read the sample.xml file
    std::ifstream theFile(fileXml);
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer
    doc.parse<0>(&buffer[0]);

    // Find out the root node
    root_node = doc.first_node("departments");

    // Iterate over the student nodes
    for (rapidxml::xml_node<> *department_node = root_node->first_node(
            "department"); department_node; department_node = department_node->next_sibling()) {

        std::string nameDepartment = static_cast<char *>(department_node->first_attribute("name")->value());
        Component *branch = new Composite(nameDepartment, 0, 0);




        for (rapidxml::xml_node<> *employment_node = department_node->first_node(
                "employments"); employment_node; employment_node = employment_node->next_sibling()) {
            int salary = 0;
            int number = 0;
            double summ = 0;

            for (rapidxml::xml_node<> *person_node = employment_node->first_node(
                    "employment"); person_node; person_node = person_node->next_sibling()) {

                std::string surname;
                std::string name;
                std::string middleName;
                std::string function;


                for(rapidxml::xml_node<>* student_name_node = person_node->first_node("surname"); student_name_node; student_name_node = student_name_node->next_sibling())
                {
                    surname = static_cast<char *>(student_name_node->value());
                    break;
                }
                for(rapidxml::xml_node<>* student_name_node = person_node->first_node("name"); student_name_node; student_name_node = student_name_node->next_sibling())
                {
                    name = static_cast<char *>(student_name_node->value());
                    break;
                }
                for(rapidxml::xml_node<>* student_name_node = person_node->first_node("middleName"); student_name_node; student_name_node = student_name_node->next_sibling())
                {
                    middleName = static_cast<char *>(student_name_node->value());
                    break;
                }
                for(rapidxml::xml_node<>* student_name_node = person_node->first_node("function"); student_name_node; student_name_node = student_name_node->next_sibling())
                {
                    function = static_cast<char *>(student_name_node->value());
                    break;
                }
                for(rapidxml::xml_node<>* student_name_node = person_node->first_node("salary"); student_name_node; student_name_node = student_name_node->next_sibling())
                {
                    salary = std::stoi(student_name_node->value());
                    break;
                }

                Component *leaf = new Leaf(surname, name, middleName, function, salary);
                branch->Add(leaf);
                number++;
                summ+=salary;
            }
            branch->changeNumberDepartment(number);
            branch->changeMidleSalaryOfDepartment(summ/number);
            tree->Add(branch);
        }
    }
}
