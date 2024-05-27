
#pragma once
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
class exceptie2 : public std::exception {
    virtual const char* what() const throw() {
        return "Indexul este inafara domeniului!";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T> class ArrayIterator {
private:
    int Current; 
    T** ArrPtr;  
public:
    ArrayIterator() : Current(0), ArrPtr(nullptr) {}

    ArrayIterator(T** arrPtr, int current) : ArrPtr(arrPtr), Current(current) {}

    ArrayIterator& operator++() {
        ++Current;
        return (*this);
    }
    ArrayIterator& operator--() {
        --Current;
        return (*this);
    }
    bool operator==(ArrayIterator<T>& elem) {
        return this->Current == elem.Current;
    }
    bool operator!=(ArrayIterator<T>& elem) {
        return !(this->Current == elem.Current);
    }

    T* GetElement() {
        return &(*ArrPtr[Current]); 
        
    }
};

template <class T> class Array {
private:
    T** List;    
    int Capacity; 
    int Size;     
public:
   
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() 
    {
        delete[] this->List;
        this->Size = this->Capacity = 0;
    }

    Array(int capacity)
    {
        this->Size = 0;
        this->Capacity = capacity;
        this->List = new T * [this->Capacity];
        for (int i = 0; i < this->Capacity; ++i)
            this->List[i] = nullptr;
    }

    Array(const Array<T>& otherArray) 
    {
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;
        this->List = new T * [this->Capacity];
        for (int i = 0; i < this->Size; ++i)
            this->List[i] = new T(*otherArray.List[i]);
    }

    T& operator[](int index) 
    {
        exceptie2 out_range;
        try {
            if (index < 0 || index >= this->Size)
                throw out_range;

        }
        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
        }
        return *(this->List[index]);
    }

    
    Array<T>& operator+=(const T& newElem) {
        if (this->Size >= this->Capacity) {
        
            int newCapacity = (this->Capacity == 0) ? 1 : this->Capacity * 2;

            T** newList = new T * [newCapacity];

            for (int i = 0; i < this->Size; ++i)
                newList[i] = this->List[i];

            delete[] this->List;

            this->List = newList;

            this->Capacity = newCapacity;
        }

        this->List[this->Size] = new T(newElem);
        this->Size++;
        return (*this);
    }
    const Array<T>& Insert(int index, const T& newElem) {
        exceptie2 out_range;
        try {
            if (index < 0 || index >= this->Size)
                throw out_range;
            if (this->Size >= this->Capacity) {
                int newCapacity = (this->Capacity == 0) ? 1 : this->Capacity * 2;
                T** newList = new T * [newCapacity];

                for (int i = 0; i < this->Size; ++i) {
                    newList[i] = this->List[i];
                }

                delete[] this->List;
                this->List = newList;
                this->Capacity = newCapacity;

                for (int i = this->Size; i > index; --i)
                    this->List[i] = this->List[i - 1];

                this->List[index] = new T(newElem);
                this->Size++;
            }
        }
        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
        }
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        exceptie2 out_range;
        try {
            if (index < 0 || index >= this->Size)
                throw out_range;
            int newSize = Size + otherArray.Size;
            if (newSize >= Capacity) {

                int newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
                while (newSize >= newCapacity) {
                    newCapacity *= 2;
                }
                T** newList = new T * [newCapacity];
                int i = 0;
                for (; i < index; ++i) {
                    newList[i] = List[i];
                }
                for (int j = 0; j < otherArray.Size; ++i, ++j) {
                    newList[i] = new T(*otherArray.List[j]);
                }
                for (; i < Size + otherArray.Size; ++i) {
                    newList[i] = List[i - otherArray.Size];
                }
                delete[] List;
                List = newList;
                Capacity = newCapacity;
            }
            else {
                for (int i = Size - 1; i >= index; --i) {
                    List[i + otherArray.Size] = List[i];
                }
                for (int i = 0; i < otherArray.Size; ++i) {
                    List[index + i] = new T(*otherArray.List[i]);
                }
            }
            Size = newSize;
        }
        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
        }
        return *this;
    }
    const Array<T>& Delete(int index) {
        exceptie2 out_range;
        try {
            if (index < 0 || index >= this->Size)
                throw out_range;
            for (int i = index + 1; i < this->Size; ++i)
                this->List[i - 1] = this->List[i];
            this->Size--;

        }
        catch (std::exception& e) {
            std::cout << "Exceptie: " << e.what() << '\n';
        }
        return *this;
    }

    bool operator==(const Array<T>& otherArray) const {
        if (this->Size != otherArray.Size || this->Capacity != otherArray.Capacity)
            return false;

        for (int i = 0; i < this->Size; ++i)
            if (*this->List[i] != *otherArray.List[i])
                return false;

        return true;
    }
    void Sort() {
        for (int i = 0; i < this->Size - 1; ++i)
            for (int j = i + 1; j < this->Size; ++j)
                if (*this->List[i] > *this->List[j]) {
                    T* aux = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                }
    }
    void Sort(int (*compare)(const T&, const T&)) {
        for (int i = 0; i < this->Size - 1; ++i) {
            for (int j = i + 1; j < this->Size; ++j) {
                if (compare(*this->List[i], *this->List[j]) > 0) 
                {
                    T* temp = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = temp;
                }
            }
        }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < this->Size - 1; ++i)
            for (int j = i + 1; j < this->Size; j++)
                if (comparator->CompareElements(this->List[i], this->List[j]) > 0) {
                    T* temp = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = temp;
                }
    }
    int BinarySearch(const T& elem) {
        int begin = 0;
        int end = this->Size - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (*this->List[mid] == elem) {
                return mid;
            }
            else {
                if (*this->List[mid] > elem)
                    end = mid - 1;
                else if (*this->List[mid] < elem)
                    begin = mid + 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, int (*compare)(const T&, const T&)) {
        int begin = 0;
        int end = this->Size - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (compare(*this->List[mid], elem) == 0) {
                return mid;
            }
            else {
                if (compare(*this->List[mid], elem) > 0)
                    end = mid - 1;
                else if (compare(*this->List[mid], elem) < 0)
                    begin = mid + 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {

        T* elemPtr = const_cast<T*>(&elem);
        int begin = 0;
        int end = this->Size - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (comparator->CompareElements(this->List[mid], elemPtr) == 0) {
                return mid;
            }
            else {
                if (comparator->CompareElements(this->List[mid], elemPtr) > 0)
                    end = mid - 1;
                else if (comparator->CompareElements(this->List[mid], elemPtr) < 0)
                    begin = mid + 1;
            }
        }
        return -1;
    }
    int Find(const T& elem) {
        for (int i = 0; i < this->Size; ++i)
            if (*this->List[i] == elem)
                return i;
        return -1;
    }
   
    int Find(const T& elem, int (*compare)(const T&, const T&)) {
        for (int i = 0; i < this->Size; ++i)
            if (compare(*this->List[i], elem) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator) {
        T* elemPtr = const_cast<T*>(&elem);
        for (int i = 0; i < this->Size; ++i)
            if (comparator->CompareElements(this->List[i], elemPtr) == 0)
                return i;
        return -1;
    }

    int GetSize() const { return this->Size; }
    int GetCapacity() const { return this->Capacity; }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(this->List, 0);
    }
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(this->List, this->Size);
    }
};
