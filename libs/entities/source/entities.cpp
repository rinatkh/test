#include "entities.hpp"


void Component::SetParent(Component *parent) {
    this->parent_ = parent;
}

Component *Component::GetParent() const {
    return this->parent_;
}

bool Component::IsComposite() const {
    return false;
}

std::string Leaf::Operation() const {

    return "\n\t" + this->getSurname() + "\n" +
           "\t" + this->getName() + "\n" +
           "\t" + this->getMidleName() + "\n" +
           "\t" + this->getFunction_() + "\n" +
           "\t" + std::to_string(this->getSalary()) + "\n";

}

Leaf::Leaf(std::string surname, std::string name, std::string midleName, std::string function, int salary)
        : surname_(surname), name_(name), midleName_(midleName), function_(function), salary_(salary) {};

void Leaf::changeMidleName(std::string midleName) {
    this->midleName_ = midleName;
}

void Leaf::changeFunction(std::string function) {
    this->function_ = function;
}

void Leaf::changeSalary(int salary) {
    this->salary_ = salary;
}

void Leaf::changeName(std::string name) {
    this->name_ = name;
}

std::string Leaf::getSurname() const {
    return this->surname_;
}

std::string Leaf::getName() const {
    return this->name_;
}

std::string Leaf::getMidleName() const {
    return this->midleName_;
}

std::string Leaf::getFunction_() const {
    return this->function_;
}

int Leaf::getSalary() const {
    return salary_;
}

void Leaf::changeSurname(std::string surname) {
    this->surname_ = surname;
}

Composite::Composite(std::string name, int number, double midle)
        : name_(name), number_(number), midleSalary_(midle) {}

void Composite::Add(std::shared_ptr<Component> component) {
    children_.push_back(component);
    component->Component::SetParent(this);
}

void Composite::Remove(std::shared_ptr<Component> component) {
    children_.remove(component);
    component->Component::SetParent(nullptr);
}

void Composite::RemoveAll() {
    delete this;
}

bool Composite::IsComposite() const {
    return true;
}

int Composite::getSize() {
    return children_.size();
}


std::string Composite::Operation() const {
    std::string result;
    for (const std::shared_ptr<Component> c : children_) {

        if (c == children_.back()) {
            result += c->Operation();
        } else {
            result += c->Operation();
        }
    }
    return "\nДепартамент " + this->getName() + "\n" +
           "Количество сотрудников = " + std::to_string(this->getNumber()) + "\n" +
           "Средняя зарплата =  " + std::to_string(this->getMiddleSalary()) + "\n\nСотрудники :" + result;


}

std::string Composite::getName() const {
    return this->name_;
}

int Composite::getNumber() const {
    return this->number_;
}

double Composite::getMiddleSalary() const {
    return this->midleSalary_;
}

void Composite::changeNameDepartment(std::string name) {
    this->name_ = name;
}

void Composite::changeNumberDepartment(int number) {
    this->number_ = number;
}

void Composite::changeMidleSalaryOfDepartment(double midleSalary) {
    this->midleSalary_ = midleSalary;
}

const std::list<std::shared_ptr<Component>> &Composite::getChildren() const {
    return children_;
}

void printTree(Component *component) {
    // ...
    std::cout << "Parsing the file txt.xml " << component->Operation();
    // ...
}


void changeNameDepartment(Component *tree) {
    int commandchange = 0;
    int d = 1;
    std::cout << "Which of these? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t" << d++ << ": " << depart->getName() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nEnter new name department №" << commandchange << std::endl;
    std::string newDepartment;
    std::cin >> newDepartment;

    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<Composite *>(branch.get());
        for (int i = 0; i != commandchange; i++) {
            depart->changeNameDepartment(newDepartment);
        }
    }
}

void removeNDepartment(Component *tree) {
    int commandchange = 0;
    int d = 1;
    std::cout << "Which of these? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t" << d++ << ": " << depart->getName() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nRemove department №" << commandchange << std::endl;
    int k = 0;

    tree->Remove(*std::next(tree->getChildren().begin(), commandchange - 1));

}

void changeSurnameEmployee(Component *tree) {
    int commandchange = 0;
    int l = 1;
    std::cout << "Which of these department? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t " << l++ << ": "<< depart->getName() << std::endl;

    }
    l = 1;
    std::cin >> commandchange;
    std::cout << "\nWhich of these employees" << std::endl;
    auto branch = dynamic_cast<Composite *>(std::next(tree->getChildren().begin(), commandchange - 1)->get());
    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<const Leaf *>(leaf.get());
        std::cout << "\t\t" << l++ << ": " << empl->getSurname() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nEnter new function employee №" << commandchange << std::endl;

    std::string newEmployee;
    std::cin >> newEmployee;

    auto leaf = dynamic_cast<Leaf *>(std::next(branch->getChildren().begin(), commandchange - 1)->get());
    leaf->changeSurname(newEmployee);
}

