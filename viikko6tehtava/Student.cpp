#include "Student.h"

Student::Student(string name, int age)
{
    Name = name;
    Age = age;
}

void Student::setAge(int age)
{
    Age = age;
}

void Student::setName(string name)
{
    Name = name;
}

string Student::getName() const
{
    return Name;
}

int Student::getAge() const
{
    return Age;
}

void Student::printStudentInfo() const
{
    cout << "Student " << Name << " Age " << Age << endl;
}
