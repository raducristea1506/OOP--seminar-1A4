#include "Sort.h"
Sort::Sort() { }

Sort::Sort(int n, int x, int y) 
{

	srand(time(nullptr));
	for (int i = 0; i < n; i++)
		elements.push_back(rand() % (y - x + 1) + x);
}

Sort::Sort(initializer_list<int> initList) : elements(initList) {}

Sort::Sort(const vector<int>& vec, int numElements)
{
	elements.assign(vec.begin(), vec.begin() + numElements);
}
Sort::Sort(const string& str)
{
	stringstream ss(str);
	int num;
	char comma;
	while (ss >> num >> comma)
		elements.push_back(num);
	ss >> num;
	elements.push_back(num);
}
Sort::Sort(int numArgs, ...) {
	va_list args;
	va_start(args, numArgs);
	for (int i = 0; i < numArgs; ++i)
		elements.push_back(va_arg(args, int));
	va_end(args);
}
void Sort::InsertSort(bool ascendent)
{
	int n = elements.size();
	for (int i = 1; i < n; ++i)
	{
		int key = elements[i];
		int j = i - 1;
		while (j >= 0 && ((!ascendent && elements[j] > key) || (ascendent && elements[j] < key))) 
		{
			elements[j + 1] = elements[j];
			j = j - 1;
		}
		elements[j + 1] = key;
	}
}

int Sort::partition(int low, int high, bool ascendent) 
{
	int pivot = elements[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) 
	{
		if ((!ascendent && elements[j] <= pivot) || (ascendent && elements[j] >= pivot)) 
		{
			i++;
			swap(elements[i], elements[j]);
		}
	}
	swap(elements[i + 1], elements[high]);
	return (i + 1);
}

void Sort::quickSort(int low, int high, bool ascendent)
{
	if (low < high) {
		int pi = partition(low, high, ascendent);
		quickSort(low, pi - 1, ascendent);
		quickSort(pi + 1, high, ascendent);
	}
}
void Sort::QuickSort(bool ascendent) {
	
	quickSort(0, elements.size() - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
	int n = elements.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if ((!ascendent && elements[j] > elements[j + 1]) || (ascendent && elements[j] < elements[j + 1])) {
				swap(elements[j], elements[j + 1]);
			}
		}
	}
}
void Sort::Print()
{
	for (int i = 0; i < elements.size(); ++i) {
		cout << elements[i] << " ";
	}
	cout << endl;
}
int  Sort::GetElementsCount()
{
	return elements.size();
}
int  Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < elements.size()) {
		return elements[index];
	}
	else return  -1;
}