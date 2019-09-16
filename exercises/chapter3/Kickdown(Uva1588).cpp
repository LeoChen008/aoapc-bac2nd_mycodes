#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 105
using namespace std;
char top[maxn];
char bottom[maxn];
int main(){
	while(cin>>top>>bottom){
		int tlen=strlen(top);
		int blen=strlen(bottom);
		int i,j,t,b;
		for(i=0;i<blen;i++){
			bool flag=true;
			for(j=0;j<tlen&&i+j<blen;j++){
				if(top[j]=='2'&&bottom[i+j]=='2'){
					flag=false;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		t=max(i+tlen,blen);
		
		for(i=0;i<tlen;i++){
			bool flag=true;
			for(j=0;j<blen&&i+j<tlen;j++){
				if(top[i+j]=='2'&&bottom[j]=='2'){
					flag=false;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		b=max(i+blen,tlen);
		printf("%d\n",min(t,b));
		
	}
}
