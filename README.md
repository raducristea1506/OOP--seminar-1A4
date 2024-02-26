# OOP--seminar-1A4

#include <iostream>
#include <cstring>

using namespace std;

int conv(char s[1024])
{
    int nr = 0;
    for (int i = 0; i < strlen(s) && s[i]>='0' && s[i] <= '9';i++)
    {
    nr = nr * 10 + (s[i] - '0');
  }
    return nr;
}
int main() 
{
    int s = 0;
    char line[1024];
    FILE* fp; fopen_s(&fp,"Source.txt", "r");
    //Checks if file is empty
    if (fp == NULL)
    {
        return 0;
    }
    while (fgets(line, 1024, fp))
    {
        s+=conv(line);
    }
    printf("%d", s);
}
   /* while (fgets(in.txt, 1024, fp))
    {
        printf("%s\n", in.txt);
    }
    
    return 0;
}
*/
