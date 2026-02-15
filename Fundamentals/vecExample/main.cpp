#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
    
    v.insert(v.begin(), 10);
    
     cout << "\nThis is another way" << endl;
    
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        cout << *it<< endl;
    }

 return 0; 
    
}
