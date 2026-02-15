#include <iostream>
using namespace std;

void Swap(int &num1, int &num2)
{
    int tmp = num1; 
    num1 =  num2;
    num2 = tmp;
}

void display(int num1, int num2)
{
  cout << "num1 = " << num1  << "; " << "num2 = " << num2 << "; " << endl;
}


int main() {
    
    int a, b; 
    cout << "Enter two numbers.\n";
    cin >> a >> b; 
    cout << "Before passing data to function template.\n";
    
    display(a,b);
    Swap(a,b);
    
    cout << "\nAfter passing data to function template.\n";
    display(a,b);

    return 0;
}
