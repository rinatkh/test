#include "parsing.h"



void foo(const char *fileXml)
{
    cout << "\nParsing my students data (sample.xml)....." << endl;

    xml_document<> doc;
    xml_node<> * root_node = NULL;

    // Read the sample.xml file
    ifstream theFile (fileXml);
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer
    doc.parse<0>(&buffer[0]);

    // Find out the root node
    root_node = doc.first_node("departments");

    // Iterate over the student nodes
    for (xml_node<> * department_node = root_node->first_node("department"); department_node; department_node = department_node->next_sibling()) {
        cout << "\nDepartament =   " << department_node->first_attribute("name=")->value();
        cout << endl;



        for (xml_node<> * employment_node = department_node->first_node("employment"); employment_node; employment_node = employment_node->next_sibling()) {


            for (xml_node<> *person_node = employment_node->first_node(
                    "employment"); person_node; person_node = person_node->next_sibling()) {
                cout << "\nEmployment =   " << person_node->first_attribute("surname")->value();
                cout << "\nEmployment =   " << person_node->first_attribute("name")->value();
                cout << "\nEmployment =   " << person_node->first_attribute("middleName")->value();
                cout << "\nEmployment =   " << person_node->first_attribute("function")->value();
                cout << "\nEmployment =   " << person_node->first_attribute("salary")->value();

                cout << endl;

            }
            cout << endl;
        }
    }
}
