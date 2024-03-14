
#include <iostream>
#include "Math.h";
using namespace std;
int main()
{
    Math mate;
   cout<<mate.Add(3, 4)<<endl;
   cout<<mate.Add(3, 4, 5)<<endl;
   cout<<mate.Add(3.5, 4.5) <<endl;
   cout<<mate.Add(3.5, 4.5, 5.5) << endl;
   cout<<mate.Mul(3, 4) << endl;
   cout<<mate.Mul(3, 4, 5) << endl;
   cout<<mate.Mul(3.5, 4.5) << endl;
   cout<<mate.Mul(3.5, 4.5, 5.5) << endl;

    /*cout << mate.Add(4, 4, 3, 2, 1) << endl;*/
   
    
}