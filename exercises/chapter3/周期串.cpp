#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 85
using namespace std;
int main(){
	int T;
	cin>>T;
	char s[maxn];
	while(T--){
		scanf("%s",s);
		int len=strlen(s);
		for(int k,i=1;i<=len;i++){
			if(len%i==0){
				for(k=i;k<len;k++){
					if(s[k]!=s[k%i]) break;
				}
				if(k==len){
					printf("%d\n",i);
					break;
				}
			}
		}
		if(T) cout<<endl;
	}
} 
