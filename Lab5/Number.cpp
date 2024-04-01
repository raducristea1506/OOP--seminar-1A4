#include "Number.h"
#include <iostream>
Number::Number(const char* value, int base) //din base in baza 10
{
   
    this->base = base;
    this->base10 = 0;
    int lg = 0;
    while (value[lg] != '\0') lg++;
    this->as_char = new char[lg+1];
    memcpy(this->as_char, value, lg + 1);
    for (int i = 0; i < lg; i++)
        if ('0' <= as_char[i] && as_char[i] <= '9') this->base10 = this->base10 * base + value[i] - '0';//daca e in baza<=10
        else this->base10 = this->base10 * base + value[i] - 'A' + 10;
}
Number::Number(int nr) //cand am un nr care e deja in baza 10
{
    this->base = 10;
    this->base10 = nr;
    int aux = nr;
    int lg = 0;
    while (aux != 0) { lg++; aux /= 10; } 
    this->as_char = new char[lg + 1];
    for (int i = lg - 1; i >= 0; i--)// de la final la capat
    {
        this->as_char[i] = (nr % 10) + '0';///completam vectorul cu cifrele in char
        nr /= 10;
    }
    this->as_char[lg] = '\0';
}

Number::Number(const Number& other) ///constructor de copiere din other in this
{
    this->base = other.base;
    this->base10 = other.base10;
    int lg = 0;
    while (other.as_char[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, other.as_char, lg + 1);
}

Number::Number(Number&& other) //muta si   sterge other
{
    this->base = other.base;
    this->base10 = other.base10;
    other.base = 0;
    other.base10 = 0;
    int lg = 0;
    while (other.as_char[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, other.as_char, lg + 1);
    other.as_char = nullptr;
}

Number::~Number() //destructorul
{
    delete[] this->as_char;
}

Number& Number::operator=(const Number& other) ///de copiere
{
    if (this != &other) 
    {
        delete[] this->as_char;
        this->base = other.base;
        this->base10 = other.base10;
        int lg = 0;
        while (other.as_char[lg] != '\0') lg++;
        this->as_char = new char[lg + 1];
        memcpy(this->as_char, other.as_char, lg + 1);
    }
    return *this;
}

Number& Number::operator=(Number&& other) //de mutare
{
    if (this != &other) 
    {
        delete[] this->as_char;
        this->base = other.base;
        this->base10 = other.base10;
        int lg = 0;
        while (other.as_char[lg] != '\0') lg++;
        this->as_char = new char[lg + 1];
        memcpy(this->as_char, other.as_char, lg + 1);
        other.base = 0;
        other.base10 = 0;
        other.as_char = nullptr;
    }
    return *this;
}

Number& Number::operator=(const char* value) // n4="13579"
{
    
    char* rez = Number::Convertire(value, 10, this->base);
    int lg = 0;
    while (rez[lg] != '\0') lg++;
    delete[] this->as_char;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, rez, lg + 1);
    this->base10 = 0;
    for (int i = 0; value[i] != 0; i++)
        this->base10 = this->base10 * base + value[i] - '0';
    return *this;
}

void Number::Print()
{
    std::cout << "Valoare:" << this->as_char << " " << "Baza:" << this->base << " " << "Reprezentare in baza 10:" << this->base10 << "\n";
}

int Number::GetDigitsCount()
{
    int ct = 0;
    while (this->as_char[ct] != '\0') ct++;
    return ct;
}
int Number::GetBase()
{
    return this->base;
}
Number operator+(const Number& n1, const Number& n2) ///functie friend pt adunare
{
    //vad care e baza mai mare
    int baza = n1.base;
    if (n2.base > baza) baza = n2.base;
    int suma = n1.base10 + n2.base10;//le adun in baza 10
    char* result = Number::IntToChar(suma);//
    result = Number::Convertire(result, 10, baza);//il convertesc inapoi
    Number n(result, baza);
    
    delete[] result;//pt ca l-am creat dinamic, il sterg
    return n;//rezultatul adunarii
}
Number operator+=(Number& n1, Number& n2)
{
    n1.base10 = n1.base10 + n2.base10;
    char* result = Number::IntToChar(n1.base10);
    result = Number::Convertire(result, 10, n1.base);
    int lg = 0;
    while (result[lg] != '\0') lg++;
    delete[] n1.as_char;
    n1.as_char = new char[lg + 1];
    memcpy(n1.as_char, result, lg + 1);
    return n1;
}
Number operator-(const Number& n1, const Number& n2) //firend pt -
{
    
    int baza = n1.base;
    if (n2.base > baza) baza = n2.base;
    int suma = n1.base10 - n2.base10;
    char* result = Number::IntToChar(suma);
    result = Number::Convertire(result, 10, baza);
    Number n(result, baza);
    
    delete[] result;
    return n;
}
char& Number::operator[](int index) //pt n1[tr]
{
    return this->as_char[index];
}
bool Number::operator<(const Number& other)
{
    if (this->base10 < other.base10)  
    {
        return 1;
    }
    return 0; 
}
bool Number::operator>(const Number& other)
{
    if (this->base10 > other.base10)  
    {
        return 1;
    }
    return 0; 
}
bool Number::operator<=(const Number& other)
{
    if (this->base10 <= other.base10) 
    {
        return 1;
    }
    return 0; 
}
bool Number::operator>=(const Number& other)
{
    if (this->base10 >= other.base10)  
    {
        return 1;
    }
    return 0; 
}
bool Number::operator==(const Number& other)
{
    if (this->base10 == other.base10)  
    {
        return 1;
    }
    return 0; 
}
bool Number::operator!=(const Number& other)
{
    if (this->base10 != other.base10)  
    {
        return 1;
    }
    return 0; 
}
Number& Number::operator--()//--prefixat elimin cifra din st
{
    int lg = 0;
    while (this->as_char[lg] != '\0') lg++;
    if (lg == 0) return *this;
    
    for (int i = 0; i < lg; ++i)
        this->as_char[i] = this->as_char[i + 1];
    this->base10 = 0;
    for (int i = 0; i < lg - 1; i++)
        if ('0' <= as_char[i] && as_char[i] <= '9') this->base10 = this->base10 * base + as_char[i] - '0';
        else this->base10 = this->base10 * base + as_char[i] - 'A' + 10;
    return *this;
}
Number& Number::operator--(int)//postfixat--elimin cifra din dr
{
    int  lg = 0;
    while (this->as_char[lg] != '\0') lg++;
    this->as_char[lg - 1] = '\0';
    this->base10 = 0;
    for (int i = 0; i < lg - 1; i++)
        if ('0' <= this->as_char[i] && this->as_char[i] <= '9') this->base10 = this->base10 * base + this->as_char[i] - '0';
        else this->base10 = this->base10 * base + this->as_char[i] - 'A' + 10;
    return *this;
}
void Number::SwitchBase(int newBase)
{
    if (this->base == newBase) return;
    char* nr = Number::Convertire(this->as_char, this->base, newBase);
    this->base = newBase;
    delete[] this->as_char;
    int lg = 0;
    while (nr[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, nr, lg + 1);
    delete[] nr;
}
char* Number::Convertire(const char* value, int baza_initiala, int baza_finala)
{
    
    int lg = 0;
    while (value[lg] != '\0') lg++;
    int rez = 0;
    for (int i = 0; i < lg; ++i) 
    {
        int cif = 0;
        if ('0' <= value[i] && value[i] <= '9') cif = value[i] - '0';
        if ('A' <= value[i] && value[i] <= 'F') cif = value[i] - 'A' + 10;
        rez = rez * baza_initiala + cif;
    }
    
    char* nr_nou = new char[16];
    int i = 0;
    while (rez != 0)
    {
        int cif = rez % baza_finala;
        char ciff;
        if (cif < 10) ciff = cif + '0';
        else ciff = cif + 'A' - 10;
        nr_nou[i++] = ciff;
        rez /= baza_finala;
    }
    if (i == 0) 
        nr_nou[i++] = '0'; 
    nr_nou[i] = '\0'; 
    
    for (int j = 0; j < i / 2; ++j)
    {
        char aux = nr_nou[j];
        nr_nou[j] = nr_nou[i - j - 1];
        nr_nou[i - j - 1] = aux;
    }
    return nr_nou;
}
char* Number::IntToChar(int nr)
{
    int aux = nr, lg = 0;
    while (aux != 0) { lg++; aux /= 10; }
    char* value = new char[lg + 1];
    for (int i = lg - 1; i >= 0; i--)
    {
        value[i] = (nr % 10) + '0';
        nr /= 10;
    }
    value[lg] = '\0';
    return value;
}