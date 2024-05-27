
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void sortVector(vector<T>& x)
{
    int n = x.size();
    for (int i = 0; i < n - 1; ++i) //am corectat cu < in loc de <=
    { 
        for (int j = 0; j < n - 1 - i; ++j) 
        {
            if (x[j] > x[j + 1])// am corectat cu > in loc de <
            {
                swap(x[j], x[j + 1]); //am corectat x[j+1] in loc de x[i+1]
            }
        }
    }
}
template <typename T>
void printVector(const vector<T>& x)
{
    int n=x.size(); //am adaugat size-ul
    for (const T& elem : x)
        cout << elem << " "; //am corectat sa afiseze cu spatii
}

int main()
{
    vector<int> x = { 10,13,1,4,23 };
    printVector(x);
    cout << endl;
    sortVector(x);
    printVector(x);
}

