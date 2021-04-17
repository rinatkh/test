#include "entities.hpp"

class Component {

protected:
    Component *parent_;

public:
    virtual ~Component() {}
    void SetParent(Component *parent) {
        this->parent_ = parent;
    }
    Component *GetParent() const {
        return this->parent_;
    }
    virtual void Add(Component *component) {}
    virtual void Remove(Component *component) {}

    virtual bool IsComposite() const {
        return false;
    }

    virtual std::string Operation() const = 0;
};

class Leaf : public Component {
public:
    std::string Operation() const override {
        return "Leaf";
    }

    void changeSurname(std::string surname) {
        this->surname_ = surname;
    }

    void changeName(std::string name) {
        this->name_ = name;
    }

    void changeMidleName(std::string midleName) {
        this->midleName_ = midleName;
    }

    void changeFunction(std::string function) {
        this->function_ = function;
    }

    void changeSalary(int salary) {
        this->salary_ = salary;
    }

    std::string getSurname() {
        return this->surname_;
    }

    std::string getName() {
        return this->name_;
    }

    std::string getMidleName() {
        return this->midleName_;
    }

    std::string getFunction_() {
        return this->function_;
    }

    int getSalary() {
        return salary_;
    }

private :
    std::string surname_;
    std::string name_;
    std::string midleName_;
    std::string function_;
    int salary_;

};

class Composite : public Component {

protected:
    std::list<Component *> children_;

public:

    void Add(Component *component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }

    void Remove(Component *component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }

    bool IsComposite() const override {
        return true;
    }

    std::string Operation() const override {
        std::string result;
        for (const Component *c : children_) {
            if (c == children_.back()) {
                result += c->Operation();
            } else {
                result += c->Operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }

    std::string getName () {
        return this->name;
    }
private:
    std::string name;
    int number;
    double midleSalary;

};

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
