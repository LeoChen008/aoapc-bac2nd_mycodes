#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std;
const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* meg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

char r(char ch){
	if(isalpha(ch))return rev[ch-'A'];
	else return rev[ch-'0'+25];
}
int main(){
	char s[30];
	while(scanf("%s",s)==1){
		int len=strlen(s);
		int f1=1,f2=1;
		for(int i=0;i<(len+1)/2;i++){
			if(s[i]!=s[len-1-i]) f1=0;
			if(r(s[i])!=s[len-1-i]) f2=0;
		}
		printf("%s -- is %s.\n\n",s,meg[f2*2+f1]);
		
	}
} 
