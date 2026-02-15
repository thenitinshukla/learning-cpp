/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   !!                                                                   !!
   !!                   Template, Swap C++ code                         !!
   !!          Written by Nitin Shukla - CINECA -2020 Bologna           !!
   !!                                                                   !!
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */

#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
};

template <typename T>
void myPrint(T& a, T& b)
{
  cout << "a = " << a  << "; " << "a = " << b << "; " << endl;
}

int main()
{
  int a = 2, b = 10; 
  cout << "Before passing data to function template.\n";
  myPrint(a,b);
  Swap(a,b);
  cout << "\nAfter passing data to function template.\n";
  myPrint(a,b);
  
  return 0;
}
