#include <iostream>
#include "Masina.h";
using namespace std;
//Firma
void Masina::SetNameFirma(char* name)
{
    if (this->name == 0)
        this->name = new char[100];

    int sz = strlen(name);
    for (int i = 0; i < sz; i++)
    {
        this->name[i] = name[i];
    }
}
char* Masina::GetNameFirma()
{
    return this->name;
}
//capacitate
bool Masina::Setlitribenzina(float litri)
{
    if (litri < 0 || litri>100)
        return false;
    this->litribenzina = litri;
    return true;
}
float Masina::Getlitribenzina()
{
    return this->litribenzina;
}
//kilometraj
bool Masina::Setkilometraj(float km)
{
    if (km < 0 || km>200000)
        return false;
    this->km = km;
    return true;
}
float Masina::Getkilometraj()
{
    return this->km;
}
//km parcursi
bool Masina::Setkm(float k)
{
    if (k < 0 || k>500)
        return false;
    this->kmparcursi = k;
    this->km = this->km + this->kmparcursi;
    return true;
}
//litri consumati
bool Masina::Setlitriconsumat(float litri)
{
    if (litri > this->litribenzina)
        return false;
    this->lconsum= litri;
    this->litribenzina -= this->lconsum;
    return true;
}
//consum
bool Masina::Setconsum(float litri, float km)
{
    if (litri < 0 || litri>60 || km < 0 || km>500 )
        return false;
    this->lconsum = litri;
    this->kmparcursi = km;
    return true;
}
float Masina::Getconsum()
{
    consum = this->lconsum / this->kmparcursi;

    return consum;
}
//BISNITAR
void Masina::Bisnitar()
{
    if (this->km < 1000) this->km=0;
    this->km= this->km-1000;
}
void Masina::Cursa(float distanta)
{
     this->km=km+distanta;//crste kilometrajul
     //scade numarul de litri
     if (litribenzina - distanta * consum >= 0)
         this->litribenzina = this->litribenzina - distanta * consum;
     else this->litribenzina = 0; //nu are suficienti litrii pentru a parcurge distanta
}





