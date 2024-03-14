
#include <iostream>
#include "Math.h";
#include <cstring>
using namespace std;
int Math::Add(int a, int b) 
{
    return a+b;
}
int Math::Add(int a, int b, int c) 
{
    return a+b+c;
}
int Math::Add(double a, double b)
{
    return static_cast<int>(a+b);
}
int Math::Add(double a, double b, double c)
{
    return static_cast<int>(a+b+c);
}
int Math::Mul(int a, int b)
{
    return a*b;
}
int Math::Mul(int a, int b, int c)
{
    return a*b*c;
}
int Math::Mul(double a, double b) {
    return static_cast<int>(a*b);
}
int Math::Mul(double a, double b, double c) 
{
    return static_cast<int>(a*b*c);
}

int Math::Add(int count,...)
{
    int sum = 0;

    int* ptr = &count + 1;

    for (int i = 0;i<count;i++) 
    {
        sum+=*ptr;
        ptr++;
    }
    return sum;
}

char* Math::Add(const char* sir1, const char* sir2) 
{
    if (sir1==nullptr || sir2==nullptr)
        return nullptr;
    int len1=strlen(sir1);
    int len2=strlen(sir2);
    char* result = new char[len1+len2+1];
    strcpy(result,sir1);
    strcat(result,sir2);
    return result;
}