void changeNameEmployee(Component *tree) {
    int commandchange = 0;
    int l = 1;
    std::cout << "Which of these department? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t " << l++ << ": "<< depart->getName() << std::endl;

    }
    l = 1;
    std::cin >> commandchange;
    std::cout << "\nWhich of these employees" << std::endl;
    auto branch = dynamic_cast<Composite *>(std::next(tree->getChildren().begin(), commandchange - 1)->get());
    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<const Leaf *>(leaf.get());
        std::cout << "\t\t" << l++ << ": " << empl->getSurname() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nEnter new function employee №" << commandchange << std::endl;

    std::string newEmployee;
    std::cin >> newEmployee;

    auto leaf = dynamic_cast<Leaf *>(std::next(branch->getChildren().begin(), commandchange - 1)->get());
    leaf->changeName(newEmployee);
}

void changeMiddleNameEmployee(Component *tree) {
    int commandchange = 0;
    int l = 1;
    std::cout << "Which of these department? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t " << l++ << ": "<< depart->getName() << std::endl;

    }
    l = 1;
    std::cin >> commandchange;
    std::cout << "\nWhich of these employees" << std::endl;
    auto branch = dynamic_cast<Composite *>(std::next(tree->getChildren().begin(), commandchange - 1)->get());
    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<const Leaf *>(leaf.get());
        std::cout << "\t\t" << l++ << ": " << empl->getSurname() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nEnter new function employee №" << commandchange << std::endl;

    std::string newEmployee;
    std::cin >> newEmployee;

    auto leaf = dynamic_cast<Leaf *>(std::next(branch->getChildren().begin(), commandchange - 1)->get());
    leaf->changeMidleName(newEmployee);
}

void changeFunctionEmployee(Component *tree) {
    int commandchange = 0;
    int l = 1;
    std::cout << "Which of these department? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t " << l++ << ": "<< depart->getName() << std::endl;

    }
    l = 1;
    std::cin >> commandchange;
    std::cout << "\nWhich of these employees" << std::endl;
    auto branch = dynamic_cast<Composite *>(std::next(tree->getChildren().begin(), commandchange - 1)->get());
    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<const Leaf *>(leaf.get());
        std::cout << "\t\t" << l++ << ": " << empl->getSurname() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nEnter new function employee №" << commandchange << std::endl;

    std::string newEmployee;
    std::cin >> newEmployee;

    auto leaf = dynamic_cast<Leaf *>(std::next(branch->getChildren().begin(), commandchange - 1)->get());
    leaf->changeFunction(newEmployee);


}

void changeSalaryEmployee(Component *tree) {
    int commandchange = 0;
    int l = 1;
    std::cout << "Which of these department? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t " << l++ << ": "<< depart->getName() << std::endl;

    }
    l = 1;
    std::cin >> commandchange;
    std::cout << "\nWhich of these employees" << std::endl;
    auto branch = dynamic_cast<Composite *>(std::next(tree->getChildren().begin(), commandchange - 1)->get());
    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<const Leaf *>(leaf.get());
        std::cout << "\t\t" << l++ << ": " << empl->getSurname() << std::endl;
    }
    std::cin >> commandchange;
    std::cout << "\nEnter new salary employee №" << commandchange << std::endl;

    int newEmployee = 0;
    std::cin >> newEmployee;

    auto leaf = dynamic_cast<Leaf *>(std::next(branch->getChildren().begin(), commandchange - 1)->get());
    leaf->changeSalary(newEmployee);

    int summ = 0;
    int number = 0;

    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<Leaf *>(leaf.get());
        number++;
        int salary = empl->getSalary();
        summ += salary;
    }

    branch->changeMidleSalaryOfDepartment(summ / number);
}


void removingEmployee(Component *tree) {

    int commandchange = 0;
    int l = 1;
    std::cout << "Which of these employees? " << std::endl;
    for (const auto &branch : tree->getChildren()) {
        auto depart = dynamic_cast<const Composite *>(branch.get());
        std::cout << "\t " << l++ << ": "<< depart->getName() << std::endl;

    }
    l = 1;
    std::cin >> commandchange;
    std::cout << "\nEnter number of employee to remove" << commandchange << std::endl;
    auto branch = dynamic_cast<Composite *>(std::next(tree->getChildren().begin(), commandchange - 1)->get());
    for (const auto &leaf : branch->getChildren()) {
        auto empl = dynamic_cast<const Leaf *>(leaf.get());
        std::cout << "\t\t" << l++ << ": " << empl->getSurname() << std::endl;
    }
    int removed_empl = 0;
    std::cin >> removed_empl;

    branch->Remove(*std::next(branch->getChildren().begin(), removed_empl - 1));
}