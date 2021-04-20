#include "parsing.hpp"
#include "entities.hpp"

int main() {
    Component *tree = new Composite;

    const std::string & xmlFile = "test.xml";
    pars(xmlFile, tree);
    //ClientCode(tree);
    CreateXml(xmlFile, tree);
    delete tree;
return 0;
}