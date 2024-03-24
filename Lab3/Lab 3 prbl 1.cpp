#include "Math.h"
#include <iostream>
#include <cstring>
#include <cstdarg>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int Math::Add(int a, int b)
{
    return a + b;
}
int Math::Add(int a, int b, int c)
{
    return a + b + c;
}
int Math::Add(double a, double b)
{
    return static_cast<int>(a + b);
}
int Math::Add(double a, double b, double c) {
    return static_cast<int>(a + b + c);
}
int Math::Mul(int a, int b) {
    return a * b;
}
int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}
int Math::Mul(double a, double b) {
    return static_cast<int>(a * b);
}
int Math::Mul(double a, double b, double c) 
{
    return static_cast<int>(a * b * c);
}
int Math::Add(int count, ...)// count arata numarul de parametrii care urmeaza
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);
    va_end(args);
    return sum;

}
char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;
    int a= atoi(s1);
    int b= atoi(s2);
    a += b;
    int aux = a, nr =0;
    while (aux) 
    {
        nr++;
        aux=aux/10;
    }
    char* rez = new char[nr+1];
    _itoa_s(a, rez, nr + 1, 10);
    return rez;

}