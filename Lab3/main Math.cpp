
#include <iostream>
#include "Math.h"
using namespace std;
int main()
{
    Math mat;
    cout << mat.Add(3, 4) << endl;
    cout << mat.Add(3, 4, 5) << endl;
    cout << mat.Add(3.5, 4.5) << endl;
    cout << mat.Add(3.5, 4.5, 5.5) << endl;
    cout << mat.Mul(3, 4) << endl;
    cout << mat.Mul(3, 4, 5) << endl;
    cout <<mat.Mul(3.5, 4.5) << endl;
    cout <<mat.Mul(3.5, 4.5, 5.5) << endl;
    cout <<mat.Add(4, 4, 3, 2, 1) << endl;
    cout << mat.Add("12","4") << endl;

}