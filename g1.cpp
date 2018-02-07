#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
int n,i;
cout<<"Enter lenth of array:\n";
cin>>n;
int a1[n],a2[n],a3[2*n];
cout<<"Enter the even nos\n";
for(i=0;i<n;i++)
{
cin>>a1[i];
}
sort(a1,a1+n);
cout<<"Enter the odd nos\n";
for(i=0;i<n;i++)
{
cin>>a2[i];
}
sort(a2,a2+n);


merge(a1,a1+n,a2,a2+n,a3);
for(i=0;i<2*n;i++)
{
cout<<a3[i]<<"\t";
}
cout<<endl;
return 0;
}




