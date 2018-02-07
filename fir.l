%{
#include<stdio.h>
#include<string.h>
int i,j,cnt,arr[10],temp;
char str[10];
%}


%%
[0-9] {cnt++;str=yytext();}
%%

int main(int argc,char* argv[1]){
yyin=fopen("num.txt","r");
yylex();
len=strlen(str);
printf("%d",cnt);
}

int yywrap(){
return 1;}
