#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 100000
char t[maxn];
char s[maxn];
using namespace std;
int main(){
	while(scanf("%s%s",s,t)!=EOF){
		int tlen=strlen(t);
		int slen=strlen(s);
		int start=0;
		for(int i=0;i<tlen;i++){
			if(s[start]==t[i]){
				start++;
			}
			if(start==slen){
				printf("Yes\n");
				break;
			}
		}
		if(start!=slen){
			printf("No\n");
		}
	}
} 
