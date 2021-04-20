#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <memory>

class Component {
protected:
    Component *parent_;
public:

    virtual ~Component() {};

    void SetParent(Component *parent);

    Component *GetParent() const;

    virtual void Add(std::shared_ptr <Component> component) {};

    virtual void Remove(std::shared_ptr <Component> component) {};

    virtual void RemoveAll() {};

    virtual int getSize() { return 0; };

    virtual bool IsComposite() const;

    virtual std::string Operation() const = 0;

    virtual void changeNameDepartment(std::string name) {};

    virtual void changeNumberDepartment(int number) {};
    virtual const std::list<std::shared_ptr<Component>> &getChildren() const = 0;

    virtual void changeMidleSalaryOfDepartment(double midleSalary) {};
};



class Leaf : public Component {
public:
    Leaf() = default;

    explicit Leaf(std::string surname, std::string name, std::string midleName, std::string function, int salary);

    std::string Operation() const override;

    void changeSurname(std::string surname);

    void changeName(std::string name);

    void changeMidleName(std::string midleName);

    void changeFunction(std::string function);

    void changeSalary(int salary);

    std::string getSurname() const;

    std::string getName() const;

    std::string getMidleName() const;

    std::string getFunction_() const;

    const std::list<std::shared_ptr<Component>> &getChildren() const override {return ownership_;}

    int getSalary() const;

private :
    std::string surname_;
    std::string name_;
    std::string midleName_;
    std::string function_;
    int salary_;


    std::list<std::shared_ptr<Component>> ownership_;
};

class Composite : public Component {
protected:
    std::list<std::shared_ptr<Component>> children_;
public:
    Composite() = default;

    int getSize() override;

    const std::list<std::shared_ptr<Component>> &getChildren() const override;

    explicit Composite(std::string name, int number, double midle);

    void Add(std::shared_ptr <Component> component) override;

    void Remove(std::shared_ptr <Component> component) override;

    void RemoveAll() override;

    bool IsComposite() const override;

    std::string Operation() const override;

    void changeNameDepartment(std::string name);

    void changeNumberDepartment(int number);

    void changeMidleSalaryOfDepartment(double midleSalary);

    std::string getName() const;

    int getNumber() const;

    double getMiddleSalary() const;

private:
    std::string name_;
    int number_;
    double midleSalary_;
};

void ClientCode(Component *component);
