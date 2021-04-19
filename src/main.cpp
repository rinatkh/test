#include "parsing.hpp"
#include "entities.hpp"

int main() {
    Component *tree = new Composite;

    const char* xmlFile = "test.xml";
    foo(xmlFile, tree);
return 0;
}