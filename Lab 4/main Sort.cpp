#include "Sort.h"
int main() {

    Sort list1(10, 1, 100);
    cout << "Original list 1: ";
    list1.Print();

    Sort list2{ 5, 2, 9, 1, 7 };
    cout << "Original list 2: ";
    list2.Print();

    vector<int> vec = { 3, 8, 4, 6, 2 };
    Sort list3(vec, 3);
    cout << "Original list 3: ";
    list3.Print();

    Sort list4(6, 20, 40, 10, 30, 5, 15);
    cout << "Original list 4: ";
    list4.Print();

    Sort list5("10,40,100,5,70");
    cout << "Original list 5: ";
    list5.Print();


    list1.InsertSort(true);
    list2.QuickSort(true);
    list3.BubbleSort(true);
    list4.InsertSort(true);
    list5.QuickSort(true);

    cout << "Sorted list 1: ";
    list1.Print();
    cout << "Sorted list 2: ";
    list2.Print();
    cout << "Sorted list 3: ";
    list3.Print();
    cout << "Sorted list 4: ";
    list4.Print();
    cout << "Sorted list 5: ";
    list5.Print();

    return 0;
}