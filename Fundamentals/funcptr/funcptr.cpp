// Functions pointers is being used in order to pass function as an argument to functions. Optimize the code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ascendingCompare( int a, int b )
{
    return a < b;
}

bool descendingCompare( int a, int b )
{
    return a > b;
}

int swapy(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return b;
}


void sortAscending(vector<int>& numbersVector)
{
    for( int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for( int currentIndex = startIndex+1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if( ascendingCompare( numbersVector[currentIndex], numbersVector[bestIndex]))
            {
                bestIndex = currentIndex;
            }
            swap(numbersVector[startIndex], numbersVector[bestIndex]);
        }
    }
}


void sortDescending(vector<int>& numbersVector)
{
    for( int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for(  int currentIndex = startIndex+1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if( descendingCompare( numbersVector[currentIndex], numbersVector[bestIndex]))
            {
                bestIndex = currentIndex;
            }
        }
        swap(numbersVector[startIndex], numbersVector[bestIndex]);
    }
}


int main()
{
    vector<int> numbersVector = {2,3,4,5,6};
    sortAscending(numbersVector);
    cout << "Sorted in ascending order: ";
    for( int i = 0; i < numbersVector.size(); i++)
    {
        cout << numbersVector[i] << " ";
    }
    cout << endl;
    sortDescending(numbersVector);
    cout << "Sorted in descending order: ";
    for( int i = 0; i < numbersVector.size(); i++)
    {
        cout << numbersVector[i] << " ";
    }

    return 0;
}
