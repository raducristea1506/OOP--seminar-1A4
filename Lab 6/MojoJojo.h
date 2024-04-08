#include <iostream>
#include <cstdlib> 
#include <cstring>
#include "Powerpuff.h"
#include "Profesor.h"

using namespace std;
class MojoJojo
{
	int damage;
	int health;
	const char* nume;
public:
	MojoJojo()
	{
		nume = "MojoJojo";
		damage = 30;
		health = 100;
	}
	const char* GetMonstru()
	{
		return this->nume;
	}
	void SetMonstru(const char* nume)
	{
		this->nume = nume;
	}
	int GetHealth()
	{
		return this->health;
	}
	int GetDamage()
	{
		return this->damage;
	}
	void atacat(int x)
	{
		if (this->health >= x)
			this->health = this->health - x;
		else this->health = 0;
	}
};


