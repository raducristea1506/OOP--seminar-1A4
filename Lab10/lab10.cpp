#include "Array.h"
template <typename T> int CompareFunction(const T& a, const T& b) {
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

template <typename T> int CompareForSearch(const T& elem1, const T& elem2) {
    if (elem1 == elem2)
        return 0;
    return (elem1 < elem2) ? -1 : 1;
}
class IntComparator : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int* elem1 = static_cast<int*>(e1);
        int* elem2 = static_cast<int*>(e2);
        if (*elem1 < *elem2)
            return -1;
        if (*elem1 > *elem2)
            return 1;
        return 0;
    }
};

class DoubleComparator : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        double* elem1 = static_cast<double*>(e1);
        double* elem2 = static_cast<double*>(e2);
        if (*elem1 > *elem2)
            return -1;
        if (*elem1 < *elem2)
            return 1;
        return 0;
    }
};

int main() {

    Array<int> intArray(10);
    intArray += 5;
    intArray += 3;
    intArray += 8;
    intArray += 2;
    intArray += 6;
    intArray += 10;
    intArray += 1;
    intArray += 9;
    intArray += 4;
    intArray += 7;
    std::cout << "Int Array elements:" << '\n';
    ArrayIterator<int> it = intArray.GetBeginIterator();
    ArrayIterator<int> end = intArray.GetEndIterator();
    for (; it != end; ++it) {
        std::cout << *it.GetElement() << " ";
    }
    std::cout << '\n';
    intArray.Sort(CompareFunction<int>);

    std::cout << "Sorted Int Array elements:" << '\n';
    for (int i = 0; i < intArray.GetSize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << '\n';


    intArray.Insert(3, 100);

    for (int i = 0; i < intArray.GetSize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << '\n';

    Array<int> intArray2;
    intArray2 += 10;
    intArray2 += 2;

    intArray.Insert(3, intArray2);

    for (int i = 0; i < intArray.GetSize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << '\n';


    int searchElement = 4;
    int searchIndex = intArray.BinarySearch(searchElement);
    if (searchIndex != -1) {
        std::cout << "Element " << searchElement << " found at index "
            << searchIndex << " using Binary Search" << '\n';
    }
    else {
        std::cout << "Element " << searchElement << " not found" << '\n';
    }

    searchElement = 6;
    searchIndex = intArray.BinarySearch(searchElement, CompareForSearch<int>);
    if (searchIndex != -1) {
        std::cout << "Element " << searchElement << " found at index "
            << searchIndex << " using Binary Search" << '\n';
    }
    else {
        std::cout << "Element " << searchElement << " not found" << '\n';
    }

    searchElement = 9;
    IntComparator intComparator;
    searchIndex = intArray.BinarySearch(searchElement, &intComparator);
    if (searchIndex != -1) {
        std::cout << "Element " << searchElement << " found at index "
            << searchIndex << " using Binary Search" << '\n';
    }
    else {
        std::cout << "Element " << searchElement << " not found" << '\n';
    }

  
    int findElement = 8;
    int findIndex = intArray.Find(findElement);
    if (findIndex != -1) {
        std::cout << "Element " << findElement << " found at index " << findIndex
            << " using Find function" << '\n';
    }
    else {
        std::cout << "Element " << findElement << " not found using Find function"
            << '\n';
    }


    findElement = 11;
    findIndex = intArray.Find(findElement, CompareForSearch<int>);
    if (findIndex != -1) {
        std::cout << "Element " << findElement << " found at index " << findIndex
            << " using Find function" << '\n';
    }
    else {
        std::cout << "Element " << findElement << " not found using Find function"
            << '\n';
    }

    findElement = 10;
    findIndex = intArray.Find(findElement, &intComparator);
    if (findIndex != -1) {
        std::cout << "Element " << findElement << " found at index " << findIndex
            << " using Find function" << '\n';
    }
    else {
        std::cout << "Element " << findElement << " not found using Find function"
            << '\n';
    }

    

    Array<int> copyArray(intArray);

    if (copyArray == intArray) {
        std::cout << "The arrays are equal." << '\n';
    }
    else {
        std::cout << "The arrays are not equal." << '\n';
    }

    Array<double> doubleArray(5);
    doubleArray += 10.0;
    doubleArray += 4.5;
    doubleArray += 7.9;
    doubleArray += 1.1;
    doubleArray += 9.8;

    std::cout << "Double Array elements: " << '\n';
    for (int i = 0; i < doubleArray.GetSize(); ++i) {
        std::cout << doubleArray[i] << ' ';
    }
    std::cout << '\n';

    DoubleComparator doubleComparator;
    doubleArray.Sort(&doubleComparator);

    std::cout << "Double Array elements sorted: " << '\n';
    for (int i = 0; i < doubleArray.GetSize(); ++i) {
        std::cout << doubleArray[i] << ' ';
    }
    std::cout << '\n';

    Array<char> charArray(5);
    charArray += 'c';
    charArray += 't';
    charArray += 'a';
    charArray += 'b';
    charArray += 'f';

    std::cout << "Char Array elements: " << '\n';
    for (int i = 0; i < charArray.GetSize(); ++i) {
        std::cout << charArray[i] << ' ';
    }
    std::cout << '\n';

    charArray.Sort();

    std::cout << "Char Array elements sorted: " << '\n';
    for (int i = 0; i < charArray.GetSize(); ++i) {
        std::cout << charArray[i] << ' ';
    }
    std::cout << '\n';
    charArray.Delete(0);

    std::cout << "Char Array elements without the first element: " << '\n';
    for (int i = 0; i < charArray.GetSize(); ++i) {
        std::cout << charArray[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Char Array capacity: " << charArray.GetCapacity() << '\n';

    return 0;
}