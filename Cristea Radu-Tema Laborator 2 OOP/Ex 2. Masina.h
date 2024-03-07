class Masina
{
    char* name=0;
    float litribenzina;
    float consum;
    float km;
    float kmparcursi;
    float lconsum;
    float distanta;
public:
    void SetNameFirma(char* name);
    char* GetNameFirma();
    
    bool Setlitribenzina(float litri);
    bool Setkilometraj(float km);
    bool Setkm(float k);//kilometri parcursi
    bool Setlitriconsumat(float litri);
    bool Setconsum(float litri, float km);
    void Bisnitar();
    void Cursa(float distanta);
    float Getlitribenzina();
    float Getkilometraj();
    float Getkm();
    float Getl();
    float Getconsum();
};
