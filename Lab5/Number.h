#pragma once
class Number
{
	int base10;///nr in baza 10
	int base; ///baza in care este numarul
	char* as_char; ///cifrele numarului
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int nr);//cand nr e deja in baza 10
	Number(const Number& other);//copy constructor
	Number(Number&& other);//move constructor
	~Number();

	Number& operator=(const Number& other);///copy
	Number& operator=(Number&& other);///move
	Number& operator=(const char* value);///n4="13579"
	// +, - folosesc friend
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	friend Number operator+=(Number& n1, Number& n2);
	
	char& operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);
	//decrementare
	Number& operator--();//prefixat
	Number& operator--(int); //postfixat

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
private: 
	static char* Convertire(const char* value, int baza_initiala, int baza_finala);
	static char* IntToChar(int nr);
};
