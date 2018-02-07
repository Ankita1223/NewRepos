%{
#include<stdio.h>
int a[20],i,j,n,num,temp;
%}
%%
[0-9]+ {num=0;
for(i=0;i<yyleng;i++)
num=num*10+(yytext[j]-'0');
a[n++]=num;
j++;
}
.;

%%
int main()
{
yyin=fopen("num.txt","r");
yylex();
for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}


int yywrap()
{return 1;
}

