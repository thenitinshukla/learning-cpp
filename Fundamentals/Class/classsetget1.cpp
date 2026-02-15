#include<iostream>
#include<list>
using namespace std;

class ProgramingLang {
public:
    string Name;
    int Year;
    
    ProgramingLang(string name, int year) {
        Name = name; 
        Year = year;
    }
    
    void myPrint() {
        cout << "I like " << Name << " langauge, which is being used since " << Year << ".\n";
    }
    
};

int main()
{
    ProgramingLang p0 = ProgramingLang("Fortran", 1950);
    ProgramingLang p1 = ProgramingLang("C/Cpp", 1950);
    
    p0.myPrint();
    p1.myPrint();
    
    
    return 0;
}
