// vectorul numbers il fac dinamic->> pointer
#include <iostream>
#include "NumberList.h"
using namespace std;
void NumberList::Init()
{
    this->count = 0;
}
bool NumberList::Add(int x)
{
    int size = 10;
    if(this->count>=size)
    {
        size = size * 2;
        int* neu = (int*)realloc(numbers, size * sizeof(int));
        numbers = neu;
        numbers[this->count] = x;
        this->count++;
    }
    else
    {
        this->numbers[this->count] = x;
        this->count++;
    }
}
void NumberList::Sort()
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < this->count - 1; i++)
        {
            if (this->numbers[i] > this->numbers[i + 1])
            {
                int aux = this->numbers[i];
                this->numbers[i] = this->numbers[i + 1];
                this->numbers[i + 1] = aux;
                sorted = false;
            }
        }
    }
}

void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
        printf("%d ", this->numbers[i]);
    printf("\n");
}
int main()
{
    NumberList number;
    number.Init();
   cout<< number.Add(7)<<endl;
    cout<<number.Add(5)<<endl;
    cout<<number.Add(8)<<endl;
    cout<<number.Add(10)<<endl;
    number.Sort();
    number.Print();
}
