#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
class Sort
{
  
    vector<int> elements;
public:
    
    Sort();
    Sort(int n, int x, int y);
    Sort(initializer_list<int> initList);
    Sort(const std::vector<int>& vec, int numElements);
    Sort(const std::string& str);
    Sort(int numArgs, ...);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
private:
    void quickSort(int low, int high, bool ascendent);
    int partition(int low, int high, bool ascendent);
};
