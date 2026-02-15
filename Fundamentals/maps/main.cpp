// Online C++ compiler to run C++ program online

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, int> mp = {
        {'T', 7},
        {'S', 8},
        {'a', 4},
    };
    mp['u'] = 9; 
    pair<char, int>p1('j', 5);
    mp.insert(p1);
    
    for (map<char, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
        cout << "Keys :=> " ;
        cout << itr->first << endl;
        cout << "Values :=> " ;
        cout << (*itr).second << endl;
    }
}
