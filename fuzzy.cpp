#include<iostream>

#define inf 32678
using namespace std;

int main(){
float heights[10],min=inf,max=-1;
cout<<"Enter ten heights";
for(int i=0;i<10;i++)
{
cin>>heights[i];
if(heights[i]>=max)
max=heights[i];
if(heights[i]<=min)
min=heights[i];
}

for(int i=0;i<10;i++){
float memb=0.0;
memb=1+((heights[i]-min)/(min-max));
cout<<"Membership for SHORT set for person "<<i+1<<"is:"<<memb<<endl;
cout<<"Membership for VERY SHORT set for person "<<i+1<<"is:"<<memb*memb<<endl;
cout<<"****************************************************************"<<endl;
}}
