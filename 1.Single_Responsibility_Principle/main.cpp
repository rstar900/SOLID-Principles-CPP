/*
According to Single responsibilty principle, 
each class does one thing and only have one reason to
change (i.e. the served functionality)
*/

#include <iostream>

class Person
{
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name(name), age(age)
    {
    }

    std::string getName() { return this->name; }

    int getAge() { return this->age; }
};

class ValidatePerson
{
    Person p;

public:
    ValidatePerson(std::string name, int age) : p(name,age)
    {
    }

    bool validateAge()
    {
        return (p.getAge() >= 18);
    }

    bool validateName()
    {
        return (p.getName().size() >= 3);
    }
};

class DisplayPerson
{
    std::string name;
    int age;
    ValidatePerson vp;

public:
    DisplayPerson(std::string name, int age) : vp(name, age)
    {
        this->age = age;
        this->name = name;
    }

    void display()
    {
        if (vp.validateAge() && vp.validateName())
        {
            std::cout << "Name: " << this->name << std::endl;
            std::cout << "Age: " << this->age << std::endl;
        }
        else
        {
            std::cout << "Invalid Person!" << std::endl;
        }    
    }
};

/*
The idea here is to have a separate class for each functionality
so for example, if we add validation and display functionality into
person class, then this class will have 3 reasons to change its source code
(change in person, validation or display class). But we want 1 reason to change.
*/

int main()
{
    DisplayPerson dp1{"RJ", 21}; // Invalid due to name
    DisplayPerson dp2{"Ritchie", 17}; // Invalid due to age
    DisplayPerson dp3{"Raj", 23}; // Valid

    dp1.display();
    std::cout << std::endl;
    dp2.display();
    std::cout << std::endl;
    dp3.display();
    std::cout << std::endl;

    return 0;
}
