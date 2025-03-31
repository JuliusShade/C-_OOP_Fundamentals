#include <iostream>  // Include the standard input/output library

using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    int Age;
protected:
    string Name;
    string Company;
public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        if (age > 18) {
        Age = age;
        } else {
            cout <<"This person is not old enough to work" << endl;
        }
    }
    int getAge() {
        return Age;
    }
    void IntroduceYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry no promotion for you!" << endl;
    }
    virtual void Work() {
        cout << Name << " is working on " << Company << endl;
    }
};

class Developer:public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string FavProgrammingLanguage)
        : Employee(name, company, age) 
    {
        this->FavProgrammingLanguage = FavProgrammingLanguage;
    }
    void FixBug() {
        cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work() {
        cout << Name << " is writing " << FavProgrammingLanguage << " code for " << Company << endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;
    Teacher(string name, string company, int age, string Subject)
        :Employee(name, company, age) {
        this->Subject = Subject;
    }
    void Work() {
        cout << Name << " is teaching " << Subject << " classes for " << Company << endl;
    }
    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
};

int main() {
    Developer developer1 = Developer("Julius", "Meta", 25, "C++");
    Teacher teacher1 = Teacher("Jack", "Cool School", 35, "Math");
    Employee* employee1 = &developer1;
    Employee* employee2 = &teacher1;
    employee1->Work();
    employee2->Work();
}