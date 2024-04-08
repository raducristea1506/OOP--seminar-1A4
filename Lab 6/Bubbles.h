class Bubbles : public Powerpuff
{
public:
	Bubbles()
	{
		nume = "Bubbles";
		damage = 20;
		health = 100;
	}
	const char* Getfetita()
	{
		return this->nume;
	}
	void SetFetita(const char* nume)
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

};
