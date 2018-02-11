// To find the Roots of an Algebraic Equation by Newton-Raphson Method

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define EPSILON .00001

float f(float(x))
{
       return (pow(x,3)-(3*x)+1);
}

float g(float(x))
{
       return (3*x*x-3);
}

int main()
{
       float x;
       int i=1;
       cout<<"Given algebric equation is x^3-3^x+1 "<<endl;
       cout<<"Enter the initial guess of the root "<<endl;
       cin>>x;

       if (f(x)==0)
       {
              cout<<"Root of the given equation is "<<x<<endl;
              return 0;
       }
        double h = f(x) / g(x);
    while (abs(h) >EPSILON)
    {
        h = f(x)/g(x);

        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - h;

        cout<<"Iteration No."<<i<<" x="<<x<<"\n";
        i++;
    }

    cout << "The value of the root is : " <<setprecision(4)<<x;
       return 0;
}
