#include <ctime>
#include<iostream>
#include <cstdlib> 
#include <cstring>
#include "Powerpuff.h";

class Profesor
{
    const char** ingredienteGlovo;
    int nrfetite;
    int nringrediente;
    int nr1, nr2, nr3;
    Powerpuff** fetite;
public:
    //constructor
    Profesor(const char** ingrediente, int nr) : nringrediente(nr)
    {
        ingredienteGlovo = new const char* [nringrediente];
        for (int i = 0; i < nringrediente; i++)
        {
            ingredienteGlovo[i] = ingrediente[i];
        }
    }

    // destructor cu care eliberez memoria alocata dinamic
    ~Profesor()
    {
        delete[] ingredienteGlovo;
    }

    //
    bool compara(const char* s1, const char* s2)
    {
        while (*s1 && *s2)
        {
            if (*s1 != *s2)
                return false;
            s1++;
            s2++;
        }
        return *s1 == *s2;
    }
    void AddGirl(Powerpuff* fetita, int poz)
    {
        fetite[poz] = fetita;
    }

    //creaza fetite
    void faceFetite()
    {
        int nr1 = 0, nr2 = 0, nr3 = 0;
        for (int i = 0; i < nringrediente; i++)
        {
            if (compara(ingredienteGlovo[i], "sugar"))
            {
                nr1++;
            }
            else if (compara(ingredienteGlovo[i], "spice"))
            {
                nr2++;
            }
            else if (compara(ingredienteGlovo[i], "everything_nice"))
            {
                nr3++;
            }
        }
        if (nr1 < nr2) nrfetite = nr1;
        else nrfetite = nr2;
        if (nr3 < nrfetite) nrfetite = nr3;
        fetite = new Powerpuff * [nrfetite];//aloca memorie
        for (int i = 0; i < nrfetite; ++i)
            fetite[i] = nullptr;
        // fetitele

        int fe;
        for (int i = 0; i < nrfetite; i++)
        {
            fe=i%3;
            if (fe==0) AddGirl(new Buttercup(), i);
            else if (fe==1) AddGirl(new Bubbles(), i);
            else AddGirl(new Blossom(),i);
        }
    }
    const int Getnr()
    {
        return this->nrfetite;
    }
    int GetfetitaDamage(int poz)
    {
        return fetite[poz]->GetDamage();
    }
    int GetfetitaHealth(int poz)
    {
        return fetite[poz]->GetHealth();
    }
    void modificDamage(int poz, int x)
    {
        fetite[poz]->damage = x;
    }
    void modificHealth(int poz, int x)
    {
        fetite[poz]->health = x;
    }
    int Damagetotal()
    {
        int s = 0;
        int nr = this->Getnr();
        for (int i = 0; i < nr; i++)
        {
            s += this->GetfetitaDamage(i);
        }
        return s;
    }
    void Elimfetita(int poz)
    {
        swap(fetite[poz], fetite[this->nrfetite - 1]);
        this->nrfetite--;
    }
};
