#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

class Component {
protected:
    Component *parent_;
public:
    virtual ~Component();
    void SetParent(Component *parent);
    Component *GetParent() const;
    virtual void Add(Component *component);
    virtual void Remove(Component *component);
    virtual bool IsComposite() const;
    virtual std::string Operation() const;
};

class Leaf : public Component {
public:
    std::string Operation() const override;
    void changeSurname(std::string surname);
    void changeName(std::string name);
    void changeMidleName(std::string midleName);
    void changeFunction(std::string function);
    void changeSalary(int salary);
    std::string getSurname();
    std::string getName();
    std::string getMidleName();
    std::string getFunction_();
    int getSalary();
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
    void Add(Component *component) override;
    void Remove(Component *component) override;
    bool IsComposite() const override;
    std::string Operation() const override;
    std::string getName ();
private:
    std::string name;
    int number;
    double midleSalary;
};

void ClientCode(Component *component);
void ClientCode2(Component *component1, Component *component2);