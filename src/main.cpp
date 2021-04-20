#include "parsing.hpp"
#include "entities.hpp"

int main() {
    Component *tree = new Composite;

    const char* xmlFile = "test.xml";
    foo(xmlFile, tree);
    ClientCode(tree);
    delete tree;
return 0;
}