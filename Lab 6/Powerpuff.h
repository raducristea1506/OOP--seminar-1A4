#pragma once
class Powerpuff
{
public:
    int damage;
    int health;
    const char* nume;
    virtual const char* Getfetita() = 0;
    virtual void SetFetita(const char* nume) = 0;
    virtual int GetHealth() = 0;
    virtual int GetDamage() = 0;

};

