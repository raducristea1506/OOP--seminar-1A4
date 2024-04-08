class Blossom : public Powerpuff
{
public:
	Blossom()
	{
		nume = "Blossom";
		damage = 25;
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

