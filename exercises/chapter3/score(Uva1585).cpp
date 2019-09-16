#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 85
using namespace std;
int main(){
	int T;
	cin>>T;
	char s[maxn];
	while(T--){
		scanf("%s",s);
		int sum=0;
		int point=0;
		int n=strlen(s);
		for(int i=0;i<n;i++){
			if(s[i]=='O'){
				++point;
				sum+=point;
			}
			else{
				point=0;
			}
		}
		printf("%d\n",sum);
	}
}
