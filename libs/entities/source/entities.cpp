#include "entities.hpp"


void Component::SetParent(Component *parent) {
    this->parent_ = parent;
}
Component * Component::GetParent() const {
    return this->parent_;
}
bool Component::IsComposite() const {
    return false;
}

std::string Leaf::Operation() const {

    return  "\n\t" + this->getSurname() + "\n" +
            "\t" + this->getName() + "\n" +
            "\t" + this->getMidleName() + "\n" +
            "\t" + this->getFunction_() + "\n" +
            "\t" + std::to_string(this->getSalary()) + "\n";

}

Leaf::Leaf (std::string surname, std::string name, std::string midleName, std::string function, int salary)
    : surname_(surname)
    , name_(name)
    , midleName_(midleName)
    , function_(function)
    , salary_(salary) {};
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
int Leaf::getSalary() const{
    return salary_;
}
void Leaf::changeSurname(std::string surname) {
    this->surname_ = surname;
}

Composite::Composite (std::string name, int number, double midle)
    : name_(name)
    , number_(number)
    , midleSalary_(midle) {}
void Composite::Add(Component *component) {
    this->children_.push_back(component);
    component->Component::SetParent(this);
}
void Composite::Remove(Component *component) {
    children_.remove(component);
    component->Component::SetParent(nullptr);
}
void Composite::RemoveAll() {
    delete this;
}
bool Composite::IsComposite() const {
    return true;
}

std::string Composite::Operation() const{
    std::string result;
    for (const Component *c : children_) {

        if (c == children_.back()) {
            result += c->Operation();
        } else {
            result += c->Operation();
        }
    }
    return  "Департамент " + this->getName() + "\n" +
            "Количество сотрудников = " +  std::to_string(this->getNumber()) + "\n" +
            "Средняя зарплата =  " + std::to_string(this->getMiddleSalary()) + "\n\nСотрудники :" +  result;


}
std::string Composite::getName () const{
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
void Composite::changeMidleSalaryOfDepartment(double midleSalary){
    this->midleSalary_ = midleSalary;
}

void ClientCode(Component *component) {
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}
void ClientCode2(Component *component1, Component *component2) {
    // ...
    if (component1->IsComposite()) {
        component1->Add(component2);
    }
    std::cout << "RESULT: " << component1->Operation();
    // ...
}
