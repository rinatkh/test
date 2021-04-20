
#include "parsing.hpp"

void pars(const std::string &fileXml, Component *tree) {
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
        std::shared_ptr<Component> branch = std::make_shared<Composite>(nameDepartment, 0, 0);


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


                for (rapidxml::xml_node<> *student_name_node = person_node->first_node(
                        "surname"); student_name_node; student_name_node = student_name_node->next_sibling()) {
                    surname = static_cast<char *>(student_name_node->value());
                    break;
                }
                for (rapidxml::xml_node<> *student_name_node = person_node->first_node(
                        "name"); student_name_node; student_name_node = student_name_node->next_sibling()) {
                    name = static_cast<char *>(student_name_node->value());
                    break;
                }
                for (rapidxml::xml_node<> *student_name_node = person_node->first_node(
                        "middleName"); student_name_node; student_name_node = student_name_node->next_sibling()) {
                    middleName = static_cast<char *>(student_name_node->value());
                    break;
                }
                for (rapidxml::xml_node<> *student_name_node = person_node->first_node(
                        "function"); student_name_node; student_name_node = student_name_node->next_sibling()) {
                    function = static_cast<char *>(student_name_node->value());
                    break;
                }
                for (rapidxml::xml_node<> *student_name_node = person_node->first_node(
                        "salary"); student_name_node; student_name_node = student_name_node->next_sibling()) {
                    salary = std::stoi(student_name_node->value());
                    break;
                }

                std::shared_ptr<Component> leaf = std::make_shared<Leaf>(surname, name, middleName, function, salary);
                branch->Add(leaf);
                number++;
                summ += salary;
            }
            branch->changeNumberDepartment(number);
            branch->changeMidleSalaryOfDepartment(summ / number);
            tree->Add(branch);
        }
    }
}


void CreateXml(const std::string &XMLFileName, Component *tree) {
    std::setlocale(LC_ALL, "");
    rapidxml::xml_document<> doc;

    rapidxml::xml_node<> *root = doc.allocate_node(rapidxml::node_pi,
                                                   doc.allocate_string("xml version=\"1.0\" encoding=\"UTF-8\""));
    doc.append_node(root);

    rapidxml::xml_node<> *node = doc.allocate_node(rapidxml::node_element, "departments", nullptr);
    doc.append_node(node);

    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        rapidxml::xml_node<> *comment = doc.allocate_node(rapidxml::node_element, "department", depart->getName().c_str());
        node->append_node(comment);


        rapidxml::xml_node<> *object = doc.allocate_node(rapidxml::node_element, "employments", nullptr);
        comment->append_node(object);
        for (const auto &leaf : branch->getChildren()) {
            auto empl = dynamic_cast<const Leaf *>(leaf.get());
            rapidxml::xml_node<> *employment = doc.allocate_node(rapidxml::node_element, "employment", nullptr);
            object->append_node(employment);

            employment->append_node(doc.allocate_node(rapidxml::node_element, "surname", empl->getSurname().c_str()));
            employment->append_node(doc.allocate_node(rapidxml::node_element, "name", empl->getName().c_str()));
            employment->append_node(doc.allocate_node(rapidxml::node_element, "middleName", empl->getMidleName().c_str()));
            employment->append_node(doc.allocate_node(rapidxml::node_element, "function", empl->getFunction_().c_str()));
            employment->append_node(doc.allocate_node(rapidxml::node_element, "salary", std::to_string(empl->getSalary()).c_str()));
        }
    }

    // Print the entire XML content
    std::string text;
    rapidxml::print(std::back_inserter(text), doc, 0);
    std::cout << text << std::endl;

    // Output DOM to file
    std::ofstream outfile(XMLFileName.c_str(), std::ios::out);
    if (outfile) {
        outfile << doc;
        outfile.close();
    }

    doc.clear();
}


