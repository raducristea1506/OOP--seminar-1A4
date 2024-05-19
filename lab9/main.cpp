#include "Map.h"
int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char*> m1;
    m1.Set(1, "One");
    m1.Set(2, "Two");
    m1.Set(3, "Three");
    m1.Set(4, "Four");

    const char* value;
    if (m1.Get(2, value)) {
        std::cout << "Value at key 2: " << value << std::endl;
    }
    else {
        std::cout << "Key 2 not found" << std::endl;
    }

    std::cout << "Number of elements in m1: " << m1.Count() << std::endl;

    if (m1.Delete(3)) {
        std::cout << "Deleted key 3" << std::endl;
    }
    else {
        std::cout << "Key 3 not found" << std::endl;
    }

    m1.Clear();
    std::cout << "Cleared map m1. Count after clear: " << m1.Count() << std::endl;

    Map<int, const char*> m2;
    m2.Set(1, "One");
    m2.Set(2, "Two");
    m2.Set(4, "Four");

    if (m2.Includes(m1)) {
        std::cout << "Map m2 includes map m1" << std::endl;
    }
    else {
        std::cout << "Map m2 does not include map m1" << std::endl;
    }
    m2.Clear();
    return 0;
}