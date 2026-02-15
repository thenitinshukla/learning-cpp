/* Find Maximum Number and Minimum Number of Entries
   @N.Shukla, Bologna, Italy 
*/

#include <iostream>
using namespace std;

template <class T>
class FindMaxMin
{
    private:
        T *array;
        T size;
    public:
        FindMaxMin( T *array, T size); 
        T getMin(T *array, T size);
        T getMax(T *array, T size);
};

template <class T>
FindMaxMin<T>::FindMaxMin( T *array, T size)
{
    this->array = array;
    this->size = size;
}

template <class T>
T FindMaxMin<T>::getMin(T *array, T size)
{
    T min= array[0]; 
    for (int i = 1; i < size; i++)
    {
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

template <class T>
T FindMaxMin<T>::getMax(T *array, T size)
{
    T max= array[0]; 
    for (int i = 1; i < size; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

int main()
{
    int size; 
    cout << "Enter the array size" << endl;
    cin >> size;
    cout << "Enter the elements" << endl;
    int a[size];
    for (int i = 0; i < size; i++)
        cin >> a[i];
    
    for (int i = 0; i < size; i++)
    {
        cout << "Array " << i << ": ";
        cout << a[i] << " " << endl;
    }

    FindMaxMin<int> FindMaxMinArray(a, size);
    cout << "Program to determine maximum and minimum number in Array." << endl << endl;
    cout << "The largest value is: " << FindMaxMinArray.getMax(a, size) << endl;
    cout << "The minimum value is: " << FindMaxMinArray.getMin(a, size) << endl;
    
    return 0;
}