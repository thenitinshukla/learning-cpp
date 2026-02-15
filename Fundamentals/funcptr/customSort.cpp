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

void customSort( vector <int>& numbersVector, bool(*compareFuncPtr)(int, int) )
{
    for( int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for( int currentIndex = startIndex+1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if( compareFuncPtr( numbersVector[currentIndex], numbersVector[bestIndex]))
            {
                bestIndex = currentIndex;
            }
        }
        swap(numbersVector[startIndex], numbersVector[bestIndex]);
    }
}

void display(vector<int>& numbersVector)
{
    for( int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        cout << numbersVector[startIndex] << " ";
    }
}


int main()
{
    vector<int> numbersVector = {2,3,4,5,6};
    bool(*funcPtr)(int, int) = ascendingCompare;
    customSort(numbersVector, funcPtr);
    cout << "Sorted in ascending order: ";
    display(numbersVector);
    cout << endl;

    bool(*funcPtrd)(int, int) = descendingCompare;
    customSort(numbersVector, funcPtrd);
    cout << "Sorted in descending order: ";
    display(numbersVector);


    return 0;
}
