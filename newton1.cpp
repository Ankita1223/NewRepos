#include<iostream>
#include<math.h>
using namespace std;

double f(double a)
{
    return(a*a*a-3*a+1);
}
double d(double a)
{
    return(3*a*a-3);
}

main()
{
	cout<<"Roll Number-161220006";
    double a=0.5,a1=0;
    int p=0,q=1;
    while(p!=q)
    {
        a=a1;
        a1=a-f(a)/d(a);
        p=a*1000000;
        q=a1*1000000;
        cout<<a<<" "<<a1<<endl;
    }

}
