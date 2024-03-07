#include<iostream>
#include "Masina.h";
using namespace std;
int main()
{
	char porsche[] = "Porsche";
	Masina sally;
	sally.SetNameFirma(porsche);
	sally.Setkilometraj(20000);
	cout << "initial, kilometrajul e=" << sally.Getkilometraj() <<endl;
	sally.Setlitribenzina(100); //capacitate
	cout << "initial, numarul de litrii de benzina  e=" << sally.Getlitribenzina() << endl;
	sally.Setkm(60);//km parcursi ---->20060 
	sally.Setlitriconsumat(5);//litrii consumati
	sally.Setconsum(5,60);
	cout<<"consum="<<sally.Getconsum()<<endl;
	sally.Bisnitar();// ->>>kilometraj=19060
	sally.Cursa(120);//+140 kilometraj => kilometrajul va fi 19200 si litri=100-5-120*1/12=85
		cout << sally.Getkilometraj() << endl;
		cout << sally.Getlitribenzina() << endl;
	

}