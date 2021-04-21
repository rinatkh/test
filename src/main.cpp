#include "parsing.hpp"
#include "entities.hpp"

int main() {
    Component *tree = new Composite;

    const std::string &xmlFile = "test.xml";
    pars(xmlFile, tree);


    enum COMMAND {
        print = 1,
        fill = 2,
        change = 3,
    };

    enum COMMANDCHANGE {
        departmentName = 1,
        removeDepartment =2,
        employeeSurname = 3,
        employeeName = 4,
        employeeMiddlename = 5,
        employeeSalary = 6,
        employeeFunction = 7,
        removeEmployee = 8,
    };


    std::cout << "enter command:\n"
                 "1: Print the list of departaments and employees\n"
                 "2: Fill data into file\n"
                 "3: Change data of the list of departaments and employees\n"

              << std::endl;
    int command = 0;
    int commandcange = 0;

    std::cout.precision(9);
    while (std::cin >> command) {
        switch (command) {
            case print: {
                printTree(tree);
                std::cout << "\nPRINTING SUCCESS" << std::endl;
                std::cout << "\nenter command:\n"
                             "1: Print the list of departaments and employees\n"
                             "2: Fill data into file\n"
                             "3: Change data of the list of departaments and employees\n"

                          << std::endl;
                break;
            }
            case fill: {
                CreateXml(xmlFile, tree);
                std::cout << "\nFILLING SUCCESS" << std::endl;
                std::cout << "\nenter command:\n"
                             "1: Print the list of departaments and employees\n"
                             "2: Fill data into file\n"
                             "3: Change data of the list of departaments and employees\n"

                          << std::endl;
                break;
            }
            case change: {
                std::cout << "\nWhat do you wanna change?" << std::endl;
                std::cout <<
                          "1: Department name\n"
                          "2: Remove department\n"
                          "3: Employee Surname \n"
                          "4: Employee name \n"
                          "5: Employee Middlename \n"
                          "6: Employee salary \n"
                          "7: Employee function \n"
                          "8: Remove Employee \n"
                          << std::endl;

                std::cin >> commandcange;

                switch (commandcange) {
                    case departmentName: {
                        changeNameDepartment(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case removeDepartment: {
                        removeNDepartment(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case employeeSurname: {
                        changeSurnameEmployee(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case employeeName: {
                        changeNameEmployee(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case employeeMiddlename: {
                        changeMiddleNameEmployee(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case employeeSalary: {
                        changeSalaryEmployee(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case employeeFunction: {
                        changeFunctionEmployee(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    case removeEmployee: {
                        removingEmployee(tree);
                        std::cout << "\nCHANGING SUCCESS" << std::endl;
                        break;
                    }
                    default:
                        std::cout << "wrong command" << std::endl;

                }
                std::cout << "\nenter command:\n"
                             "1: Print the list of departaments and employees\n"
                             "2: Fill data into file\n"
                             "3: Change data of the list of departaments and employees\n"

                          << std::endl;
                break;
            }
            default:
                std::cout << "wrong command" << std::endl;


        }
    }
    delete tree;
    return 0;
}
