// Online C++ compiler to run C++ program online
#include <iostream>
using std::string;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
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
        void AskForPromotion() {
            if(Age>30)
                std::cout << Name << " got promoted! " << std::endl;
            else
                std::cout << Name << " Undefined! " << std::endl;
        }
};


int main() 
{
    Employee p1 = Employee("Nitin", "CINECA", 38); 
    Employee p2 = Employee("Ni", "NECA", 25); 
    
    p1.AskForPromotion();
    p2.AskForPromotion();
   
  
    return 0;
    
}