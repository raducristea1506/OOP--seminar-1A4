# Cristea Radu- OOP--seminar-1A4 26.02.2023
 //problema 2
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


//Problema 4



    2023

Laboratories
Lab-1 (recap)

    Learn how to use GIT

        Install: https://git-scm.com/downloads 

        Documentation: https://git-scm.com/docs/ 

        Learn simple command:

            commit --> https://git-scm.com/docs/git-commit 

            clone --> https://git-scm.com/docs/git-clone 

            push --> https://git-scm.com/docs/git-push 

            pull --> https://git-scm.com/docs/git-pull 

            status --> https://git-scm.com/docs/git-status 

            add --> https://git-scm.com/docs/git-add 

            log --> https://git-scm.com/docs/git-log 

            config --> https://git-scm.com/docs/git-config 

        Each student will create his/hers private GITHUB repository where his/her teaching assistant will be set as a collaborator for that repo. 

        All of the operations from now on (lab exams, lab homework will be done via that repo (or multiple repos) ).

    Write a program in C-Language that open the file "in.txt", and prints the sum of the numbers that are found on each line of the file in.txt. To open the file use fopen API. Write your own function that converts a string to a number (similar cu atoi API). To print something to the screen, use the printf API.

Example: let's consider the following "ini.txt" file:

   			123

   			198698

   			5009

   			983279

The program will print to the screen 1187109.

    Read a sentence from the input using scanf API. Then sort split it into words and write to the screen (using the printf API) the words sorted (from the longest one to the shortest one).If two words have the same length - they will be sorted out alphabetically. We consider that each word is separated from another one using space (one or multiple).

Example: let's consider the following sentence: "I went to the library yesterday". The program will print the following to the screen:

   			yesterday

   			library

   			went

   			the

   			to

   			I

    Lets consider the following code:

#include <iostream>

using namespace std;


bool isPrime(int n)

{

    for (int tr = 2; tr < n / 2; tr++)

        if ((n % tr ) == 0)

            return false;

    return true;

}

int main()

{

    int n;

    std::cout << "Enter a number:";

    std::cin >> n;

    if (isPrime(n))

        std::cout << n << " is prime !";

    else 

        std::cout << n << " is NOT prime !";

    return 0;

}
