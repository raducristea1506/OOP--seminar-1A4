#include<iostream>
#include <cstdlib> 
#include <cstring>
#include "Powerpuff.h";
#include "Bubbles.h";
#include "Blossom.h";
#include "Buttercup.h";
#include "MojoJojo.h";
#include "Profesor.h";
using namespace std;
void Bataie(Profesor& profesor, MojoJojo mojo)
{
    profesor.faceFetite();
    int fetiteinitial = profesor.Getnr();
    int nrture = 0;
    while (mojo.GetHealth() > 0 && profesor.Getnr() > 0)
    {
        nrture++;
        int atacfetite = profesor.Damagetotal();
        mojo.atacat(atacfetite);
        int nr = rand() % profesor.Getnr(); ///nr fetitei atacate
        int x = profesor.GetfetitaHealth(nr) - mojo.GetDamage();
        if (x < 0) x = 0;
        profesor.modificDamage(nr, x);///modif health pt fetita atacata
        if (x == 0) ///eliminam fetita
        {
            profesor.Elimfetita(nr);
        }
    }
    cout << "Castigatorul este ";
    if (mojo.GetHealth() == 0) cout << "Profesorul" << "\n";
    else cout << "MojoJojo" << "\n";
    cout << "Bataia a durat " << nrture << " ture" << "\n";
    cout << "Au murit " << fetiteinitial - profesor.Getnr() << " fetite" << "\n";

}
void Statistica(Profesor profesor, MojoJojo mojo)
{
    cout << "Au supravietuit " << profesor.Getnr() << "fetite:" << "\n";
    if (profesor.Getnr() != 0)
    {
        for (int i = 0; i < profesor.Getnr(); i++)
            if (profesor.GetfetitaHealth(i) != 0)
                cout << "Fetita" << i << "cu health" << profesor.GetfetitaHealth(i) << "\n";
    }
}
int main()
{
    const char* ingredienteGlovo[] = { "spice","spice", "sugar", "spice", "spice", "everything_nice", "sugar", "spice", "everything_nice", "everything_nice" };
    Profesor profesor(ingredienteGlovo, 10);
    MojoJojo mojo;
    Bataie(profesor, mojo);
    Statistica(profesor, mojo);
    return 0;
}