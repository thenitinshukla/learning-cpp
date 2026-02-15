// Online C++ compiler to run C++ program online
#include <iostream>
using std::string;

class Employee {
    private:
        string Name;
        string Company; 
        int Age;
    public:
        void setName(string name) { //setter 
            Name = name;
        }
        string getName() { // getter
            return Name;
        }
        
        void setCompany(string company) { //setter 
            Company = company;
        }
        string getCompany() { // getter
            return Company;
        }
        
        void setAge(int age) { //setter 
            if(age>=18)
            Age = age;
        }
        int getAge() { // getter
            return Age;
        }
        
        void Intro() {
            std::cout << "Name -" << Name << std::endl;
            std::cout << "Company -" << Company << std::endl;
            std::cout << "Age -" << Age << std::endl;
        }
        
        Employee(string name, string company, int age) {
            Name = name;
            Company = company; 
            Age = age;
        }
};


int main() 
{
    Employee p1 = Employee("X", "CINECA", 27); 
    p1.Intro();

    Employee p2 = Employee("Ni", "NECA", 30); 
    p2.Intro();
    
    p1.setAge(15);
    std::cout << p1.getName() << " is " << p1.getAge() << " years old" << std::endl;
  
    return 0;
    
}
