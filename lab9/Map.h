#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <strings.h>

template <typename T, typename V> class Map 
{
private:
    struct KeyValue {
        T key;
        V value;
    };
    static constexpr int max_size = 100;
    int size;
    KeyValue list[max_size] = { 0,0 };

public:
    Map() : size(0) {}

    void Set(const T& key, const V& value) {
        for (int i = 0; i < size; ++i) {
            if (list[i].key == key) {
                list[i].value = value;
                return;
            }
        }
        if (size < max_size) {
            list[size].key = key;
            list[size].value = value;
            size++;
            return;
        }
        throw std::out_of_range("Map full");
    }

    bool Get(const T& key, V& value) const {
        for (int i = 0; i < size; ++i)
            if (list[i].key == key) {
                value = list[i].value;
                return true;
            }
        return false;
    }

    int Count() const { return size; }

    void Clear() {
        for (int i = 0; i < size; ++i) {
            list[i].key = (T)NULL;
            list[i].value = (V)NULL;
        }
        size = 0;
    }

    bool Delete(const T& key) {
        bool found = false;
        int index_of_the_key = 0;
        for (int i = 0; i < size; ++i) {
            if (list[i].key == key) {
                found = true;
                index_of_the_key = i;
                break;
            }
        }
        if (!found)
            return false;

        for (int j = index_of_the_key + 1; j < size; ++j) {
            list[j - 1].key = list[j].key;
            list[j - 1].value = list[j].value;
        }
        size--;
        return true;
    }

    bool Includes(const Map<T, V>& map) const {
        for (int i = 0; i < map.size; ++i) {
            bool found = false;
            for (int j = 0; j < size; ++j)
                if (map.list[i].key == list[j].key) {
                    found = true;
                    break;
                }
            if (!found)
                return false;
        }
        return true;
    }

    V& operator[](const T& key) {
        for (int i = 0; i < size; ++i) {
            if (list[i].key == key) {
                return list[i].value;
            }
        }
        if (size < max_size) {
            list[size].key = key;
            return list[size++].value;
        }
        throw std::out_of_range("Map full");
    }
    struct KeyValueIndex {
        T key;
        V value;
        int index;
    };
    class Iterator {
    private:
        Map<T, V>& map;
        int index;

    public:
        Iterator(Map<T, V>& m, int i) : map(m), index(i) {}
        void operator++() { ++index; }
        bool operator!=(const Iterator& other) { return index != other.index; }
        KeyValueIndex operator*() const {
            return { map.list[index].key, map.list[index].value, index };
        }
    };
    Iterator begin() { return Iterator(*this, 0); }
    Iterator end() { return Iterator(*this, size); }
};