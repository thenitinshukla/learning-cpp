#include <iostream>
#include <tuple>
using namespace std;

int main()
{
  tuple<int, string> stuff(10, "Apple");
  cout << get<0>(stuff) << endl;
  cout << get<1>(stuff);
  get<1>(stuff) = "Goog";
  cout << "\nnew stuff is:" << endl;
  cout << get<1>(stuff) << endl;
  
  tuple<int, char, bool, float> things;
  things = make_tuple(10, 'A', true, 12.5);
  cout << get<0>(things) << endl;
  cout << get<1>(things) << endl;
  cout << get<2>(things) << endl;
  cout << get<3>(things) << endl;
}
