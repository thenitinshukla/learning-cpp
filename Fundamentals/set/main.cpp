#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<char> s1 = {'B', 'B', 'C', 'C', 'A'};
    
    s1.insert('D');
    s1.erase('C');
    
    if (s1.find('C') == s1.end()){
        cout << "Could not find C" << endl;
    } else {
        cout << "Find C" << endl; 
    }
    
    for (auto i = s1.begin(); i !=s1.end(); i++)
    {
        cout << *i << endl;
    }
}
